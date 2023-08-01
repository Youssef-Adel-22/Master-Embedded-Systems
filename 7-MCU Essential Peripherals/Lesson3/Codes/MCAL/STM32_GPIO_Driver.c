/*
 * STM32_GPIO_Driver.c
 *
 *  Created on: Jun 22, 2023
 *      Author: Harby
 */
#include "STM32F103C6_GPIO_Driver.h"

/* ===============================================
 * Private APIs Supported by "MCAL GPIO DRIVER"
 * ===============================================*/
uint8_t Get_RCLH_Position(uint16_t PinNumber)
{
	switch(PinNumber)
	{
	case GPIO_PIN_0:
	case GPIO_PIN_8:
		return 0;
		break;
	case GPIO_PIN_1:
	case GPIO_PIN_9:
		return 4;
		break;
	case GPIO_PIN_2:
	case GPIO_PIN_10:
		return 8;
		break;
	case GPIO_PIN_3:
	case GPIO_PIN_11:
		return 12;
		break;
	case GPIO_PIN_4:
	case GPIO_PIN_12:
		return 16;
		break;
	case GPIO_PIN_5:
	case GPIO_PIN_13:
		return 20;
		break;
	case GPIO_PIN_6:
	case GPIO_PIN_14:
		return 24;
		break;
	case GPIO_PIN_7:
	case GPIO_PIN_15:
		return 28;
		break;
	}
	return 0;
}
/**================================================================
 * @Fn				-MCAL_GPIO_Init
 * @brief 			-Initializes the GPIOx PINy peripheral to the specified parameters in the GPIO PinConfig
 * @param [in] 		-GPIOx: pointer to GPIO_t structure To select specific GPIOx peripheral >>> where x can be (A,B,C,D,E,F,G) depending on Device used
 * @param [in] 		-PinConfig: Pointer to GPIO_PinConfig_t structure that contains the configuration of specified GPIO pin
 * @retval 			-None
 * Note				-STM32F103C6
 */
void MCAL_GPIO_Init(GPIO_t* GPIOx , GPIO_PinConfig_t* PinConfig)
{
	//Each of the general-purpose I/O ports has two 32-bit configuration registers (GPIOx_CRL Pins(0 to 7) ,GPIOx_CRHPins(8 to 15))
	volatile uint32_t* CRx =(PinConfig->GPIO_PinNumber <= GPIO_PIN_7)?(&GPIOx->CRL):(&GPIOx->CRH);
	//config_Reg =(PinConfig->GPIO_PinNumber <= GPIO_PIN_7)?(&GPIOx->CRL):(&GPIOx->CRH);
	//Clear CNFx[1:0] MODEx[1:0]
	(*CRx) &= ~(0xF << Get_RCLH_Position(PinConfig->GPIO_PinNumber));
	//uint8_t CPin=0;
	switch(PinConfig->GPIO_PinMODE)
	{
	case GPIO_MODE_OUTPUT_PP:
	case GPIO_MODE_OUTPUT_OD:
	case GPIO_MODE_OUTPUT_AF_PP:
	case GPIO_MODE_OUTPUT_AF_OD:
		//CPin = ((PinConfig->GPIO_PinMODE << 2)|(PinConfig->GPIO_Pin_OutputSpeed)) << Get_RCLH_Position(PinConfig->GPIO_PinNumber)));
		(*CRx)|=((PinConfig->GPIO_PinMODE << 2)|(PinConfig->GPIO_Pin_OutputSpeed)) << Get_RCLH_Position(PinConfig->GPIO_PinNumber);
		break;
	case GPIO_MODE_INPUT_ANALOG:
		break;
	case GPIO_MODE_INPUT_FLO:
		(*CRx)|=(((PinConfig->GPIO_PinMODE-4) << 2)) << Get_RCLH_Position(PinConfig->GPIO_PinNumber);
		break;
	case GPIO_MODE_INPUT_PU:
		(*CRx)|=(((PinConfig->GPIO_PinMODE-4) << 2)) << Get_RCLH_Position(PinConfig->GPIO_PinNumber);
		GPIOx->ODR	|=PinConfig->GPIO_PinNumber;
		break;
	case GPIO_MODE_INPUT_PD:
		(*CRx)|=(((PinConfig->GPIO_PinMODE-5 )<< 2)) << Get_RCLH_Position(PinConfig->GPIO_PinNumber);
		GPIOx->ODR	&=~(PinConfig->GPIO_PinNumber);
		break;
	case GPIO_MODE_INPUT_AF:
		(*CRx)|=(((PinConfig->GPIO_PinMODE-7 )<< 2)) << Get_RCLH_Position(PinConfig->GPIO_PinNumber);
		break;


	}
}

