#include "ros/ros.h"
#include "std_msgs/String.h"


void partialCallBack(const std_msgs::String::ConstPtr& msg)
{
 // ROS_INFO("%s", msg->data.c_str());
  std::cout << msg->data.c_str() << std::endl; 
}


int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "viewer");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("partial", 1000, partialCallBack);

  ros::spin();

  return 0;
}

