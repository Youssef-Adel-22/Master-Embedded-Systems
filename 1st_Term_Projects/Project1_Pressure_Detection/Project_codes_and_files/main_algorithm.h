/*
 * main_algorithm.h
 *
 *  Created on: May 29, 2023
 *      Author: Harby
 */

#ifndef MAIN_ALGORITHM_H_
#define MAIN_ALGORITHM_H_
#include "state.h"

//Declaration of states ID
extern enum M_state Main_Algorithm_state_id;

state_define(Compare_Pressure_value);


//Declaration pointer to functions
extern void (*Main_Algorithm_state_ptr)();


#endif /* MAIN_ALGORITHM_H_ */
