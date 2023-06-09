/*
 * DC_motor.h
 *
 *  Created on: May 29, 2023
 *      Author: Harby
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "state.h"
//define states
enum{
	DC_motor_init,
	DC_motor_stop,
	DC_motor_move
}DC_motor_state_id;

state_define(DC_motor_init);
state_define(DC_motor_stop);
state_define(DC_motor_move);

//define ptr to functions
extern void (*DC_motor_state_ptr)();
#endif /* DC_MOTOR_H_ */
