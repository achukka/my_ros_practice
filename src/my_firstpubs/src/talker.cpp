// PUBLISHER NODE

#include "ros/ros.h"  				// ROS header files
#include "std_msgs/String.h"		// String messages

#include <sstream>

/* 
	Basic Outline
	1. Initialize the ROS System
	2. Advertise that we will publish "std_msgs::String" messages on "myChatter" topic to the master
	3. Loop while publishing message to "myChatter" 10 times a second
*/
int main(int argc, char **argv){

	ros::init(argc, argv, "myTalker"); // Initialize ROS

	ros::NodeHandle n; // Handler to process the node

	// Tell the handler that we will advertise messages of type "std_msgs::String"
	ros::Publisher chatter_pub = n.advertise<std_msgs::String>("myChatter", 1000); 

	// Frequency of loop
	ros::Rate loop_rate(10);

	int count = 0; // Number of messages we have sent, used to create a unique string for each message

	while(ros::ok()){
		// Create a message object, stuff it with data and publish it
		std_msgs::String msg;

		std::stringstream ss; // String stream to convert int to string

		ss <<" This is message number:"<< count<<" from myTalker";
		msg.data = ss.str();

		/// print it to terminal
		ROS_INFO("%s", msg.data.c_str()); // data is stored as an character array

		/* Now publish the messsage using your publisher */
		chatter_pub.publish(msg);

		// Regulate Call backs
		ros::spinOnce();

		// Sleep until we hit 10Hz publish rate
		loop_rate.sleep();

		++ count; // Increment message count
	}
	return 0;
}