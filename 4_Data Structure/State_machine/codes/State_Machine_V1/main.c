/*
 * main.c
 *
 *  Created on: May 27, 2023
 *      Author: Harby
 */
#include "CA.h"

extern void (*CA_state_ptr)();
volatile int i;
void setup(){
	//init frist state
	CA_state_ptr = state(CA_stop);
}
int main()
{
	setup();
while(CA_state_ptr){
	CA_state_ptr();
	for(i=0;i<5000000;i++);
}
return 0;
}
