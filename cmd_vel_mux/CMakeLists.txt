cmake_minimum_required(VERSION 3.0.2)
project(cmd_vel_mux)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  geometry_msgs
)

catkin_package(
  #INCLUDE_DIRS include
  #LIBRARIES cmd_vel_mux
  CATKIN_DEPENDS geometry_msgs roscpp geometry_msgs
  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(cmd_vel_mux_node src/cmd_vel_mux.cpp)
target_link_libraries(cmd_vel_mux_node ${catkin_LIBRARIES})
