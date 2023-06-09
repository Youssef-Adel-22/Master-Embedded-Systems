/*
 * state.h
 *
 *  Created on: May 27, 2023
 *      Author: Harby
 */

#ifndef STATE_H_
#define STATE_H_

//Auto State functions declaration
#define state_define(_stateFun_) void ST_##_stateFun_()
#define state(_stateFun_) ST_##_stateFun_

//state Connections
void read_distance(int distance);
void set_speed(int speed);

#endif /* STATE_H_ */
