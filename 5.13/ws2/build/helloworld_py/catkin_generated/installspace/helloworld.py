#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import rospy

def main():
    # 初始化ROS节点
    rospy.init_node('helloworld_node', anonymous=True)
    
    # 设置循环频率
    rate = rospy.Rate(1)  # 1Hz
    
    count = 0
    while not rospy.is_shutdown():
        count += 1
        rospy.loginfo("Hello World! Count: %d" % count)
        print("Hello World from Python! Count: " + str(count))
        
        rate.sleep()
        
        # 只打印5次后退出
        if count >= 5:
            break
    
    rospy.loginfo("Python HelloWorld Node finished")

if __name__ == '__main__':
    try:
        main()
    except rospy.ROSInterruptException:
        pass
