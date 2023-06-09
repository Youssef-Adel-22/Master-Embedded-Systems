/*
 * Reg.h
 *
 *  Created on: Jun 9, 2023
 *      Author: Harby
 */

#ifndef REG_H_
#define REG_H_

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
#endif /* REG_H_ */
