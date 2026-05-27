cmake_minimum_required(VERSION 3.0.2)
project(turtlecpp)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  turtlesim
)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(circle_motion_node src/circle_motion.cpp)
add_dependencies(circle_motion_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(circle_motion_node
  ${catkin_LIBRARIES}
)