/**================================================================
 * @Fn				-MCAL_GPIO_DeInit
 * @brief 			-Rest the GPIOx Registers
 * @param [in] 		-GPIOx){ pointer to GPIO_t structure To select specific GPIOx peripheral	>>> where x can be (A,B,C,D,E,F,G) depending on Device used
 * @retval 			-None
 * Note				-None
 */
void MCAL_GPIO_DeInit(GPIO_t* GPIOx )
{

	if(GPIOx==GPIOA)
	{
		RCC->APB2RSTR|=(1<<2);
		RCC->APB2RSTR&=~(1<<2);
	}
	else if(GPIOx== GPIOB)
	{
		RCC->APB2RSTR|=(1<<3);
		RCC->APB2RSTR&=~(1<<3);
	}
	else if(GPIOx== GPIOC)
	{
		RCC->APB2RSTR|=(1<<4);
		RCC->APB2RSTR&=~(1<<4);
	}
	else if(GPIOx== GPIOD)
	{
		RCC->APB2RSTR|=(1<<5);
		RCC->APB2RSTR&=~(1<<5);
	}
	else if(GPIOx== GPIOE)
	{
		RCC->APB2RSTR|=(1<<6);
		RCC->APB2RSTR&=~(1<<6);
	}
}
/**================================================================
 * @Fn				-MCAL_GPIO_ReadPin
 * @brief 			-Read Specific input Pin on the GPIOx Port
 * @param [in] 		-GPIOx: pointer to GPIO_t structure To select specific GPIOx peripheral >>> where x can be (A,B,C,D,E,F,G) depending on Device used
 * @param [in] 		-PinNumber: set The Number of the input pin want to read according to	>>> @REf GPIO_PINS_Define
 * @retval 			-uint8: A value of the selected input pin you want read 				>>> it can be a value of two values according to @REf GPIO_PIN_State
 * Note				-None
 */
uint8_t MCAL_GPIO_ReadPin(GPIO_t* GPIOx , uint16_t PinNumber)
{
	uint8_t PinState=(uint16_t)((GPIOx->IDR) & PinNumber)? GPIO_PIN_HIGH:GPIO_PIN_LOW;
	return PinState;
}
/**================================================================
 * @Fn				-MCAL_GPIO_ReadPort
 * @brief 			-Read Specific input GPIOx Port
 * @param [in] 		-GPIOx: pointer to GPIO_t structure To select specific GPIOx peripheral	>>> where x can be (A,B,C,D,E,F,G) depending on Device used
 * @retval 			-uint16: A value of the selected input GPIOx port to be read
 * Note				-None
 */
uint16_t MCAL_GPIO_ReadPort(GPIO_t* GPIOx )
{
	return((uint16_t)GPIOx->IDR);
}
/**================================================================
 * @Fn				-MCAL_GPIO_WritePin
 * @brief 			-Write a Specific value on specified output Pin on the GPIOx Port
 * @param [in] 		-GPIOx: pointer to GPIO_t structure To select specific GPIOx peripheral >>> where x can be (A,B,C,D,E,F,G) depending on Device used
 * @param [in] 		-PinNumber: set The Number of the pin you want to write on according to >>> @REf GPIO_PINS_Define
 * @param [in] 		-PinValue: set a value you want to write it according to 				>>> @REf GPIO_PIN_State
 * @retval 			-none
 * Note				-None
 */
