// SERVER NODE

#include "ros/ros.h"  							// ROS header files
#include "my_first_serv_client/addTwoIntegers.h"		   // Header for adding two integers

// Takes the request, adds the numbers and sets it response
bool add(my_first_serv_client::addTwoIntegers::Request &req,
		my_first_serv_client::addTwoIntegers::Response &res)
{
	res.sum = req.a + req.b;
	ROS_INFO("Request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
	ROS_INFO("Sending back response: [%ld]", (long int)res.sum);
	return true;
}

int main(int argc, char **argv){

	ros::init(argc, argv, "add_two_integers_server"); // Initialize ROS

	ros::NodeHandle n; // Handler to process the node

	// Tell the handler that we will advertise Services and calls the CallBack
	ros::ServiceServer service = n.advertiseService("add_two_integers", add);  

	/// Ready to add integers
	ROS_INFO("Ready to add two integers");

	// Regulate Call backs
	ros::spin();
	return 0;
}