cmake_minimum_required(VERSION 2.8.3)
project(helloworld_py)

find_package(catkin REQUIRED COMPONENTS rospy)

catkin_package()

# 标记脚本文件为可执行
catkin_install_python(PROGRAMS scripts/helloworld.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
