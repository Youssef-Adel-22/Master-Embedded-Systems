/*
 * alarm_monitor.c
 *
 *  Created on: May 29, 2023
 *      Author: Harby
 */
#include "alarm_monitor.h"

//define states
enum AM_state{
	Alarm_OFF,
	Alarm_ON
}Alarm_Monitor_state_id;

//variables
void (*Alarm_Monitor_state_ptr)();

//Definition of state Functions
state_define(Alarm_OFF){
	Alarm_Monitor_state_id = Alarm_OFF;
	stop_alarm();
}

state_define(Alarm_ON){
	Alarm_Monitor_state_id = Alarm_ON;
		start_alarm();
		Delay(6000000);
		stop_alarm();
		Alarm_Monitor_state_ptr =state(Alarm_OFF);
}

//definition Connections Functions
void high_pressure_detected(){

	Alarm_Monitor_state_ptr = state(Alarm_ON);

}
