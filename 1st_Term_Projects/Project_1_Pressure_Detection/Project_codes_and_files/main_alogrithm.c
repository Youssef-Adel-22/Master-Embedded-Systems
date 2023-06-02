/*
 * main_alogrithm.c
 *
 *  Created on: May 29, 2023
 *      Author: Harby
 */
#include "main_algorithm.h"

//Define states
enum M_state{
	Compare_Pressure_value
}Main_Algorithm_state_id;

//variables
int32_t pressure_value=0, threshold_val=20;
void (*Main_Algorithm_state_ptr)();

//states function definition
state_define(Compare_Pressure_value){
	//state id
	Main_Algorithm_state_id = Compare_Pressure_value;
	//state Action
	if( pressure_value > threshold_val) 
		high_pressure_detected();
	else
		Main_Algorithm_state_ptr = state(Compare_Pressure_value);
}

//Definition Connection Functions
void set_pressure_value(int32_t Pval){
	pressure_value = Pval;
}
