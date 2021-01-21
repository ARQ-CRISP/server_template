// Change server_name byt he name of your package and template_action_server by the name of your hpp file
#include <server_template/template_action_server.hpp>

/**
 Constructor of the class
 * @param nodehandler               reference to a ros NodeHandle object
 * @param action_server_name        name given to the action server
 */
MyActionServer::MyActionServer(ros::NodeHandle* node_handler, std::string action_server_name)
  : action_server_(*node_handler, action_server_name, false)
{
    action_server_.registerGoalCallback(boost::bind(&MyActionServer::goal_callback, this));
    action_server_.registerPreemptCallback(boost::bind(&MyActionServer::preempt_callback, this));
    action_server_.start();
}

/**
  Callback executed when a goal is received. Your code should be called or written inside this method
 */
void MyActionServer::goal_callback()
{
    // If the server is already processing a goal
    if (busy_)
    {
        ROS_ERROR("The action will not be processed because the server is already busy with another action. "
                  "Please preempt the latter or wait before sending a new goal");
        return;
    }
    // The first step is to accept a new goal. If you want to access to the input field, you should write
    // new_goal->input;
    new_goal_ = action_server_.acceptNewGoal();
    // Set busy to true
    busy_ = true;

    // The core of your code should be called or written here
    // ...

    // You can fill and send a feedback message with the following block. Don't forget to change field_name and value
    action_feedback_.field_name = value;
    action_server_.publishFeedback(action_feedback_);

    // Return the response of the action. Don't forget to change the values
    action_result_.outcome = value;
    action_result_.returned_object = object;
    action_server_.setSucceeded(action_result_);
    // Set busy to false
    busy_ = false;
}

void MyActionServer::preempt_callback()
{
    // You can add some code here if you need to perform some specific operations when a preemption request is sent
    action_server_.setPreempted();
}

int main(int argc, char** argv)
{
    // Initialise the node with a specific name (please change it to match your action)
    ros::init(argc, argv, "template_cpp_action_server");
    // Initialise the node handler that will be given to the class' constructor
    ros::NodeHandle node_handler;
    /**
    Create an instance of the class running the action server. The argument of the class determines the name of the
    action. Make sure to change it to match your code.
    */
    MyActionServer my_action_server_(&node_handler, "template_action");
    // Wait for shutdown
    ros::spin();
    return 0;
}
