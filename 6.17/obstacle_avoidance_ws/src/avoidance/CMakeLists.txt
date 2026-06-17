cmake_minimum_required(VERSION 3.0.2)
project(avoidance)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  sensor_msgs
)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(avoidance_node src/avoidance.cpp)
add_dependencies(avoidance_node ${catkin_EXPORTED_TARGETS})

target_link_libraries(avoidance_node
  ${catkin_LIBRARIES}
)

install(TARGETS avoidance_node
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(DIRECTORY launch
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
  PATTERN "*.launch"
)
