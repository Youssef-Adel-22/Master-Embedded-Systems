/*
 * STM32F103C6_GPIO_Driver.h
 *
 *  Created on: Jun 22, 2023
 *      Author: Harby
 */

#ifndef INC_STM32F103C6_GPIO_DRIVER_H_
#define INC_STM32F103C6_GPIO_DRIVER_H_
//-----------------------------
//Includes
//-----------------------------
#include "STM32F103x6.h"
//-----------------------------
//User type definitions (structures)
//-----------------------------
typedef struct
{
	uint16_t GPIO_PinNumber;		//Specifies GPIO pin number to be configured
										//This parameter must be value of @REf GPIO_PINS_Define
	uint8_t GPIO_PinMODE;			//Specifies GPIO pin operating mode to be configured for the selected pins
										//This parameter must be value of @REf GPIO_MODE_Define
	uint8_t GPIO_Pin_OutputSpeed;	//Specifies GPIO output pin Speed to be configured for the selected pins
										//This parameter must be value of @REf GPIO_SPEED_Define
}GPIO_PinConfig_t;
//-----------------------------
//Macros Configuration References
//-----------------------------

//@REf GPIO_PINS_Define
#define GPIO_PIN_0		((uint16_t) 0x1)
#define GPIO_PIN_1		((uint16_t) 0x2)
#define GPIO_PIN_2		((uint16_t) 0x4)
#define GPIO_PIN_3		((uint16_t) 0x8)
#define GPIO_PIN_4		((uint16_t) 0x10)
#define GPIO_PIN_5		((uint16_t) 0x20)
#define GPIO_PIN_6		((uint16_t) 0x40)
#define GPIO_PIN_7		((uint16_t) 0x80)
#define GPIO_PIN_8		((uint16_t) 0x100)
#define GPIO_PIN_9		((uint16_t) 0x200)
#define GPIO_PIN_10		((uint16_t) 0x400)
#define GPIO_PIN_11		((uint16_t) 0x800)
#define GPIO_PIN_12		((uint16_t) 0x1000)
#define GPIO_PIN_13		((uint16_t) 0x2000)
#define GPIO_PIN_14		((uint16_t) 0x4000)
#define GPIO_PIN_15		((uint16_t) 0x8000)
#define GPIO_PIN_All	((uint16_t) 0xFFFF)

#define GPIO_PIN_MASK	Ox0000FFFFUL

//@REf GPIO_PIN_State
#define GPIO_PIN_LOW		0U
#define GPIO_PIN_HIGH		1U
//@REf GPIO_PIN_LOCK_State
#define GPIO_PIN_LOCK_FAILED	0U
#define GPIO_PIN_LOCK_OK		1U

//@REf GPIO_MODE_Define
//Input modes :
//0: Analog mode
//1: Floating input (reset state)
//2: Input with pull-up
//3: Input with pull-down
//output modes:
//4: General purpose output push-pull
//5: General purpose output Open-drain
//6: Alternate function output Push-pull
//7: Alternate function output Open-drain
//8: Alternate function input Floating


#define GPIO_MODE_OUTPUT_PP			0x0U
#define GPIO_MODE_OUTPUT_OD			0x1U
#define GPIO_MODE_OUTPUT_AF_PP		0x2U
#define GPIO_MODE_OUTPUT_AF_OD		0x3U
#define GPIO_MODE_INPUT_ANALOG		0x4U
#define GPIO_MODE_INPUT_FLO			0x5U
#define GPIO_MODE_INPUT_PU			0x6U
#define GPIO_MODE_INPUT_PD			0x7U
#define GPIO_MODE_INPUT_AF			0x8U

//@REf GPIO_SPEED_Define
//1: Output mode, max speed 10 MHz.
//2: Output mode, max speed 2 MHz.
//3: Output mode, max speed 50 MHz.

#define GPIO_SPEED_10M				0x1U
#define GPIO_SPEED_2M				0x2U
#define GPIO_SPEED_50M				0x3U



/*@ref Module_REF_NAME_define
*/
/*
* ===============================================
* APIs Supported by "MCAL GPIO DRIVER"
* ===============================================
*/
void MCAL_GPIO_Init(GPIO_t* GPIOx , GPIO_PinConfig_t* PinConfig);
void MCAL_GPIO_DeInit(GPIO_t* GPIOx);

uint8_t MCAL_GPIO_ReadPin(GPIO_t* GPIOx , uint16_t PinNumber);
uint16_t MCAL_GPIO_ReadPort(GPIO_t* GPIOx);

void MCAL_GPIO_WritePin(GPIO_t* GPIOx , uint16_t PinNumber, uint8_t PinValue);
void MCAL_GPIO_WritePort(GPIO_t* GPIOx,  uint16_t PortValue);

void MCAL_GPIO_TogglePin(GPIO_t* GPIOx , uint16_t PinNumber);
uint8_t MCAL_GPIO_LockPin(GPIO_t* GPIOx , uint16_t PinNumber);
#endif /* INC_STM32F103C6_GPIO_DRIVER_H_ */
