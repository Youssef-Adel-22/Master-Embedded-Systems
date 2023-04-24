/*
 * main.c
 *
 *  Created on: Apr 8, 2023
 *      Author: Harby
 */

#include<stdio.h>

void Q1_function(void);
void Q2_function(void);
void Q3_function(void);
void Q4_function(void);
void Q5_function(void);
int main(){
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stdin,NULL,_IONBF,0);
	Q1_function();

	return 0;
}
