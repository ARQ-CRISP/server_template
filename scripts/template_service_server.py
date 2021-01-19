#!/usr/bin/env python

import rospy
# Please uncomment this out and change server_template by the name of your ROS package
# and srvName by the name of your srv file (without the .srv)
# from server_template.srv import srvName, srvNameResponse

# You can add here any other import statement you might need for your code


# You can define here as many functions as you want

# Function that is going to be linked to the service server
def my_function(request):
    """
        This function (feel free to change its name) must contain your code.
        It MUST have a single input argument, that will be the request part of the srv, so DO NOT change it.
        You can call other functions inside it without any problem
    """
    # Remove the pass when you add your code
    pass
    # Access to the msg stored in request
    # input_values = request.input
    # The core of your code should be called or written here
    # ...
    # Make sure to uncomment this out and change srvName by the name of your srv
    # response = srvNameResponse()

    # Fill in the service response.
    # The outcome field is mandatory and must contain an integer (0, 1, 2, ...) that describes how your code behaved.
    # For instance, if your code can have two outcomes (let's say, no solution found and solution found), you can
    # set the outcome field to 0 when you find a solution and 1 when you don't.
    # response.outcome = integer
    # The returned_object field is also mandatory. It allows you to return an object of your choice, which type depends
    # on your srv definition. If you don't want to return anything, you can set it to an empty list
    # response.returned_object = list()

    # Return the response
    # return response

if __name__ == '__main__':
    # Initialise the node with a specific name (please change it to match your service)
    rospy.init_node('template_python_service_server')
    # Set the name of the service, specify which kind of srv will trigger it and what function will be run.
    # Please uncomment this out, change the name of the server with one that matches the content of your code,
    # set the second argument to the name of the srv file, and the last one should be the function that runs your code.
    # service = rospy.Service("template_service", srvName, my_function)
    rospy.spin()
