#include "ros/ros.h"
#include "std_msgs/String.h"
#include "ROS_Homework_1/Num.h"
#include <sstream>
#include <string>



int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "sender");
  
  ros::NodeHandle n;
  
  ros::Publisher sender_pub = n.advertise<ROS_Homework_1::Num>("dati", 1000);
  

// 1 message per second
  ros::Rate loop_rate(1); 


  while (ros::ok())
  {
    
    // Messaggio da inviare
    ROS_Homework_1::Num msg;
    msg.nome = "Cristian Sandu";
    msg.eta = "29";
    msg.corso_di_laurea = "Laurea in Informatica";

    //publica il messaggio
    sender_pub.publish(msg);

//std::cout << "Nome: " << msg.nome << ".\n" <<"Eta: " << msg.eta <<".\n"<< "Corso di laurea: " << msg.corso_di_laurea << ".\n";

    ros::spinOnce();
      
    loop_rate.sleep();

  }
  
  
  return 0;
}

