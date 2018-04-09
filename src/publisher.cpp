#include "ros/ros.h"
#include "std_msgs/String.h"
#include "ROS_Homework_1/Num.h"
#include <sstream>

int main(int argc, char **argv)
{
  

  ros::init(argc, argv, "publisher");

  ros::NodeHandle n;

  ros::Publisher publisher_pub = n.advertise<ROS_Homework_1::Num>("complete", 1000);

  ros::Rate loop_rate(1); // 1 message per second

  int count = 0;
  

  
  while (ros::ok())
  {

   
   ROS_Homework_1::Num msg;
   msg.nome = "Cristian Sandu";
   msg.eta = "29";
   msg.corso_di_laurea = "Laurea in Informatica";
  
 //std::cout << "Nome: " << msg.nome << ".\n" <<"Eta: " << msg.eta <<".\n"<< "Corso di laurea: " << msg.corso_di_laurea << ".\n";

    publisher_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();

    ++count;
  }


  return 0;
}