void MCAL_GPIO_WritePin(GPIO_t* GPIOx , uint16_t PinNumber, uint8_t PinValue)
{
	//====================Method 1===========================
	//(PinValue== GPIO_PIN_HIGH)?(GPIOx->ODR|=PinNumber): (GPIOx->ODR&=~PinNumber);

	//====================Method 2===========================
	//	BSRR Register:(BSy) Portx Set bit y (y= 0 .. 15)
	//	These bits are write-only and can be accessed in Word mode only.
	//	0: No action on the corresponding ODRx bit
	//	1: Set the corresponding ODRx bit
	//	BSRR Register:(BRy) Port x Reset bit y (y= 0 .. 15)
	//	These bits are write-only and can be accessed in Word mode only.
	//	0: No action on the corresponding ODRx bit
	//	1: Reset the corresponding ODRx bit
	(PinValue== GPIO_PIN_LOW)?(GPIOx->BRR=(uint32_t)PinNumber): (GPIOx->BSRR=(uint32_t)PinNumber);
}
/**================================================================
 * @Fn				-MCAL_GPIO_WritePort
 * @brief 			-Write a Specific value on a specified output GPIOx Port
 * @param [in] 		-GPIOx: pointer to GPIO_t structure To select specific GPIOx peripheral	>>> where x can be (A,B,C,D,E,F,G) depending on Device used
 * @param [in] 		-PortValue: set a value you want to write
 * @retval 			-none
 * Note				-None
 */
void MCAL_GPIO_WritePort(GPIO_t* GPIOx,  uint16_t PortValue)
{
	GPIOx->ODR = (uint32_t)PortValue;
}
/**================================================================
 * @Fn				-MCAL_GPIO_TogglePin
 * @brief 			-Toggle a Specific value on specified output Pin on the GPIOx Port
 * @param [in] 		-GPIOx: pointer to GPIO_t structure To select specific GPIOx peripheral 	>>> where x can be (A,B,C,D,E,F,G) depending on Device used
 * @param [in] 		-PinNumber: set The Number of the pin you want to Toggle it according to 	>>> @REf GPIO_PINS_Define
 * @retval 			-none
 * Note				-None
 */
void MCAL_GPIO_TogglePin(GPIO_t* GPIOx , uint16_t PinNumber)
{
	GPIOx->ODR^=(uint32_t)PinNumber;
}
/**================================================================
 * @Fn				-MCAL_GPIO_LockPin
 * @brief 			-Lock the configuration of a Specific Pin on the GPIOx Port
 * @param [in] 		-GPIOx: pointer to GPIO_t structure To select specific GPIOx peripheral 	>>> where x can be (A,B,C,D,E,F,G) depending on Device used
 * @param [in] 		-PinNumber: set The Number of the pin you want to Lock it
 * @retval 			-uint8_t: return of Locking status (OK or Failed) it according to 			>>> @REf GPIO_PIN_LOCK_State
 * Note				-None
 */
uint8_t MCAL_GPIO_LockPin(GPIO_t* GPIOx , uint16_t PinNumber)
{
//select PinNumber to be locked
//	LCKy: Port x Lock bit y (y= 0 .. 15)
//	These bits are read write but can only be written when the LCKK bit is 0.
//	0: Port configuration not locked
//	1: Port configuration locked.
GPIOx->LCKR |= (uint32_t)PinNumber;

//LOCK key writing sequence:
//	Write 1
//	Write 0
//	Write 1
//	Read 0
//	Read 1 (this read is optional but confirms that the lock is active)
//	Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
//	Any error in the lock sequence will abort the lock.
GPIOx->LCKR|=(1<<16);
GPIOx->LCKR&=~(1<<16);
GPIOx->LCKR|=(1<<16);
uint8_t Read =(GPIOx->LCKR>>16);
Read=(GPIOx->LCKR>>16);
if(Read== GPIO_PIN_LOCK_FAILED)
	return GPIO_PIN_LOCK_FAILED;
else
	return GPIO_PIN_LOCK_OK;
}

