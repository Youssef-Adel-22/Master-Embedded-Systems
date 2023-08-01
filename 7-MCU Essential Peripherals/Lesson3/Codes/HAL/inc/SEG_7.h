/*
 * Seg_7.h
 *
 *  Created on: Jun 26, 2023
 *      Author: Harby
 */

#ifndef SEG_7_H_
#define SEG_7_H_
#include"STM32F103x6.h"
#define SEG_PORT GPIOB
#define COMMON Anode  //Anode/cathode
//7_Segment APIs
void SEG_init(void);
void SEG_clear(void);
void SEG_Write_Number(uint8_t num);		//Specifies Number to be display
											//This parameter must be value of @REf 7_Segment Numbers


//@REf 7_Segment Numbers
#if(COMMON == Cathode)
#define ZERO 	0b00111111		//(gfedcba)>> g=0 , abcdef=1
#define ONE 	0b00000110		//(gfedcba)>> adefg=0 , bc=1
#define TWO 	0b01011011		//(gfedcba)>> cf=0 , abdeg=1
#define THREE 	0b01001111		//(gfedcba)>> ef=0 ,abcdg=1
#define FOUR 	0b01100110
#define FIVE 	0b01101101
#define SIX	 	0b01111101
#define SEVEN 	0b00000111
#define EIGHT 	0b01111111
#define NINE 	0b01101111
#endif
#if(COMMON == Anode)
#define ZERO 	0b00111111		//(gfedcba)>> g=0 , abcdef=1
#define ONE 	0b00000110		//(gfedcba)>> adefg=0 , bc=1
#define TWO 	0b01011011		//(gfedcba)>> cf=0 , abdeg=1
#define THREE 	0b01001111		//(gfedcba)>> ef=0 ,abcdg=1
#define FOUR 	0b01100110
#define FIVE 	0b01101101
#define SIX	 	0b01111101
#define SEVEN 	0b00000111
#define EIGHT 	0b01111111
#define NINE 	0b01101111
#endif
#endif /* 7_SEGMENT_DRIVER_SEG_7_H_ */
