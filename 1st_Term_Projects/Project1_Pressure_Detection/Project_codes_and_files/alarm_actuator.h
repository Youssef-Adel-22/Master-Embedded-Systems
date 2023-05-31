/*
 * alarm_actuator.h
 *
 *  Created on: May 29, 2023
 *      Author: Harby
 */

#ifndef ALARM_ACTUATOR_H_
#define ALARM_ACTUATOR_H_
#include "state.h"

//Declaration of states ID
extern enum A_state Alarm_Actutor_state_id;

state_define(Alarm_Actutor_init);
state_define(Alarm_Actutor_wating);
state_define(Alarm_Actutor_OFF);
state_define(Alarm_Actutor_ON);

//Declaration pointer to functions
extern void (*Alarm_Actutor_state_ptr)();


#endif /* ALARM_ACTUATOR_H_ */
