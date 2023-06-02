/*
 * alarm_actuator.c
 *
 *  Created on: May 29, 2023
 *      Author: Harby
 */
#include "alarm_actuator.h"

//define states
enum A_state{
	Alarm_Actutor_init,
	Alarm_Actutor_wating,
	Alarm_Actutor_OFF,
	Alarm_Actutor_ON
}Alarm_Actutor_state_id;

//variables
void (*Alarm_Actutor_state_ptr)();

//Definition of state Functions
state_define(Alarm_Actutor_init){
	//state id
	Alarm_Actutor_state_id= Alarm_Actutor_init;
	//initialize us deriver
	Alarm_Actutor_state_ptr= state(Alarm_Actutor_wating);
}

state_define(Alarm_Actutor_wating){
	//state id
		Alarm_Actutor_state_id= Alarm_Actutor_wating;
}

state_define(Alarm_Actutor_OFF){
	Alarm_Actutor_state_id = Alarm_Actutor_OFF;
	Set_Alarm_actuator(1);
}

state_define(Alarm_Actutor_ON){
	Alarm_Actutor_state_id = Alarm_Actutor_ON;
	Set_Alarm_actuator(0);
}
//Definition of Connection Functions
void stop_alarm(){
	Alarm_Actutor_state_ptr = state(Alarm_Actutor_OFF);
	Alarm_Actutor_state_ptr();
}

void start_alarm(){
	Alarm_Actutor_state_ptr = state(Alarm_Actutor_ON);
	Alarm_Actutor_state_ptr();
}
