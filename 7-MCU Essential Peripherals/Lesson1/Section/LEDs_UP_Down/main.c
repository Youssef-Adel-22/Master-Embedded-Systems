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
	DDRD=0x00;
	DDRD|=(0b111<<5);
}
int main(void)
{
    GPIO_init();
	int i;
    while (1) 
    {	
		//LEDs Light UP
		for(i=5; i<8;i++){
		Set_bit(PORTD,i);
		_delay_ms(500);
		}
		//LEDs Light DOWN
		for(; i>=5;i--){
			Clear_bit(PORTD,i);
			_delay_ms(500);
		}

}
}

