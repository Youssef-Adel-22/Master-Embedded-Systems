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
	//configure pins D5.D6.D7 as output push/pull
	DDRD|=(0b111<<5);
	//Set pushbutton0 pin as input and Disable PullUP Resistor =(floating input)
	Clear_bit(DDRD,0);
	Set_bit(SFIOR,2);
}
int main(void)
{
    GPIO_init();
	int i =5;
	int f=0;
    while (1) 
    {
		if(Read_bit(PIND,0)==1)
		{
			
			if(f ==0)	//Light Up
			{ 
			Set_bit(PORTD,i);
			_delay_ms(500);
			i++;
			}
		
			else if(f ==1)	//Light Down
			{	
			Clear_bit(PORTD,i);
			_delay_ms(500);
			i--;
			}
		
			if(i > 7 ){		//Switch Direction
				i=7;
				f=1;
			}
			else if(i<5){	//Switch Direction
				i=5;
				f=0;
			}
		}
		
		
}
}

