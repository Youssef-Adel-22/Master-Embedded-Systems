/*
* LCD_Keypad.c
*
* Created: 6/20/2023 9:14:40 AM
* Author : Harby
*/
#define F_CPU 1000000UL
#include "LCD.h"
#include <util/delay.h>
#include "keypad.h"
int main(void)
{
	LCD_init();
	Keypad_init();
	char pressed_kay='N';
	while (1)
	{
		pressed_kay=Keypad_Getkey();
		if (pressed_kay != 'N'){
			LCD_W_char(pressed_kay);
		}
	}
}

