/*
 * DC_motor.c
 *
 *  Created on: May 29, 2023
 *      Author: Harby
 */

#include "DC_motor.h"
#include "stdio.h"
//variables
static unsigned int DC_speed;
void (*DC_motor_state_ptr)();

void set_speed(int speed){
	DC_speed =speed;

	(DC_speed > 0)?(DC_motor_state_ptr = state(DC_motor_move)):(DC_motor_state_ptr = state(DC_motor_stop));
	printf("CA ---- Speed: %d ----> DC motor\n",DC_speed);
	//DC_motor_state_ptr();
}

//Definition of states
state_define(DC_motor_init){
	//state id
	DC_motor_state_id= DC_motor_init;
	//initialize DC motor deriver
	printf("DC motor initialize state.......Done\n\n");
}
state_define(DC_motor_stop){
	DC_motor_state_id = DC_motor_stop;
	printf("DC Motor Stop State: Speed = %d \n\n",DC_speed);
}
state_define(DC_motor_move){
	DC_motor_state_id = DC_motor_move;
	printf("DC Motor move State: Speed = %d \n\n",DC_speed);
}
