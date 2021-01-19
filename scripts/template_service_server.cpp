#include <ros/ros.h>
/**
Please uncomment this out and change server_template by the name of your ROS package
and srvName by the name of your srv file (without the .srv)
*/
// #include <server_template/srvName.h>

// You can add here any other include statement you might need for your code


// You can define here as many functions as you want

// Function that is going to be linked to the service server
// This function (feel free to change its name) must contain your code.
// It MUST have two paramters, one for the request the srv, and the other one for the response.
// You can call other functions inside it without any problem
bool my_function(server_template::srvName::Request &request, server_template::srvName::Response &response)
{
  // Access to the msg stored in request (assuming it is a vector of float)
  // std::vector<float> input_values = request.input;
  // The core of your code should be called or written here
  // ...

  // The outcome field is mandatory and must contain an integer (0, 1, 2, ...) that describes how your code behaved.
  /**
  For instance, if your code can have two outcomes (let's say, no solution found and solution found), you can
  set the outcome field to 0 when you find a solution and 1 when you don't.
  */
  // response.outcome = integer;
  /**
  The returned_object field is also mandatory. It allows you to return an object of your choice, which type depends
  on your srv definition. If you don't want to return anything, you can set it to an empty list
  */
  // std::vector<float> empty_vector;
  // response.returned_object = empty_vector;

  // Return true to avoid having runtime errors on the client side
  return true;
}

int main(int argc, char **argv)
{
  // Initialise the node with a specific name (please change it to match your service)
  ros::init(argc, argv, "template_cpp_service_server");
  // Create a node handler
  ros::NodeHandle node_handle;
  /**
  Set the name of the service and what function will be run and received
  Please uncomment this out, change the name of the server with one that matches the content of your code,
  and the last one should be the function that runs your code.
  */
  // ros::ServiceServer service = node_handle.advertiseService("template_service", my_function);
  ros::spin();

  return 0;
}
