#!/bin/bash

# Avvio nodo roscore
roscore &
# Metto in sleep per attendere che parta il nodo roscore
sleep 1
# Faccio partire il primo nodo e li 
gnome-terminal -x sh -c "rosrun ROS_Homework_1 sender"
# Faccio partire il terzo nodo
gnome-terminal -x sh -c "rosrun ROS_Homework_1 viewer"
# Faccio partire il secondo nodo
gnome-terminal -x sh -c "rosrun ROS_Homework_1 selector"

