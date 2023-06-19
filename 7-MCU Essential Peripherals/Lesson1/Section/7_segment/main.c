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
	//configure portc as output push/pull
	DDRC=0xff;

}
int main(void)
{
    GPIO_init();
	int i,j,w=0;
    while (1) 
    {
		for(i=0;i<=9; i++)
		{
			for(j=0;j<=9; j++)
			{
				while(w<50)
				{
					PORTC= 0b1011| (i<<4); //Tens
					_delay_ms(10);
					PORTC= 0b0111| (j<<4); //Units
					_delay_ms(10);
					w++;
				}
				
				w=0;

			}
		}
		
}
}

