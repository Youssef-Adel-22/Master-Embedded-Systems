/*
 * pressure_sensor.c
 *
 *  Created on: May 29, 2023
 *      Author: Harby
 */
#include "pressure_sensor.h"

//Define states
enum P_state{
    pressure_sensor_init,
    pressure_sensor_Reading,
    pressure_sensor_Wating
}Pressure_sensor_state_id;

//variables
 int pressure_sensor_value =0;
void (*Pressure_sensor_state_ptr)();

//state functions definition
state_define(Pressure_sensor_init){
	//state id
	Pressure_sensor_state_id= pressure_sensor_init;
	//initialize us deriver
	Pressure_sensor_state_ptr = state(Pressure_sensor_Reading);
}



state_define(Pressure_sensor_Reading){
	//state id
	Pressure_sensor_state_id = pressure_sensor_Reading ;
	//state Action
	pressure_sensor_value = getPressureVal();
	set_pressure_value(pressure_sensor_value);
	Pressure_sensor_state_ptr = state(Pressure_sensor_Wating);

}

state_define(Pressure_sensor_Wating){
	//state id
	Pressure_sensor_state_id = pressure_sensor_Wating ;
	//state Action
	Delay(1000);
	Pressure_sensor_state_ptr = state(Pressure_sensor_Reading);
}

