/*
 * CFile1.c
 *
 * Created: 6/20/2023 2:55:52 PM
 *  Author: Harby
 */
#include "keypad.h"
#include "STM32F103C6_GPIO_Driver.h"
extern GPIO_PinConfig_t pinConfig;

uint16_t row[4]= {GPIO_PIN_0,GPIO_PIN_1,GPIO_PIN_3,GPIO_PIN_4};
uint16_t col[4]= {GPIO_PIN_5,GPIO_PIN_6,GPIO_PIN_7,GPIO_PIN_8};
char keys[4][4]= {"789/","456X","123-","K0=+"};
void _delay_ms(uint32_t d);
void Keypad_init(void)
{
	uint8_t i;
	//Keypad_Dir = 0xF0;
	for(i=0;i<4;i++)
	{
		pinConfig.GPIO_PinNumber = 	row[i] ;
		pinConfig.GPIO_PinMODE   = 	GPIO_MODE_INPUT_PD;
		MCAL_GPIO_Init(keypad_PORT, &pinConfig);
	}
	for(i=0;i<4;i++)
	{
		pinConfig.GPIO_PinNumber = 	col[i] ;
		pinConfig.GPIO_PinMODE   = 	GPIO_MODE_OUTPUT_PP;
		pinConfig.GPIO_Pin_OutputSpeed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(keypad_PORT, &pinConfig);
	}
}
char Keypad_Getkey(void)
{
	uint8_t c=0,r=0,i;
	char p='A';
	for(c=0;c<4;c++)
	{
		//keypad_PORT|=0xF0;
		for(i=0;i<4;i++)
			MCAL_GPIO_WritePin(keypad_PORT, col[i], GPIO_PIN_LOW);
		//keypad_PORT&=~(1<<col[c]);
		MCAL_GPIO_WritePin(keypad_PORT, col[c], GPIO_PIN_HIGH);
		for(r=0;r<4;r++)
		{
			if(MCAL_GPIO_ReadPin(keypad_PORT, row[r]))
			{
				//_delay_ms(10);
				while(MCAL_GPIO_ReadPin(keypad_PORT, row[r]));
				p=keys[r][c];


			}
		}
	}
	return p;
}

