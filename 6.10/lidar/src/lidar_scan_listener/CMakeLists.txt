cmake_minimum_required(VERSION 3.0.2)
project(lidar_scan_listener)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  sensor_msgs
)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(lidar_scan_listener_node src/lidar_scan_listener.cpp)

target_link_libraries(lidar_scan_listener_node
  ${catkin_LIBRARIES}
)
