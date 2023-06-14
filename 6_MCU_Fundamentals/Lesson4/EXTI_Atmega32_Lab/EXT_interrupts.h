/*
 * IncFile1.h
 *
 * Created: 6/13/2023 3:55:03 PM
 *  Author: Harby
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_
#include "stdint.h"
typedef union{
	uint8_t MCUCR_all;
	struct{
		uint8_t ISC00_b:1;
		uint8_t ISC01_b:1;
		uint8_t ISC11_b:1;
		uint8_t ISC10_b:1;
		uint8_t :4;
		}MCUCR_bits;
	}MCUCR_reg;
	
typedef union{
	uint8_t MCUCSR_all;
	struct{
		uint8_t :6;
		uint8_t ISC2_b:1;
		uint8_t :1;
	}MCUCSR_bits;
}MCUCSR_reg;

typedef union{
	uint8_t GICR_all;
	struct{
		uint8_t :5;
		uint8_t INT2_b:1;
		uint8_t INT0_b:1;
		uint8_t INT1_b:1;
	}GICR_bits;
}GICR_reg;
typedef union{
	uint8_t GIFR_all;
	struct{
		uint8_t :5;
		uint8_t INTF2_b:1;
		uint8_t INTF0_b:1;
		uint8_t INTF1_b:1;
	}GIFR_bits;
}GIFR_reg;


//Declaration of Vectors INT0,INT1,INT2
void __vector_1(void) __attribute__((signal));
void __vector_2(void) __attribute__((signal));
void __vector_3(void) __attribute__((signal));

//Array of pointers to vectors
void (*EXTI_CallBack[3])(void) = {__vector_1 , __vector_2,__vector_3};
#endif /* INCFILE1_H_ */