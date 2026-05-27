#include <ros/ros.h>
#include <std_msgs/String.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");
  ros::NodeHandle nh;
  ros::Publisher pub = nh.advertise<std_msgs::String>("chatter", 10);
  ros::Rate loop_rate(10); // 10Hz
  while (ros::ok()) {
    std_msgs::String msg;
    msg.data = "你好啊";
    pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}
