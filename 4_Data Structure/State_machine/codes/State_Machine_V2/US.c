/*
 * US.c
 *
 *  Created on: May 29, 2023
 *      Author: Harby
 */
#include "US.h"
//variables
static unsigned int US_distance;
void (*US_state_ptr)();

//state functions defination

int get_distance(int min, int max);

state_define(US_init){
	//state id
	US_state_id= init_state;
	//initialize us deriver
	printf("US initialize state......Done\n");
}
state_define(US_busy){
	//state id
	US_state_id = busy_state ;
	//state Action
	US_distance = get_distance(45, 55);
	printf("US busy state: Distance = %d \n",US_distance);
	read_distance(US_distance);

	US_state_ptr = state(US_busy);

}

int get_distance(int min, int max){
	int x = (rand() %(max-min)+min);
	return x;
}
