/*
 * Seg_7.c
 *
 *  Created on: Jun 26, 2023
 *      Author: Youssef Adel
 */
#include "SEG_7.h"
#include "STM32F103C6_GPIO_Driver.h"
uint16_t SEG_pins[7]={GPIO_PIN_9,GPIO_PIN_10,GPIO_PIN_11,GPIO_PIN_12,GPIO_PIN_13,GPIO_PIN_14,GPIO_PIN_15};
uint8_t SEG_Numbers[10]={ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
extern GPIO_PinConfig_t pinConfig;
void SEG_init(void)
{
	//Select Mode of Pins as output Push Pull
	uint8_t i;
	pinConfig.GPIO_PinMODE			= GPIO_MODE_OUTPUT_PP;
	pinConfig.GPIO_Pin_OutputSpeed 	= GPIO_SPEED_10M;
	for(i=0;i<7;i++)
	{
		pinConfig.GPIO_PinNumber = SEG_pins[i];
		MCAL_GPIO_Init(SEG_PORT, &pinConfig);
		MCAL_GPIO_WritePin(SEG_PORT, pinConfig.GPIO_PinNumber , GPIO_PIN_HIGH);
	}
}

void SEG_Write_Number(uint8_t num)
{
	//clear 7_segment
	SEG_clear();
	//write Number 0->9
	uint8_t i;
	for(i=0;i<7;i++)
		MCAL_GPIO_WritePin(SEG_PORT, SEG_pins[i],(num>>i)&1);
		//MCAL_GPIO_WritePort(SEG_PORT, num<<9);

}
void SEG_clear(void)
{
	//Write LOW on all 7segment pins
	uint8_t i;
	for(i=0;i<7;i++)
		MCAL_GPIO_WritePin(SEG_PORT, SEG_pins[i], GPIO_PIN_LOW);
}

