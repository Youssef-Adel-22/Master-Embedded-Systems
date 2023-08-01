/*
 * STM32F103C6_EXTI_Driver.c
 *
 *  Created on: Jun 29, 2023
 *      Author: Youssef Adel
 */
#include "STM32F103C6_GPIO_Driver.h"
#include "STM32F103C6_EXTI_Driver.h"

//-*-*-*-*-*-*-*-*-*-*-*-
//Generic variables
//-*-*-*-*-*-*-*-*-*-*-*
void(*GPtr_IRQ_callBack[16])(void);
//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*
#define AFIO_GPIO_EXTI_MAPPING(X)	((X==GPIOA)?0:\
									(X==GPIOB)?1:\
									(X==GPIOC)?2:\
									(X==GPIOD)?3:0)

//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Functions
//-*-*-*-*-*-*-*-*-*-*-*
void NVIC_Enable(uint8_t IRQ_num)
{
	switch(IRQ_num)
	{
	case 0:
		NVIC_EN_IRQ_EXTI0();
		break;
	case 1:
		NVIC_EN_IRQ_EXTI1();
		break;
	case 2:
		NVIC_EN_IRQ_EXTI2();
		break;
	case 3:
		NVIC_EN_IRQ_EXTI3();
		break;
	case 4:
		NVIC_EN_IRQ_EXTI4();
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_EN_IRQ_EXTI5_9();
		break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_EN_IRQ_EXTI10_15();
		break;
	}
}
void NVIC_Disable(uint8_t IRQ_num)
{
	switch(IRQ_num)
	{
	case 0:
		NVIC_Disable_IRQ_EXTI0();
		break;
	case 1:
		NVIC_Disable_IRQ_EXTI1();
		break;
	case 2:
		NVIC_Disable_IRQ_EXTI2();
		break;
	case 3:
		NVIC_Disable_IRQ_EXTI3();
		break;
	case 4:
		NVIC_Disable_IRQ_EXTI4();
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_Disable_IRQ_EXTI5_9();
		break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_Disable_IRQ_EXTI10_15();
		break;
	}
}
/* ===============================================
 * Private APIs Supported by "MCAL EXTI DRIVER"
 * ===============================================*/

/*
 * @Fn				-MCAL_EXTI_GPIO_DEINIT
 * @brief 			-Rest the external interrupt registers & NVIC corresponding IRQ mask
 * @retval 			-none
 * Note				-None
 */
void MCAL_EXTI_GPIO_DEINIT(void)
{
	EXTI->IMR 	=	0x0;
	EXTI->EMR 	=	0x0;
	EXTI->RTSR 	=	0x0;
	EXTI->FTSR 	=	0x0;
	EXTI->PR	=	0xFFFFFFFF;		//This bits are cleared by writing a ‘1’ into the bit.

	//Disable EXTI IRQ from NVIC
	NVIC_Disable_IRQ_EXTI0();
	NVIC_Disable_IRQ_EXTI1();
	NVIC_Disable_IRQ_EXTI2();
	NVIC_Disable_IRQ_EXTI3();
	NVIC_Disable_IRQ_EXTI4();
	NVIC_Disable_IRQ_EXTI5_9();
	NVIC_Disable_IRQ_EXTI10_15();
}

/*
 * @Fn				-MCAL_EXTI_GPIO_INI
 * @brief 			-Initialize the external interrupt GPIO pin configuration that includes Trigger_Edge,Enable/Disable EXTI on (IRQ mask and NVIC),and Set your ISR which will be called when IRQ happen
 * @param [in] 		-EXTI_Config: Pointer to EXTI_PinConfig_t structure that contains the configuration of specified EXTI
 * @retval 			-none
 * Note				-Mandatory Enable RCC clock for GPIO & AFIO
 */

