/*
 * alarm_monitor.h
 *
 *  Created on: May 29, 2023
 *      Author: Harby
 */

#ifndef ALARM_MONITOR_H_
#define ALARM_MONITOR_H_
#include "state.h"

extern enum AM_state Alarm_Monitor_state_id;

state_define(Alarm_OFF);
state_define(Alarm_ON);

//Declaration pointer to functions
extern void (*Alarm_Monitor_state_ptr)();


#endif /* ALARM_MONITOR_H_ */

