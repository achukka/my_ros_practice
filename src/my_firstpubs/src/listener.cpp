// SUBSCRIBER NODE


#include "ros/ros.h"  				// ROS header files
#include "std_msgs/String.h"		// String messages

#include <sstream>

/* 
	Basic Outline
	1. Initialize the ROS System
	2. Subscribe to "myChatter"
	3. Spin, waiting for the message to arrive
	4. Call myChatter Callback function when a message arrives
*/

// Is called when a message is received
void myChatterCallback(const std_msgs::String::ConstPtr &msg){
	ROS_INFO("I listened to :[%s]", msg->data.c_str());
}

int main(int argc, char **argv){

	ros::init(argc, argv, "myListener"); // Initialize ROS

	ros::NodeHandle n; // Handler to process the node

	// Tell the handler that we will advertise messages of type "std_msgs::String"
	ros::Subscriber chatter_sub = n.subscribe("myChatter", 1000, myChatterCallback); 

	// Regulate Call backs
	ros::spin();

	return 0;
}