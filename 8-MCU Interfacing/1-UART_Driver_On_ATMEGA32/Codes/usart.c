/*
 * CFile1.c
 *
 * Created: 7/10/2023 2:05:35 PM
 *  Author: Harby
 */ 
#include "usart.h"
/**================================================================
 * @Fn				-MCAL_USART_Init
 * @brief 			-Initializes the USART peripheral to the specified parameters in USART_Config structure
 * @param [in] 		-USART_Config: pointer to USART Configuration structure 
 * @retval 			-None
 * Note				-none
 */
void MCAL_USART_Init(USART_Config_t* USART_Config)
{
	//Select UBRR value for transmission and Receiving Data
	uint16_t UBRR;
	UCSRC&=~(1<<7);									//The URSEL[bit 7] must be zero when writing the UBRRH
	if(USART_Config->USART_MODE == Asynchronous_Mode)
	{
		UBRR  = (USART_Config->USART_Speed_MODE)?(USART_Config->Frequency_OSC/(8*USART_Config->BaudRate)-1):(USART_Config->Frequency_OSC/(16*USART_Config->BaudRate)-1);
		UBRRH = (uint8_t)(UBRR>>8);
		UBRRL = (uint8_t) UBRR;
	}else //Synchronous Master mode
	{
		UBRR = USART_Config->Frequency_OSC/(2*USART_Config->BaudRate)-1;
		UBRRH = (uint8_t)(UBRR>>8);
		UBRRL = (uint8_t) UBRR;
	}
	
	UCSRC|=(1<<7);									//The URSEL must be one when writing the UCSRC
	UCSRC|= USART_Config->USART_MODE;				//Select USART Mode Synchronous/ Asynchronous
	UCSRC=USART_Config->Parity_Mode;				//Select Parity Disable/ Even/ Odd
	UCSRC|= USART_Config->Stop_Bit_Select ;			//Select Number of Stop bits 1 or 2
	UCSRA|=USART_Config->USART_Speed_MODE;			//selects between Normal Mode and Double Speed Mode of operation.
	// Select Clock Polarity in Case of Synchronous Mode
	UCSRC|=(USART_Config->USART_MODE == Synchronous_Mode)? (USART_Config->Clock_Polarity):0;
	//selects the number of data bits (Character Size) in a frame
	if(USART_Config->Character_Size == _9_bit)		// in case of 9 bits data
	{
		UCSRC|= 0X6;
		UCSRB|=(1<<2);
	}else											// in case of 5-8 bits data
	{
		UCSRC|= USART_Config->Character_Size;
	}
	UCSRB|=USART_Config->Communication_Mode;		//Specifies communication type (Simplex/ Full Duplex) to be configured 
	
}

/**================================================================
 * @Fn				-MCAL_USART_Transmit
 * @brief 			-Transmit Data throughout USART
 * @param [in] 		-Data: 5-9 bits of data want to Transmit
 * @retval 			-None
 * Note				-none
 */
void MCAL_USART_Transmit(uint16_t Data)
{
	while(!(UCSRA & (1<<5)));				//Wait for empty transmit buffer
 	if(Data &(1<<8))
 	{
 		//UCSRB &=~(1<<0);					//Clear TXB8 in UCSRB Register first
 		UCSRB|=	(1<<0);						//Set TXB8 in UCSRB Register first
 		UDR	  =	(uint8_t)Data;				//Put data into buffer, sends the data
 	}
 	else									//frame of 5-8 bits of data
 	{
		UDR =(uint8_t)Data;
	}
}
uint16_t MCAL_USART_Recive(void)
{
	while(!(UCSRA & (1<<7)));				//Wait for data to be received
	
	return((((UCSRB>>1)&1)<<8) | UDR);
	
}


void MCAL_USART_Transmit_String(char* Data)
{
	while(*Data > 0)
	{
		MCAL_USART_Transmit((uint16_t)*Data);
		Data++;
	}
	MCAL_USART_Transmit('.');				//Termination Character
}
void MCAL_USART_Recive_String(char* buffer)
{
	char c=0;
	uint8_t i=0;
	while(c!= '\r')
	{
		c= MCAL_USART_Recive();
		buffer[i]= c;
		i++;
	}

}

void MCAL_USART_Transmit_int(uint32_t Data)
{
	uint8_t *byte=(uint8_t*)&Data;
	MCAL_USART_Transmit(*(byte+3));
	MCAL_USART_Transmit(*(byte+2));
	MCAL_USART_Transmit(*(byte+1));
	MCAL_USART_Transmit(*(byte+0));
	
}
uint32_t MCAL_USART_Recive_int()
{
	uint8_t byte;
	uint32_t DW=0;
	byte = MCAL_USART_Recive();
	DW|=(byte<<24);
	byte = MCAL_USART_Recive();
	DW|=(byte<<16);
	byte = MCAL_USART_Recive();
	DW|=(byte<<8);
	byte = MCAL_USART_Recive();
	DW|=(byte<<0);
	return DW;
}