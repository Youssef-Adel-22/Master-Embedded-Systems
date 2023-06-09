/*
 * CA.c
 *
 *  Created on: May 27, 2023
 *      Author: Harby
 */

#include "CA.h"
//variables
static int speed = 0, distance=0,threshold=50;

//state pointer to function

void (*CA_state_ptr)();


//state functions defination
int get_distance(int min, int max);
state_define(CA_stop){
	//state id
	CA_state_id = CA_Stop;
	//state Action
	speed = 0;
	// check distance
	distance = get_distance(45,55);
	(distance <= threshold)?(CA_state_ptr =state(CA_stop)):(CA_state_ptr =state(CA_driving));

	printf("State Stop: Distance = %d\t Speed = %d \n",distance,speed);
}

state_define(CA_driving){
	//state id
	CA_state_id = CA_Driving;
	//state Action
	speed = 100;
	// check distance
	distance = get_distance(45,55);
	(distance <= threshold)?(CA_state_ptr =state(CA_stop)):(CA_state_ptr =state(CA_driving));

	printf("State Driving: Distance = %d\t Speed = %d \n",distance,speed);
}

int get_distance(int min, int max){
	int x = (rand() %(max-min)+min);
	return x;
}

