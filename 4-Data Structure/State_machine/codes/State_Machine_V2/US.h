/*
 * US.h
 *
 *  Created on: May 29, 2023
 *      Author: Harby
 */

#ifndef US_H_
#define US_H_
#include "state.h"
#include "stdio.h"
#include "stdlib.h"
//define states
enum {
	init_state,
	busy_state
}US_state_id;

//declaration state functions
state_define(US_init);
state_define(US_busy);

//state ptr to fun
extern void (*US_state_ptr)();
#endif /* US_H_ */
