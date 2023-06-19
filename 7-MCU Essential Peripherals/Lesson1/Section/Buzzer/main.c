/*
 * uint7_Lesson1_lab1.c
 *
 * Created: 6/17/2023 12:26:23 PM
 * Author : Harby
 */ 
#define F_CPU 8000000
#include "avr/delay.h"
#include "Utils.h"
#include "MemMap.h"
void GPIO_init(){
	//Set Buzzer pin as OUTPUT push/pull
	Set_bit(DDRD,4);
	//Set pushbutton0 pin as input and Diable PullUP Resistor =(floating input)
	Clear_bit(DDRD,0);
	Set_bit(SFIOR,2);
}
int main(void)
{
    GPIO_init();

    while (1) 
    {
		if(Read_bit(PIND,0)==1)
		{
			//Turn ON Buzzer for 1000 mSec
			Set_bit(PORTD,4);
			_delay_ms(1000);
			Clear_bit(PORTD,4);
			
		}
		
}
}

