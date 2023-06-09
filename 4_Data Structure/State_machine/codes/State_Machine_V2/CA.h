/*
 * CA.h
 *
 *  Created on: May 27, 2023
 *      Author: Harby
 */

#ifndef CA_H_
#define CA_H_
#include "state.h"
#include "stdio.h"

//Define States
enum {
	CA_Stop, CA_Driving
}CA_state_id;

//declare State Function
state_define(CA_stop);
state_define(CA_driving);

//state ptr to fun
extern void (*CA_state_ptr)();

#endif /* CA_H_ */