void MCAL_EXTI_GPIO_INIT(EXTI_PinConfig_t* EXTI_Config)
{
	//1- configure EXTI GPIO pin as AF input >> input floating
	GPIO_PinConfig_t PinConfig;
	PinConfig.GPIO_PinNumber = EXTI_Config->EXTI_PIN.GPIO_PIN;
	PinConfig.GPIO_PinMODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(EXTI_Config->EXTI_PIN.GPIO_PORT, &PinConfig);
	//==============================================================================

	//2- configure AFIO to route between EXTI Line with PORT A/B/C/D
	uint8_t AFIO_EXTICR_Index = EXTI_Config->EXTI_PIN.EXTI_LineNumber/4;
	uint8_t AFIO_EXTICR_Bits_Position = (EXTI_Config->EXTI_PIN.EXTI_LineNumber%4)*4;
	//clear the desired 4 bits
	AFIO->EXTICR[AFIO_EXTICR_Index] &=~(0xF<<AFIO_EXTICR_Bits_Position);
	AFIO->EXTICR[AFIO_EXTICR_Index] |= (AFIO_GPIO_EXTI_MAPPING(EXTI_Config->EXTI_PIN.GPIO_PORT)<<AFIO_EXTICR_Bits_Position);
	//==============================================================================

	//3- Configure rising and falling Register
	//clear desired bits
	EXTI->RTSR &=~(1<<EXTI_Config->EXTI_PIN.EXTI_LineNumber);
	EXTI->FTSR &=~(1<<EXTI_Config->EXTI_PIN.EXTI_LineNumber);
	//select Trigger Edge type
	if(EXTI_Config->Trigger_Edge ==Rising_Edge)
	{
		EXTI->RTSR |=(1<<EXTI_Config->EXTI_PIN.EXTI_LineNumber);
	}
	else if(EXTI_Config->Trigger_Edge ==Falling_Edge)
	{
		EXTI->FTSR |=(1<<EXTI_Config->EXTI_PIN.EXTI_LineNumber);
	}
	else
	{
		EXTI->RTSR |=(1<<EXTI_Config->EXTI_PIN.EXTI_LineNumber);
		EXTI->FTSR |=(1<<EXTI_Config->EXTI_PIN.EXTI_LineNumber);
	}
	//==============================================================================

	//4-Set callback Function IRQ
	GPtr_IRQ_callBack[EXTI_Config->EXTI_PIN.EXTI_LineNumber] = EXTI_Config->Ptr_IRQ_callBack;
	//==============================================================================
	//5- Enable/Disable mask (Interrupt mask register (EXTI_IMR) & NVIC)
	if(EXTI_Config->IRQ_State == EXTI_IRQ_Enable)
	{
		EXTI->IMR|=(1<<EXTI_Config->EXTI_PIN.EXTI_LineNumber);
	}
	else
	{
		EXTI->IMR&=~(1<<EXTI_Config->EXTI_PIN.EXTI_LineNumber);
	}

}
/*
 * @Fn				-MCAL_EXTI_GPIO_UPDATE
 * @brief 			-Reinitialize the external interrupt GPIO pin configuration that includes Trigger_Edge,Enable/Disable EXTI on (IRQ mask and NVIC),and Set your ISR which will be called when IRQ happen
 * @param [in] 		-EXTI_Config: Pointer to EXTI_PinConfig_t structure that contains the configuration of specified EXTI
 * @retval 			-none
 * Note				-Mandatory Enable RCC clock for GPIO & AFIO
 */
void MCAL_EXTI_GPIO_UPDATE(EXTI_PinConfig_t* EXTI_Config)
{
	MCAL_EXTI_GPIO_INIT(EXTI_Config);
}


/* ===============================================
 * ISRs
 * ===============================================*/
void EXTI0_IRQHandler(void)
{
	//clear Pending register bit flag(cleared by writing a ‘1’ into the bit.)
	EXTI->PR|=(1<<0);
	//call the callback Function
	GPtr_IRQ_callBack[0]();
}
void EXTI1_IRQHandler(void)
{
	//clear Pending register bit flag(cleared by writing a ‘1’ into the bit.)
	EXTI->PR|=(1<<1);
	//call the callback Function
	GPtr_IRQ_callBack[1]();
}
void EXTI2_IRQHandler(void)
{
	//clear Pending register bit flag(cleared by writing a ‘1’ into the bit.)
	EXTI->PR|=(1<<2);
	//call the callback Function
	GPtr_IRQ_callBack[2]();
}
void EXTI3_IRQHandler(void)
{
	//clear Pending register bit flag(cleared by writing a ‘1’ into the bit.)
	EXTI->PR|=(1<<3);
	//call the callback Function
	GPtr_IRQ_callBack[3]();
}
void EXTI4_IRQHandler(void)
{
	//clear Pending register bit flag(cleared by writing a ‘1’ into the bit.)
	EXTI->PR|=(1<<4);
	//call the callback Function
	GPtr_IRQ_callBack[4]();
}
void EXTI9_5_IRQHandler(void)
{
	if(EXTI->PR & (1<<5)){ EXTI->PR|=(1<<5); GPtr_IRQ_callBack[5]();}
	else if(EXTI->PR & (1<<6)){ EXTI->PR|=(1<<6); GPtr_IRQ_callBack[6]();}
	else if(EXTI->PR & (1<<7)){ EXTI->PR|=(1<<7); GPtr_IRQ_callBack[7]();}
	else if(EXTI->PR & (1<<8)){ EXTI->PR|=(1<<8); GPtr_IRQ_callBack[8]();}
	else if(EXTI->PR & (1<<9)){ EXTI->PR|=(1<<9); GPtr_IRQ_callBack[9]();}
}
void EXTI15_10_IRQHandler (void)
{
	if(EXTI->PR & (1<<10)){ EXTI->PR|=(1<<10); GPtr_IRQ_callBack[10]();}
	else if(EXTI->PR & (1<<11)){ EXTI->PR|=(1<<11); GPtr_IRQ_callBack[11]();}
	else if(EXTI->PR & (1<<12)){ EXTI->PR|=(1<<12); GPtr_IRQ_callBack[12]();}
	else if(EXTI->PR & (1<<13)){ EXTI->PR|=(1<<13); GPtr_IRQ_callBack[13]();}
	else if(EXTI->PR & (1<<14)){ EXTI->PR|=(1<<14); GPtr_IRQ_callBack[14]();}
	else if(EXTI->PR & (1<<15)){ EXTI->PR|=(1<<15); GPtr_IRQ_callBack[15]();}

}
