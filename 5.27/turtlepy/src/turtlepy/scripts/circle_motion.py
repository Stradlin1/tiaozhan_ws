#!/usr/bin/env python3

import rospy
from geometry_msgs.msg import Twist


def main():
    rospy.init_node('circle_motion_controller')

    linear_speed = rospy.get_param('~linear_speed', 2.0)
    angular_speed = rospy.get_param('~angular_speed', 2.0)
    publish_rate_hz = rospy.get_param('~publish_rate', 10.0)

    if angular_speed == 0.0:
        rospy.logerr('angular_speed must be non-zero to generate circular motion')
        return

    publisher = rospy.Publisher('/turtle1/cmd_vel', Twist, queue_size=10)
    rate = rospy.Rate(publish_rate_hz)

    rospy.loginfo(
        'Publishing circular velocity to /turtle1/cmd_vel: linear=%.3f angular=%.3f',
        linear_speed,
        angular_speed,
    )

    while not rospy.is_shutdown():
        twist_msg = Twist()
        twist_msg.linear.x = linear_speed
        twist_msg.angular.z = angular_speed

        publisher.publish(twist_msg)
        rate.sleep()


if __name__ == '__main__':
    main()