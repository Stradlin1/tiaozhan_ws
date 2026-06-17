#include <algorithm>
#include <cmath>
#include <string>

#include <geometry_msgs/Twist.h>
#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>

namespace
{
ros::Publisher g_cmd_pub;

// --- 修改后的距离参数 ---
double g_safe_distance = 0.5;    // 从 0.8 改为 0.5
double g_danger_distance = 0.25; // 按比例缩小 (0.5 * 0.5)
double g_rear_danger_distance = 0.3; // 后方危险距离阈值

double g_front_half_angle_deg = 30.0;
double g_side_half_angle_deg = 60.0;
double g_rear_half_angle_deg = 30.0; // 后方检测半角

double g_forward_speed = 0.15;
double g_turn_speed = 0.5;
double g_back_speed = -0.1;

double deg2rad(double deg)
{
  return deg * M_PI / 180.0;
}

double minDistanceInSector(const sensor_msgs::LaserScan::ConstPtr &scan, double start_angle, double end_angle)
{
  if (scan->ranges.empty() || scan->angle_increment <= 0.0) {
    return scan->range_max;
  }

  const double clamped_start = std::max(start_angle, static_cast<double>(scan->angle_min));
  const double clamped_end = std::min(end_angle, static_cast<double>(scan->angle_max));
  if (clamped_start > clamped_end) {
    return scan->range_max;
  }

  int start_index = static_cast<int>((clamped_start - scan->angle_min) / scan->angle_increment);
  int end_index = static_cast<int>((clamped_end - scan->angle_min) / scan->angle_increment);

  start_index = std::max(0, start_index);
  end_index = std::min(static_cast<int>(scan->ranges.size()) - 1, end_index);

  double min_range = scan->range_max;
  for (int i = start_index; i <= end_index; ++i) {
    const float range = scan->ranges[i];
    if (std::isfinite(range) && range >= scan->range_min && range <= scan->range_max) {
      min_range = std::min(min_range, static_cast<double>(range));
    }
  }

  return min_range;
}

void scanCallback(const sensor_msgs::LaserScan::ConstPtr &scan)
{
  const double front_half_angle = deg2rad(g_front_half_angle_deg);
  const double side_half_angle = deg2rad(g_side_half_angle_deg);
  const double rear_half_angle = deg2rad(g_rear_half_angle_deg);

  // 前方距离
  const double dist_front = minDistanceInSector(scan, -front_half_angle, front_half_angle);
  // 左侧距离
  const double dist_left = minDistanceInSector(scan, front_half_angle, side_half_angle);
  // 右侧距离
  const double dist_right = minDistanceInSector(scan, -side_half_angle, -front_half_angle);
  
  // --- 新增：后方距离检测 ---
  // 激光雷达范围通常是 [-PI, PI]，后方在 PI 附近。
  // 需检测 [PI - half, PI] 和 [-PI, -PI + half] 两个区域
  double dist_rear_right = minDistanceInSector(scan, M_PI - rear_half_angle, M_PI);
  double dist_rear_left = minDistanceInSector(scan, -M_PI, -M_PI + rear_half_angle);
  const double dist_rear = std::min(dist_rear_right, dist_rear_left);

  geometry_msgs::Twist cmd;

  if (dist_front > g_safe_distance) {
    // 状态 1：前方安全 -> 直行
    cmd.linear.x = g_forward_speed;
    cmd.angular.z = 0.0;
    ROS_INFO_THROTTLE(1.0, "avoidance: clear path, forward (front=%.2f)", dist_front);
  } 
  else if (dist_front > g_danger_distance) {
    // 状态 2：前方出现障碍物 -> 减速转向
    cmd.linear.x = 0.05; 
    cmd.angular.z = (dist_left >= dist_right) ? g_turn_speed : -g_turn_speed;
    ROS_INFO_THROTTLE(1.0, "avoidance: turning away (front=%.2f left=%.2f right=%.2f)", dist_front, dist_left, dist_right);
  } 
  else {
    // 状态 3：前方极其危险 -> 尝试后退并转向
    // --- 新增后方检测逻辑 ---
    if (dist_rear > g_rear_danger_distance) {
      cmd.linear.x = g_back_speed; // 后方安全，可以后退
      ROS_WARN_THROTTLE(1.0, "avoidance: emergency retreat (front=%.2f rear=%.2f)", dist_front, dist_rear);
    } else {
      cmd.linear.x = 0.0; // 后方也不安全，停止后退，改为原地旋转
      ROS_WARN_THROTTLE(1.0, "avoidance: stuck! rear blocked (front=%.2f rear=%.2f)", dist_front, dist_rear);
    }
    cmd.angular.z = (dist_left >= dist_right) ? g_turn_speed : -g_turn_speed;
  }

  g_cmd_pub.publish(cmd);
}
}  // namespace

int main(int argc, char **argv)
{
  ros::init(argc, argv, "avoidance");
  ros::NodeHandle nh;
  ros::NodeHandle pnh("~");

  std::string scan_topic = "/scan";
  std::string cmd_topic = "/cmd_vel";

  pnh.param("scan_topic", scan_topic, scan_topic);
  pnh.param("cmd_topic", cmd_topic, cmd_topic);
  pnh.param("safe_distance", g_safe_distance, g_safe_distance);
  pnh.param("danger_distance", g_danger_distance, g_danger_distance);
  pnh.param("rear_danger_distance", g_rear_danger_distance, g_rear_danger_distance);
  pnh.param("front_half_angle_deg", g_front_half_angle_deg, g_front_half_angle_deg);
  pnh.param("side_half_angle_deg", g_side_half_angle_deg, g_side_half_angle_deg);
  pnh.param("rear_half_angle_deg", g_rear_half_angle_deg, g_rear_half_angle_deg);
  pnh.param("forward_speed", g_forward_speed, g_forward_speed);
  pnh.param("turn_speed", g_turn_speed, g_turn_speed);
  pnh.param("back_speed", g_back_speed, g_back_speed);

  g_cmd_pub = nh.advertise<geometry_msgs::Twist>(cmd_topic, 1);
  ros::Subscriber scan_sub = nh.subscribe(scan_topic, 1, scanCallback);

  ROS_INFO("avoidance node started. scan_topic=%s cmd_topic=%s", scan_topic.c_str(), cmd_topic.c_str());

  ros::spin();
  return 0;
}
