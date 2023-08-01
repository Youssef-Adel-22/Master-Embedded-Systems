/*
 * SPI.h
 *
 * Created: 7/18/2023 2:33:06 PM
 *  Author: Harby
 */ 


#ifndef SPI_H_
#define SPI_H_
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
	uint32_t  SPI_BaudRate;				//control the SCK rate of the device configured as a Master.
										//This parameter must be value of @REF Baud Rate[bps]
	uint8_t SPI_Clock_Polarity;				//Select Data mode from the four combinations of SCK phase and polarity with respect to serial data
											//This parameter must be value of @REf Clock Polarity
	uint8_t SPI_Clock_Phase;				//Select Data mode from the four combinations of SCK phase and polarity with respect to serial data
											//This parameter must be value of @REf Clock phase
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

}SPI_Config_t;
//-----------------------------
//Macros Configuration References
//-----------------------------

//@REf Communication Modes

	
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
#define DivBy_2		0x4						//Frequency OSC/2
#define DivBy_4		0x0						//Frequency OSC/4
#define DivBy_8		0x5						//Frequency OSC/8
#define DivBy_16	0x1						//Frequency OSC/16
#define DivBy_32	0x6						//Frequency OSC/32
#define DivBy_64	0x7						//Frequency OSC/64
#define DivBy_128	0x3						//Frequency OSC/128

//@REf Data Modes
#define Mode1  0x0							//SCK is LOW when idle --Sampled on the leading (first) edge of SCK.
#define Mode2  0x1							//SCK is HIGH when idle --Sampled on the Trailing (Last) edge of SCK.
#define Mode3  0x2							//SCK is HIGH when idle --Sampled on the Trailing (Last) edge of SCK.
#define Mode3  0x3							//SCK is HIGH when idle --Sampled on the Trailing (Last) edge of SCK.

//@REf clock Polarity
#define Idel_LOW  0x0						//SCK is LOW when idle.
#define Idel_High 0x1						//SCK is high when idle.		

//@REf clock Phase
#define Sampling_leading_Edge	0x0			// Sampled on the leading (first) edge of SCK
#define Sampling_Trailing_Edge  0x1			//Sampled on the Trailing (Last) edge of SCK
#endif /* SPI_H_ */