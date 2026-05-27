#include <geometry_msgs/Twist.h>
#include <ros/ros.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "circle_motion_controller");
  ros::NodeHandle nh;
  ros::NodeHandle private_nh("~");

  double linear_speed = 2.0;
  double angular_speed = 2.0;
  double publish_rate_hz = 10.0;

  private_nh.param("linear_speed", linear_speed, linear_speed);
  private_nh.param("angular_speed", angular_speed, angular_speed);
  private_nh.param("publish_rate", publish_rate_hz, publish_rate_hz);

  if (angular_speed == 0.0) {
    ROS_ERROR("angular_speed must be non-zero to generate circular motion");
    return 1;
  }

  ros::Publisher cmd_vel_pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);
  ros::Rate rate(publish_rate_hz);

  ROS_INFO("Publishing circular velocity to /turtle1/cmd_vel: linear=%.3f angular=%.3f", linear_speed, angular_speed);

  while (ros::ok()) {
    geometry_msgs::Twist twist_msg;
    twist_msg.linear.x = linear_speed;
    twist_msg.angular.z = angular_speed;

    cmd_vel_pub.publish(twist_msg);
    ros::spinOnce();
    rate.sleep();
  }

  return 0;
}