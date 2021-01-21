#ifndef SERVER_TEMPLATE_ACTION_H
#define SERVER_TEMPLATE_ACTION_H

#include <ros/ros.h>
#include <string>
#include <actionlib/server/simple_action_server.h>
/**
Please change server_template by the name of your ROS package
and actionName by the name of your action file (without the action)
*/
#include <server_template/actionNameAction.h>
#include <server_template/actionNameFeedback.h>
#include <server_template/actionNameResult.h>
#include <server_template/actionNameGoal.h>

// You can add here any other import statement you might need for your code


/**
Class containing the action server (you can change the name, but don't forget to also change it everywhere)
 */
class MyActionServer
{
  public:
    // Constructor
    MyActionServer(ros::NodeHandle* node_handler, std::string action_server_name);

  private:
    // Change actionName by the name of your ROS package and action file
    actionlib::SimpleActionServer<server_template::actionNameAction> action_server_;
    // Declare and initialise the message containing the outcome of the action
    server_template::actionNameResult action_result_;
    // Declare and initialise a actionNameFeedback containing the feedback to send during the execution
    server_template::actionNameFeedback action_feedback_;
    // Declare and initialise an actionNameGoal containing the goal sent to the server
    server_template::actionNameGoalConstPtr new_goal_;
    // Declare and initialise a boolean storing the state of the server
    bool busy_ = false;

    // Internal method executing all the steps required when receiving a new goal or preempting an action
    void goal_callback();
    void preempt_callback();
};

#endif  // SERVER_TEMPLATE_ACTION_H
