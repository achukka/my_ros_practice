cmake_minimum_required(VERSION 2.8.3)
project(my_pluginlib)

find_package(catkin REQUIRED COMPONENTS
  pluginlib
  roscpp
)

include_directories(
  ${catkin_INCLUDE_DIRS}
  /home/kuroku/repos/catkin_ws/src/my_pluginlib/include
)

## Declare a C++ library
add_library(my_pluginlib src/polygon_plugins.cpp)
target_link_libraries(my_pluginlib ${catkin_LIBRARIES})

## Declare a C++ executable
add_executable(polygon_loader src/polygon_loader.cpp)

## Specify libraries to link a library or executable target against
target_link_libraries(polygon_loader ${catkin_LIBRARIES})