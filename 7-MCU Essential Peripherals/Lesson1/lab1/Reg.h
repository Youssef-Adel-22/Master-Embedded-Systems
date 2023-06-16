/*
 * Reg.h
 *
 *  Created on: Jun 9, 2023
 *      Author: Harby
 */

#ifndef REG_H_
#define REG_H_

// init Functions
void SystemClock_init(void);
void GPIO_init(void);

//RCC Register
//Bit 0 HSION: Internal high-speed clock enable
//0: internal 8 MHz RC oscillator OFF
//1: internal 8 MHz RC oscillator ON
typedef union {
	uint32_t RC_all;
	struct {
		uint32_t  HSI_ON:1;
		uint32_t  HSI_RDY:1;
		uint32_t  :1;
		uint32_t   HSITRIM:5;
		uint32_t  HSICAL:8;
		uint32_t  HSE_ON:1;
		uint32_t  HSE_RDY:1;
		uint32_t  HSE_BYP:1;
		uint32_t  CSS_ON:1;
		uint32_t  :4;
		uint32_t  PLL_ON:1;
		uint32_t  PLL_RDY:1;
		uint32_t  :6;
	}RC_bits;
}RC_reg;
typedef union {
	uint32_t CFGR_all;
	struct {
		uint32_t  SW:2;
		uint32_t  SWS:2;
		uint32_t  HPRE:4;
		uint32_t  PPRE1:3;
		uint32_t  PPRE2:3;
		uint32_t  ADCPRE:2;
		uint32_t  PLL_SRC:1;
		uint32_t  PLL_XTPRE:1;
		uint32_t  PLL_MUL:4;
		uint32_t  USB_PRE:1;
		uint32_t  :1;
		uint32_t  MOC:3;
		uint32_t  :5;
	}CFGR_bits;
}CFGR_reg;
typedef union {
	uint32_t APB2ENR_all;
	struct {
		uint32_t  AFIO_EN:1;
		uint32_t  :1;
		uint32_t  IOPA_EN:1;
		uint32_t  IOPB_EN:1;
		uint32_t  IOPC_EN:1;
		uint32_t  IOPD_EN:1;
		uint32_t  IOPE_EN:1;
		uint32_t  IOPF_EN:1;
		uint32_t  IOPG_EN:1;
		uint32_t  ADC1_EN:1;
		uint32_t  ADC2_EN:1;
		uint32_t  TIM1_EN:1;
		uint32_t  SPI1_EN:1;
		uint32_t  TIM8_EN:1;
		uint32_t  USART1_EN:1;
		uint32_t  ADC3_EN:1;
		uint32_t  :3;
		uint32_t  TIM9_EN:1;
		uint32_t  TIM10_EN:1;
		uint32_t  TIM11_EN:1;
		uint32_t  :10;
	}APB2ENR_bits;
}APB2ENR_reg;
typedef union {
	uint32_t EXTI_IMR_all;
	struct {
		uint32_t  MR0:1;
		uint32_t  MR1:1;
		uint32_t  MR2:1;
		uint32_t  MR3:1;
		uint32_t  MR4:1;
		uint32_t  MR5:1;
		uint32_t  MR6:1;
		uint32_t  MR7:1;
		uint32_t  MR8:1;
		uint32_t  MR9:1;
		uint32_t  MR10:1;
		uint32_t  MR11:1;
		uint32_t  MR12:1;
		uint32_t  MR13:1;
		uint32_t  MR14:1;
		uint32_t  MR15:1;
		uint32_t  MR16:1;
		uint32_t  MR17:1;
		uint32_t  MR18:1;
		uint32_t  MR19:1;
		uint32_t  :12;
	}EXTI_IMR_bits;
}EXTI_IMR_reg;

typedef union {
	uint32_t EXTI_RTSR_all;
	struct {
		uint32_t  TR0:1;
		uint32_t  TR1:1;
		uint32_t  TR2:1;
		uint32_t  TR3:1;
		uint32_t  TR4:1;
		uint32_t  TR5:1;
		uint32_t  TR6:1;
		uint32_t  TR7:1;
		uint32_t  TR8:1;
		uint32_t  TR9:1;
		uint32_t  TR10:1;
		uint32_t  TR11:1;
		uint32_t  TR12:1;
		uint32_t  TR13:1;
		uint32_t  TR14:1;
		uint32_t  TR15:1;
		uint32_t  TR16:1;
		uint32_t  TR17:1;
		uint32_t  TR18:1;
		uint32_t  TR19:1;
		uint32_t  :12;
	}EXTI_RTSR_bits;
}EXTI_RTSR_reg;
#endif /* REG_H_ */
typedef union {
	uint32_t IDR_all;
	struct {
		uint32_t  IDR0:1;
		uint32_t  IDR1:1;
		uint32_t  IDR2:1;
		uint32_t  IDR3:1;
		uint32_t  IDR4:1;
		uint32_t  IDR5:1;
		uint32_t  IDR6:1;
		uint32_t  IDR7:1;
		uint32_t  IDR8:1;
		uint32_t  IDR9:1;
		uint32_t  IDR10:1;
		uint32_t  IDR11:1;
		uint32_t  IDR12:1;
		uint32_t  IDR13:1;
		uint32_t  IDR14:1;
		uint32_t  IDR15:1;

		uint32_t  :16;
	}IDR_bits;
}GPIO_IDR_reg;
typedef union {
	uint32_t ODR_all;
	struct {
		uint32_t  ODR0:1;
		uint32_t  ODR1:1;
		uint32_t  ODR2:1;
		uint32_t  ODR3:1;
		uint32_t  ODR4:1;
		uint32_t  ODR5:1;
		uint32_t  ODR6:1;
		uint32_t  ODR7:1;
		uint32_t  ODR8:1;
		uint32_t  ODR9:1;
		uint32_t  ODR10:1;
		uint32_t  ODR11:1;
		uint32_t  ODR12:1;
		uint32_t  ODR13:1;
		uint32_t  ODR14:1;
		uint32_t  ODR15:1;

		uint32_t  :16;
	}ODR_bits;
}GPIO_ODR_reg;

