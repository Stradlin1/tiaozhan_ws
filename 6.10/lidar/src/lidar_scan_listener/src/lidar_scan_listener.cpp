#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>

void scanCallback(const sensor_msgs::LaserScan::ConstPtr &scan) {
    int num_points = static_cast<int>((scan->angle_max - scan->angle_min) / scan->angle_increment);
    ROS_INFO_STREAM("Number of points: " << num_points);

    if (scan->ranges.empty() || num_points <= 0) {
        ROS_WARN("Received an empty or invalid LaserScan message.");
        return;
    }

    float first_range = scan->ranges.front();
    ROS_INFO_STREAM("First range: " << first_range);

    float last_range = scan->ranges[num_points - 1];
    ROS_INFO_STREAM("Last range: " << last_range);

    float half_range = scan->ranges[num_points / 2];
    ROS_INFO_STREAM("Half range: " << half_range);

    float left_range = scan->ranges[num_points / 4];
    ROS_INFO_STREAM("Left range: " << left_range);

    float right_range = scan->ranges[num_points / 4 * 3];
    ROS_INFO_STREAM("Right range: " << right_range);
}

int main(int argc, char *argv[]) {
    ros::init(argc, argv, "lidar_scan_listener");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("/scan", 1000, scanCallback);
    ros::spin();
    return 0;
}
