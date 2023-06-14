/*
 * test_AVR.c
 *
 * Created: 6/13/2023 10:53:26 AM
 * Author: Harby
 */ 
#define F_CPU 8000000UL
#include "EXT_interrupts.h"
//#include <avr/interrupt.h>
#include <util/delay.h>

#define SREG_R *((uint8_t *)0x5F)		//Global Interrupt Enable bit 7
#define DDRD_R *((uint8_t *)0x31)		//Select PORTD Direction
#define DDRB_R *((uint8_t *)0x37)		//Select PORTD Direction
#define PORTD_R *((uint8_t *)0x32)		//Digital Write on PORTD

//Definition of global pointers to External Interrupt Registers
MCUCR_reg* MCUCR_R = (MCUCR_reg*) 0x55; 
MCUCSR_reg* MCUCSR_R = (MCUCSR_reg*) 0x54; 
GICR_reg* GICR_R = (GICR_reg* )0x5B ;
GIFR_reg* GIFR_R = (GIFR_reg* ) 0x5A;
//Interrupt Handler of INT0
void __vector_1(void){
	PORTD_R |=(1<<5);
	_delay_ms(1000);
	PORTD_R &=~(1<<5);
	GIFR_R->GIFR_bits.INTF0_b=1;
	
}
//Interrupt Handler of INT1
void __vector_2(void){
	PORTD_R |=(1<<6);
	_delay_ms(1000);
	PORTD_R &=~(1<<6);
	GIFR_R->GIFR_bits.INTF1_b=1;
}
//Interrupt Handler of INT2
void __vector_3(void){
	PORTD_R |=(1<<7);
	_delay_ms(1000);
	PORTD_R &=~(1<<7);
	GIFR_R->GIFR_bits.INTF2_b=1;
}
int main(void)
{
	//Any logical change on INT0 generates an interrupt request
	MCUCR_R->MCUCR_bits.ISC00_b =1;
	MCUCR_R->MCUCR_bits.ISC01_b =0b0;
	//The rising edge of INT1 generates an interrupt request
	MCUCR_R->MCUCR_bits.ISC10_b =0b1;
	MCUCR_R->MCUCR_bits.ISC11_b =0b1;
	//If ISC2 is written to zero, a falling edge on INT2 activates the interrupt
	MCUCSR_R->MCUCSR_bits.ISC2_b=0;
	//Enable Interrupts INT0,INT1,INT2.
	GICR_R->GICR_all |=0xE0;
	//Set Bit 7 to 1:Global Interrupt Enable
	SREG_R |=(1<<7);
	
	//GPIO initialization
	DDRD_R |=0XEC;
	DDRB_R |=0x00;

    while (1) 
    {	
		
    }
}

