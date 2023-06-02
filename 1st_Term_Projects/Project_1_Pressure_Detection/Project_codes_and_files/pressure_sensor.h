/*
 * pressure_sensor.h
 *
 *  Created on: May 29, 2023
 *      Author: Harby
 */

#ifndef PRESSURE_SENSOR_H_
#define PRESSURE_SENSOR_H_
#include "state.h"

//Declaration of states ID
extern enum P_state Pressure_sensor_state_id;

state_define(Pressure_sensor_init);
state_define(Pressure_sensor_Reading);
state_define(Pressure_sensor_Wating);

//Declaration pointer to functions
extern void (*Pressure_sensor_state_ptr)();
#endif /* PRESSURE_SENSOR_H_ */

