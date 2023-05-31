/*
 * state.h
 *
 *  Created on: May 27, 2023
 *      Author: Harby
 */

#ifndef STATE_H_
#define STATE_H_
#include <stdint.h>
#include <stdio.h>
#include "driver.h"

//Auto State functions declaration
#define state_define(_stateFun_) void ST_##_stateFun_()
#define state(_stateFun_) ST_##_stateFun_

//Declaration of states Connection
void set_pressure_value(int32_t Pval);
void high_pressure_detected();
void start_alarm();
void stop_alarm();
#endif /* STATE_H_ */
