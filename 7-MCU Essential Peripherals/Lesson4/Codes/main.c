/*
 * Atmega32.c
 *
 * Created: 7/10/2023 12:16:52 PM
 * Author : Harby
 */ 
#define F_CPU 1000000UL
#include<LCD.h>


int main(void)
{

	
    /* Replace with your application code */
	LCD_init();
	LCD_W_str("learn-in-depth");
	

}

