cmake_minimum_required(VERSION 2.8.3)
project(my_firstpubs)

## Find catkin and other packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
)

## Declare ROS Messages and services
add_message_files(DIRECTORY msg FILES Num.msg)

## Generate added messages and services
## generate_messages(DEPENDENCIES std_msgs)

## Declare a catkin package
catkin_package(CATKIN_DEPENDS message_runtime)

## Build Talker and Listener
include_directories(
  ${catkin_INCLUDE_DIRS}
)

## Talker executable
add_executable(myTalker src/talker.cpp)
target_link_libraries(myTalker ${catkin_LIBRARIES})
add_dependencies(myTalker my_firstpubs_generate_messages_cpp)

## Listener executable
add_executable(myListener src/listener.cpp)
target_link_libraries(myListener ${catkin_LIBRARIES})
add_dependencies(myListener my_firstpubs_generate_messages_cpp)
