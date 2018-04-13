#include "ros/ros.h"
#include "std_msgs/String.h"
#include "ROS_Homework_1/Num.h"
#include <sstream>

/*
* Stampa il menu e chiede all'utente cosa vuole che venga inviato.
* Salva la scelta in una variabile choice la quale viene ritornata e inserita poi nel messaggio.
*
*/
char stampa_menu(){


  char choice;

do{
   std::cout << "Selezionare una delle seguenti:" << std::endl;
   std::cout << "Digita a per stampare tutto il messaggio.\nDigita n per stampare solo il nome.\nDigita e per stampare solo l’età.\nDigita c per stampare solo il corso di laurea.\nDigita x per uscire\n.>";
   std::cin >> choice;
  }while (!(choice != 'a' || choice != 'e' || choice != 'n' || choice != 'c' || choice != 'x'));
  
return choice;

}



int main(int argc, char **argv)
{
  
  // Inizializzazione del nodo 
  ros::init(argc, argv, "selector");
 
 //Dichiaro l'handler del nodo
  ros::NodeHandle n;

  // Il publisher scrive sul topic comando con un buffer di 1000
  ros::Publisher selector_pub = n.advertise<std_msgs::String>("comando", 1000);

  // 1 message per second
  ros::Rate loop_rate(1); 

  
  while (ros::ok())
  {
    
    //Il messaggio da inviare è il carattere scelto
    std_msgs::String msg;
    msg.data = stampa_menu();

    //publica il messaggio
    selector_pub.publish(msg);


    ros::spinOnce();
    
  
    loop_rate.sleep();

  }


  return 0;
}

