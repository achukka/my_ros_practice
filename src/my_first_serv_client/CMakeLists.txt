cmake_minimum_required(VERSION 2.8.3)
project(my_first_serv_client)

## Find catkin and other packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
)

## Declare ROS Messages and services
add_service_files(DIRECTORY srv FILES addTwoIntegers.srv)

## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs)

## Declare a catkin package
catkin_package(
	CATKIN_DEPENDS message_runtime
		)

## Build Talker and Listener
include_directories(
  ${catkin_INCLUDE_DIRS}
)

## Talker executable
add_executable(add_two_integers_server src/server.cpp)
target_link_libraries(add_two_integers_server ${catkin_LIBRARIES})
add_dependencies(add_two_integers_server my_first_serv_client_generate_messages_cpp)

## Listener executable
add_executable(add_two_integers_client src/client.cpp)
target_link_libraries(add_two_integers_client ${catkin_LIBRARIES})
add_dependencies(add_two_integers_client my_first_serv_client_generate_messages_cpp)