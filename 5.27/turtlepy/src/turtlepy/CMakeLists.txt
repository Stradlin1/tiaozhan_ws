cmake_minimum_required(VERSION 3.0.2)
project(turtlepy)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  rospy
  turtlesim
)

catkin_package()

catkin_install_python(PROGRAMS
  scripts/circle_motion.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)