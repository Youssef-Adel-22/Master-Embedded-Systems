/*
 * STM32F103x6.h
 *
 *  Created on: Jun 22, 2023
 *      Author: Harby
 */

#ifndef INC_STM32F103X6_H_
#define INC_STM32F103X6_H_

//-----------------------------
//Includes
//-----------------------------
#include <stdint.h>
#include <stdlib.h>
//-----------------------------
//Base addresses for Memories
//-----------------------------
#define Flash_Memory_Base				0x08000000UL
#define System_Memory_Base				0x0FFFF000UL
#define SRAM_Memory_Base				0x20000000UL
#define Peripherals_Base				0x40000000UL
#define CortexM3_internal_periphelars	0xE0000000UL
//-----------------------------
//Base addresses for BUS Peripherals
//-----------------------------
//AHB BUS (main bus)
#define RCC_Base				0x40021000UL
//APB1 BUS

//APB2 BUS
#define AFIO_Base				0x40010000UL
#define EXTI_Base				0x40010400UL
//GPIO Port A,B Fully included in this package LQFB48
#define GPIOA_Base				0x40010800UL
#define GPIOB_Base				0x40010C00UL
//GPIO GPIO C,D Partial included in this package LQFB48
#define GPIOC_Base				0x40011000UL
#define GPIOD_Base				0x40011400UL

#define GPIOE_Base				0x40011800UL	//GPIO GPIO E NOT included in this package LQFB48
#define GPIOF_Base				0x40011C00UL	//GPIO GPIO F NOT included in this package LQFB48
#define GPIOG_Base				0x40012000UL 	//GPIO GPIO G NOT included in this package LQFB48

//NVIC Registers
#define NVIC_Base				0xE000E100UL
#define NVIC_ISER0				*((volatile uint32_t*)(NVIC_Base + 0x0))
#define NVIC_ISER1				*((volatile uint32_t*)(NVIC_Base + 0x4))
#define NVIC_ISER2				*((volatile uint32_t*)(NVIC_Base + 0x8))
#define NVIC_ICER0				*((volatile uint32_t*)(NVIC_Base + 0x80))
#define NVIC_ICER1				*((volatile uint32_t*)(NVIC_Base + 0x84))
#define NVIC_ICER2				*((volatile uint32_t*)(NVIC_Base + 0x88))
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:
//-*-*-*-*-*-*-*-*-*-*-*
//RCC Register
typedef struct
{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
}RCC_t;

//AFIO Register
typedef struct
{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR[4];
	volatile uint32_t RESERVED0;
	volatile uint32_t MAPR2;

}AFIO_t;

//EXTI Register
typedef struct
{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;

}EXTI_t;
//GPIO Register
typedef struct
{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;

}GPIO_t;
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*
//RCC
#define RCC ((RCC_t*) RCC_Base)
//EXTI
#define EXTI ((EXTI_t*)EXTI_Base)
//AFIO
#define AFIO ((AFIO_t*) AFIO_Base)
//GPIO
#define GPIOA ((GPIO_t*) GPIOA_Base)
#define GPIOB ((GPIO_t*) GPIOB_Base)
#define GPIOC ((GPIO_t*) GPIOC_Base)
#define GPIOD ((GPIO_t*) GPIOD_Base)
#define GPIOE ((GPIO_t*) GPIOE_Base)
#define GPIOG ((GPIO_t*) GPIOG_Base)

//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*
#define RCC_AFIO_CLK_EN()	(RCC->APB2ENR |=(1<<0))
#define RCC_GPIOA_CLK_EN()	(RCC->APB2ENR |=(1<<2))
#define RCC_GPIOB_CLK_EN()	(RCC->APB2ENR |=(1<<3))
#define RCC_GPIOC_CLK_EN()	(RCC->APB2ENR |=(1<<4))
#define RCC_GPIOD_CLK_EN()	(RCC->APB2ENR |=(1<<5))
#define RCC_GPIOE_CLK_EN()	(RCC->APB2ENR |=(1<<6))
#define RCC_GPIOF_CLK_EN()	(RCC->APB2ENR |=(1<<7))
#define RCC_GPIOG_CLK_EN()	(RCC->APB2ENR |=(1<<8))

//-*-*-*-*-*-*-*-*-*-*-*-
//NVIC Enable/Disable Macros:
//-*-*-*-*-*-*-*-*-*-*-*
#define NVIC_EN_IRQ_EXTI0()				(NVIC_ISER0|=(1<<6)) //IRQ6
#define NVIC_EN_IRQ_EXTI1()				(NVIC_ISER0|=(1<<7)) //IRQ7
#define NVIC_EN_IRQ_EXTI2()				(NVIC_ISER0|=(1<<8)) //IRQ8
#define NVIC_EN_IRQ_EXTI3()				(NVIC_ISER0|=(1<<9)) //IRQ9
#define NVIC_EN_IRQ_EXTI4()				(NVIC_ISER0|=(1<<10)) //IRQ10
#define NVIC_EN_IRQ_EXTI5_9()			(NVIC_ISER0|=(1<<23)) //IRQ23
#define NVIC_EN_IRQ_EXTI10_15()			(NVIC_ISER1|=(1<<8)) //IRQ40

#define NVIC_Disable_IRQ_EXTI0()		(NVIC_ICER0|=(1<<6)) //IRQ6
#define NVIC_Disable_IRQ_EXTI1()		(NVIC_ICER0|=(1<<7)) //IRQ7
#define NVIC_Disable_IRQ_EXTI2()		(NVIC_ICER0|=(1<<8)) //IRQ8
#define NVIC_Disable_IRQ_EXTI3()		(NVIC_ICER0|=(1<<9)) //IRQ9
#define NVIC_Disable_IRQ_EXTI4()		(NVIC_ICER0|=(1<<10)) //IRQ10
#define NVIC_Disable_IRQ_EXTI5_9()		(NVIC_ICER0|=(1<<23)) //IRQ23
#define NVIC_Disable_IRQ_EXTI10_15()	(NVIC_ICER1|=(1<<8)) //IRQ40
//-*-*-*-*-*-*-*-*-*-*-*-
//IVT
//-*-*-*-*-*-*-*-*-*-*-*
//EXTI_IRQ_NUMBER
#define EXTI0_IRQ 	6
#define EXTI1_IRQ 	7
#define EXTI2_IRQ 	8
#define EXTI3_IRQ 	9
#define EXTI4_IRQ	10
#define EXTI5_IRQ	23
#define EXTI6_IRQ	23
#define EXTI7_IRQ	23
#define EXTI8_IRQ	23
#define EXTI9_IRQ	23
#define EXTI10_IRQ 	40
#define EXTI11_IRQ 	40
#define EXTI12_IRQ 	40
#define EXTI13_IRQ 	40
#define EXTI14_IRQ 	40
#define EXTI15_IRQ 	40
//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*

#endif /* INC_STM32F103X6_H_ */
