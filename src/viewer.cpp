#include "ros/ros.h"
#include "std_msgs/String.h"
#include "ROS_Homework_1/Num.h"
#include <sstream>
#include <string>



// Dichiaro la mia scelta globale
std::string choice;


//std::cout << "Nome: " << msg.nome << ".\n" <<"Eta: " << msg.eta <<".\n"<< "Corso di laurea: " << msg.corso_di_laurea << ".\n";

/*
* A seconda della scelta viene selezionata una parte del messaggio e messa in un oggetto di tipo StringStream 
* 
*/
std::string visualizza_messaggio(const ROS_Homework_1::Num& msg){
	
	std::string messaggio= "";


  std::stringstream ss;

  if(choice == "a" )
	ss << "Nome: " << msg.nome << ".\n" <<"Eta: " << msg.eta <<".\n"<< "Corso di laurea: " << msg.corso_di_laurea << ".\n";
  else if(choice == "n")
	ss << "Nome: " << msg.nome << ".\n";
  else if(choice == "e")
	ss <<"Eta: " << msg.eta <<".\n";
  else if(choice == "c")
	ss << "Corso di laurea: " << msg.corso_di_laurea << ".\n";
  else if(choice == "x")
	system("pid=`ps -ax | grep rosrun | awk '{print $1}'`;kill $pid 2> /dev/null");// uccido	
  else
	ss << "Attesa comando valido..." << std::endl;	
   messaggio = ss.str();

	return messaggio;
}


void selectorCallBack(const std_msgs::String::ConstPtr& msg)
{

   choice = msg->data;
    
}


void senderCallBack(const ROS_Homework_1::Num& msg)
{
  
  std::cout << visualizza_messaggio(msg) << std::endl;
  
  
}




int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "viewer");

  ros::NodeHandle nHandler;

  ros::Subscriber selector_sub = nHandler.subscribe("comando", 1000, selectorCallBack);
  ros::Subscriber sender_sub = nHandler.subscribe("dati", 1000, senderCallBack);
  

  ros::spin();

  return 0;
}

