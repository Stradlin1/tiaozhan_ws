#include "ros/ros.h"
#include "geometry_msgs/Twist.h" 
#include <cmath> // 引入数学库以使用 M_PI

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");

    ros::init(argc,argv,"control");
    ros::NodeHandle nh;

    ros::Duration(2).sleep();

    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 1000);

    // 1. 组织消息
    geometry_msgs::Twist msg;
    msg.linear.x = 0.3;  // 前进速度 (如果只想原地转圈，请改为 0.0)
    msg.linear.y = 0.0;
    msg.linear.z = 0.0;

    msg.angular.x = 0.0;
    msg.angular.y = 0.0;
    msg.angular.z = 2.0; // 旋转速度: 2.0 rad/s
    // 2. 设置发送频率
    ros::Rate r(10); // 频率 10Hz，意味着每次循环间隔 dt = 0.1s
    // 3. 定义旋转目标
    double target_angle = 3 * 2 * M_PI; 
    double current_angle = 0.0;         
    double dt = 0.1;                    
    ROS_INFO("Start rotating for 3 circles...");
    // 4. 循环发送：直到累计角度达到目标角度
    while (ros::ok() && current_angle < target_angle)
    {
        pub.publish(msg);
        
        // 累加角度: 角度 = 速度 * 时间
        current_angle += msg.angular.z * dt;
        
        r.sleep();
        ros::spinOnce();
    }
    // 5. 停止机器人
    geometry_msgs::Twist stop_msg; // 默认全为 0.0
    pub.publish(stop_msg);
    ROS_INFO("Finished 3 circles. Stopped.");
    return 0;    
}