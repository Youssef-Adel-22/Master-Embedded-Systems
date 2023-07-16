/*
 * usart.h
 *
 * Created: 7/10/2023 1:56:56 PM
 *  Author: Youssef Harby
 */ 


#ifndef USART_H_
#define USART_H_
//-----------------------------
//Includes
//-----------------------------
#include "Register_map.h"
//-----------------------------
//User type definitions (structures)
//-----------------------------

typedef struct
{
	uint32_t  Frequency_OSC;			//Specifies System oscillator clock frequency.
										//This parameter must be value of @REf oscillator clock frequency
	uint32_t  BaudRate;					//Specifies Baud rate (in bits per second, bps).
										//This parameter must be value of @REF Baud Rate[bps]
	uint8_t USART_Speed_MODE;			//selects between Normal Mode and Double Speed Mode of operation.
										//This parameter must be value of @REf USART Speed MODE
	uint8_t Communication_Mode;			//Specifies communication type (Simplex/ Full Duplex) to be configured 
										//This parameter must be value of @REf Communication Modes
	uint8_t USART_MODE;					//selects between Asynchronous and Synchronous mode of operation.
										//This parameter must be value of @REf USART MODES
	uint8_t Parity_Mode;				//Disable Parity/ Enable Parity and set type of Parity Generation and Check
										//This parameter must be value of @REf Parity Mode
	uint8_t Stop_Bit_Select;			//selects the number of stop bits to be inserted by the Transmitter
										//This parameter must be value of @REf Stop Bit Select
	uint8_t Character_Size;				//selects the number of data bits (Character Size) in a frame the Receiver and Transmitter use.
										//This parameter must be value of @REf Character Size
	uint8_t Clock_Polarity;				//This bit is used for Synchronous mode only. sets the relationship between data output change and data input sample, and the synchronous clock (XCK)
										//This parameter must be value of @REf Character Size
}USART_Config_t;
//-----------------------------
//Macros Configuration References
//-----------------------------

//@REf Communication Modes
#define TX_ONLY				0x8
#define RX_ONLY				0x16
#define Full_Duplex			0x18
			
//@REf USART MODES
#define Asynchronous_Mode	0x0
#define Synchronous_Mode	0x40

//@REF Parity Mode
#define Disabled_Parity		0x0
#define Even_Parity			0x20
#define odd_Parity			0x30

//@REf Stop Bit Select
#define ONE_BIT				0x0
#define TWO_BITS			0x8

//@REf Character Size
#define _5_bit				0x0
#define _6_bit				0x2
#define _7_bit				0x4
#define _8_bit				0x6
#define _9_bit				0xE

//@REF Clock Polarity
#define TXRising_RXFalling 	0x0
#define RXRising_TXFalling 	0x1

//@REF Oscillator Clock Frequency
#define FOSC_1MHZ			8000000UL			//MaxSpeed in Normal Mode 62.5kbps,		in Double Speed Mode 125kbps
#define FOSC_1843kHz		1843200UL			//MaxSpeed in Normal Mode 115.2kbps,	in Double Speed Mode 230.4kbps
#define FOSC_2MHZ			2000000UL			//MaxSpeed in Normal Mode 125kbps,		in Double Speed Mode 250kbps
#define FOSC_3686kHZ		3686400UL			//MaxSpeed in Normal Mode 230.4kbps,	in Double Speed Mode 460.8kbps
#define FOSC_4MHZ			4000000UL			//MaxSpeed in Normal Mode 250kbps,		in Double Speed Mode 0.5Mbps
#define FOSC_7373kHZ		7372800UL			//MaxSpeed in Normal Mode 460.8kbps,	in Double Speed Mode 921.6kbps
#define FOSC_8MHZ			8000000UL			//MaxSpeed in Normal Mode 0.5Mbps,		in Double Speed Mode 1Mbps
#define FOSC_11059kHZ		11059200UL			//MaxSpeed in Normal Mode 691.2kbps,	in Double Speed Mode 1.3824Mbps
#define FOSC_14745kHz		14745600UL			//MaxSpeed in Normal Mode 921.6kbps,	in Double Speed Mode 1.8432Mbps
#define FOSC_16MHz			16000000UL			//MaxSpeed in Normal Mode 1Mbps,		in Double Speed Mode 2Mbps
#define FOSC_18432kHz		18432000UL			//MaxSpeed in Normal Mode 1.152Mbps,	in Double Speed Mode 2.304Mbps
#define FOSC_20MHz			20000000UL			//MaxSpeed in Normal Mode 1.25Mbps,		in Double Speed Mode 2.5Mbps

//@REF Baud Rate[bps]
#define BaudRate_2400		2400UL
#define BaudRate_4800		4800UL
#define BaudRate_9600		9600UL
#define BaudRate_14400		14400UL			
#define BaudRate_19200		19200UL
#define BaudRate_28800		28800UL
#define BaudRate_38400		38400UL
#define BaudRate_57600		57600UL
#define BaudRate_76800		76800UL
#define BaudRate_115200		115200UL
#define BaudRate_230400		230400UL
#define BaudRate_250k		250000UL
#define BaudRate_500k		500000UL
#define BaudRate_1M			1000000UL

//@REf USART Speed MODE
#define Normal_Mode			0x0
#define Double_Speed_Mode	0x2

//@REf selects between UCSRC/UBRRH Register
#define Select_UBRRH		0x0
#define Select_UCSRC		0x80

//@REf special characters for terminal
#define backSpace			8
#define Clear_Terminal		12
#define NewLine				13
/* ===============================================
* APIs Supported by "MCAL USART DRIVER"
* ===============================================
*/
void MCAL_USART_Init(USART_Config_t* USART_Config);
void MCAL_USART_Transmit(uint16_t Data);
uint16_t MCAL_USART_Recive(void);
void MCAL_USART_Transmit_String(char* Data);
void MCAL_USART_Recive_String(char*);
void MCAL_USART_Transmit_int(uint32_t Data);
uint32_t MCAL_USART_Recive_int();
#endif /* USART_H_ */