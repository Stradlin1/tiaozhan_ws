#include <ros/ros.h>
#include <iostream>

int main(int argc, char **argv)
{
    // 初始化ROS节点
    ros::init(argc, argv, "helloworld_node");
    ros::NodeHandle nh;
    
    // 设置循环频率
    ros::Rate loop_rate(1);  // 1Hz
    
    int count = 0;
    while (ros::ok())
    {
        count++;
        ROS_INFO("Hello World! Count: %d", count);
        std::cout << "Hello World from C++! Count: " << count << std::endl;
        
        loop_rate.sleep();
        
        // 只打印5次后退出
        if (count >= 5)
            break;
    }
    
    ROS_INFO("C++ HelloWorld Node finished");
    return 0;
}
