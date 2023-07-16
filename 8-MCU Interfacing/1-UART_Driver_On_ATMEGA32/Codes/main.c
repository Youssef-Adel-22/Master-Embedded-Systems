/*
 * Atmega32.c
 *
 * Created: 7/10/2023 12:16:52 PM
 * Author : Harby
 */ 

#include<LCD.h>
#include "usart.h"

int main(void)
{
	// my USART configuration
	USART_Config_t myUSART_config;
	myUSART_config.Frequency_OSC		= FOSC_8MHZ;
	myUSART_config.BaudRate				= BaudRate_9600;
	myUSART_config.USART_MODE			= Asynchronous_Mode;
	myUSART_config.USART_Speed_MODE		= Normal_Mode;
	myUSART_config.Character_Size		= _8_bit;
	myUSART_config.Parity_Mode			= Disabled_Parity;
	myUSART_config.Stop_Bit_Select		= ONE_BIT;
	myUSART_config.Communication_Mode	= Full_Duplex;
	MCAL_USART_Init(&myUSART_config);
	
    /* Replace with your application code */
	LCD_init();
	LCD_clear();
	LCD_W_str("LCD is Ready ^_^");
	LCD_Set_XY(0,1);
	
	uint16_t Received_Data;
	char buffer[50];

	MCAL_USART_Transmit_String("USART Driver Created By Youssef Adel");
	MCAL_USART_Transmit(NewLine);
    while (1) 
    {
		MCAL_USART_Transmit_String("1- Send characters To LCD");
		MCAL_USART_Transmit(NewLine);
		MCAL_USART_Transmit_String("2- Send String To LCD");
		MCAL_USART_Transmit(NewLine);
		MCAL_USART_Transmit_String("3- Send Double Word To LCD");
		MCAL_USART_Transmit(NewLine);
		MCAL_USART_Transmit_String("4- Clear Terminal ");
		MCAL_USART_Transmit(NewLine);
		MCAL_USART_Transmit_String("5- Clear LCD ");
		MCAL_USART_Transmit(NewLine);
		Received_Data = MCAL_USART_Recive();
		switch(Received_Data)
		{
			case('1'):
			MCAL_USART_Transmit(Clear_Terminal);
			MCAL_USART_Transmit_String("** Send characters To LCD **");
			MCAL_USART_Transmit(NewLine);
			MCAL_USART_Transmit_String("-To back to Main List click *");
			MCAL_USART_Transmit(NewLine);
			while(Received_Data != '*')
			{
				Received_Data = MCAL_USART_Recive();
				LCD_W_char(Received_Data);
			}
			MCAL_USART_Transmit(Clear_Terminal);
			break;
			case('2'):
			MCAL_USART_Transmit(Clear_Terminal);
			MCAL_USART_Transmit_String("** Send String To LCD **");
			MCAL_USART_Transmit(NewLine);
			MCAL_USART_Transmit_String("-End your string by Enter");
			MCAL_USART_Transmit(NewLine);
			MCAL_USART_Transmit_String("-To back to Main List click *");
			MCAL_USART_Transmit(NewLine);
			LCD_clear();
			LCD_W_str("Waiting for Str  to be received..");
			MCAL_USART_Recive_String(buffer);
			LCD_clear();
			LCD_W_str(buffer);
			MCAL_USART_Transmit(NewLine);
			break;
			case('4'):
			MCAL_USART_Transmit(Clear_Terminal);
			break;
			case('5'):
			LCD_clear();
			MCAL_USART_Transmit(NewLine);
			break;
		}
		
    }
}

