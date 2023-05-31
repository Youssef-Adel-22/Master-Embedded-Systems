/*
 * main.c
 *
 *  Created on: May 27, 2023
 *      Author: Harby
 */
#include "CA.h"
#include "US.h"
#include "DC_motor.h"
extern void (*CA_state_ptr)();
extern void (*US_state_ptr)();
extern void (*DC_motor_state_ptr)();
volatile int i;
void setup(){
	//init first state
	US_state_ptr = state(US_init);
	US_state_ptr();
	DC_motor_state_ptr = state(DC_motor_init);
	DC_motor_state_ptr();
	CA_state_ptr = state(CA_stop);
	US_state_ptr = state(US_busy);
	DC_motor_state_ptr = state(DC_motor_stop);
}
int main()
{
	setup();
while(i<10){
	US_state_ptr();
	CA_state_ptr();
	DC_motor_state_ptr();
			//for(i=0;i<5000000;i++);
	i++;
}
return 0;
}
