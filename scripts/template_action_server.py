#!/usr/bin/env python

import rospy
import actionlib
# Change server_template by the name of your ROS package
# and actionName by the name of your action file (without the .action)
from server_template.msg import actionNameAction, actionNameResult, actionNameFeedback

# You can add here any other import statement you might need for your code


# You can define here as many functions as you want

# Class containing the action server (you can change the name, but don't forget to also change it line 72)
class MyActionServer(object):

    """
        Class running the action server to execute your code
    """

    def __init__(self, action_server_name):
        """
            Initialize the action server
        """
        # Change actionName by the name of your action file
        self.action_server = actionlib.SimpleActionServer(action_server_name, actionNameAction, auto_start=False)
        # Set the callback to be executed when a goal is received
        self.action_server.register_goal_callback(self.goal_callback)
        # Set the callback that should be executed when a preempt request is received
        self.action_server.register_preempt_callback(self.preempt_callback)
        # Start the server
        self.action_server.start()

    def goal_callback(self):
        """
            Callback executed when a goal is received. Your code should be called or written inside this method
        """
        # The first step is to accept a new goal.
        new_goal = self.action_server.accept_new_goal()
        # If you want to access to the input field, you should write
        input_values = new_goal.input
        # The core of your code should be called or written here
        # ...

        # You can fill and send a feedback message with the following block. Don't forget to change field_name and value
        action_feedback = actionNameFeedback()
        action_feedback.field_name = value
        # Publish the feedback
        self.action_server.publish_feedback(action_feedback)

        # Return the response of the action. Don't forget to change the values
        self.action_result = actionNameResult()
        self.action_result.outcome = value
        self.action_result.returned_object = object
        self.action_server.set_succeeded(self.action_result)

    def preempt_callback(self):
        """
            Callback executed when a preempt request has been received.
        """
        # You can add some code here if you need to perform some specific operations when a preemption request is sent
        self.action_server.set_preempted()

    # You can add here other methods to the class if you want to


if __name__ == '__main__':
    # Initialise the node with a specific name (please change it to match your action)
    rospy.init_node('template_python_action_server')
    # Create an instance of the class running the action server. The argument of the class determines the name of the
    # action. Make sure to change it to match your code.
    action_server = MyActionServer("template_action")
    rospy.spin()
