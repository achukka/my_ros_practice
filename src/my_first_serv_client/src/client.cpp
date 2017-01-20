// CLIENT NODE

#include "ros/ros.h"  								// ROS header files
#include "my_first_serv_client/addTwoIntegers.h"		// Header for adding two integers

int main(int argc, char **argv){

	ros::init(argc, argv, "add_two_integers_client"); // Initialize ROS

	if(argc!=3){
		ROS_ERROR("usage: add_two_integers_client X Y");
		return 1;
	}

	ros::NodeHandle n; // Handler to process the node

	// Tell the handler that we will create a client that calls the service later
	ros::ServiceClient client = n.serviceClient<my_first_serv_client::addTwoIntegers>("add_two_integers");  

	my_first_serv_client::addTwoIntegers srv; // Service object and play with it
	srv.request.a = atoll(argv[1]);
	srv.request.b = atoll(argv[2]);

	if(client.call(srv))
	{
		ROS_INFO("Sum: %ld", (long int)srv.response.sum);
	}
	else
	{
		ROS_ERROR("Failed to call service add_two_integers");
		return 1;
	}
	return 0;
}