/*
 * CA.c
 *
 *  Created on: May 27, 2023
 *      Author: Harby
 */

#include "CA.h"
//variables
static unsigned int speed = 0, distance=0,threshold=50;

//state pointer to function

void (*CA_state_ptr)();
extern void (*US_state_ptr)();

//state functions defination

void read_distance(int US_distance){
	distance = US_distance;
	(distance <= threshold)?(CA_state_ptr =state(CA_stop)):(CA_state_ptr =state(CA_driving));
	printf("US---- Distance = %d -----> CA \n",distance);
}
state_define(CA_stop){
	//state id
	CA_state_id = CA_Stop;
	printf("CA Stop State---: Distance = %d\t Speed = %d \n",distance,speed);
	//state Action
	speed = 0;
	set_speed(speed);
	//US_state_ptr();
}

state_define(CA_driving){
	//state id
	CA_state_id = CA_Driving;
	printf("CA Driving State : Distance = %d\t Speed = %d \n",distance,speed);
	//state Action
	speed = 100;
	set_speed(speed);

}



