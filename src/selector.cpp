#include "ros/ros.h"
#include "std_msgs/String.h"
#include "ROS_Homework_1/Num.h"
#include <sstream>
#include <string>



void selectorCallback(const ROS_Homework_1::Num& msg)
{
 
/*
* Stampa il menu e chiede all'utente cosa vuole che venga stampato
*
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  char choice;

do{
   std::cout << "Selezionare una delle seguenti:" << std::endl;
   std::cout << "Digita a per stampare tutto il messaggio.\nDigita n per stampare solo il nome.\nDigita e per stampare solo l’età.\nDigita c per stampare solo il corso di laurea.\nDigita x per uscire\n.>";
   std::cin >> choice;
  }while (!(choice != 'a' || choice != 'e' || choice != 'n' || choice != 'c' || choice != 'x'));
  
/*
* A seconda della scelta viene selezionata una parte del messaggio e messa in un oggetto di tipo StringStream 
*
*/

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  std::stringstream ss;

  if(choice == 'a' )
	ss << "Nome: " << msg.nome << ".\n" <<"Eta: " << msg.eta <<".\n"<< "Corso di laurea: " << msg.corso_di_laurea << ".\n";
  else if(choice == 'n')
	ss << "Nome: " << msg.nome << ".\n";
  else if(choice == 'e')
	ss <<"Eta: " << msg.eta <<".\n";
  else if(choice == 'c')
	ss << "Corso di laurea: " << msg.corso_di_laurea << ".\n";
  else if(choice == 'x')
	system("pkill roslaunch");// uccido	
	//ros::shutdown();

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 


 ros::NodeHandle node;

 static ros::Publisher partial_pub = node.advertise<std_msgs::String>("partial", 1000);
 static ros::Rate loop_rate(1);
    

    std_msgs::String message;
    message.data = ss.str();
    
    partial_pub.publish(message);

    ros::spinOnce();
    loop_rate.sleep();
 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}


int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "selector");
  
  ros::NodeHandle n;
  
  ros::Subscriber sub = n.subscribe("complete", 1000, selectorCallback);
  

  ros::spin();
  
  
  return 0;
}

