cmake_minimum_required(VERSION 2.8.3)
project(helloworld_cpp)

find_package(catkin REQUIRED COMPONENTS roscpp)

catkin_package()

include_directories(${catkin_INCLUDE_DIRS})

add_executable(helloworld_node src/helloworld.cpp)
target_link_libraries(helloworld_node ${catkin_LIBRARIES})
