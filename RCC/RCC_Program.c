/*
 * RCC_Program.c
 *
 *  Created on: May 7, 2024
 *      Author: Yomna Awny Salh
 */

#include "RCC_Interface.h"

#define BDRST 16


void RCC_Software_Rest(){

	SET_BIT(RCC->BDCR,BDRST);
	//RCC->CR=0x00000083;
}

void RCC_Init(u8 clk){
#if(clk==0)
	SET_BIT(RCC->CR,HSEBYP);
	SET_BIT(RCC->CR,HSEON);
#elif(clk==1)
	SET_BIT(RCC->CR,HSEON);
#elif (clk==2)
	SLC_HSI();
#else

#ifdef HSE
CLR_BIT(RCC->CR,PLLON);
SET_BIT(RCC->CFGR,PLLSRC);
#ifdef Halfed
SET_BIT(RCC->CFGR,PLLXTPRE);
#else
CLR_BIT(RCC->CFGR,PLLXTPRE);
#endif
#else
CLR_BIT(RCC->CR,PLLON);
CLR_BIT(RCC->CFGR,PLLSRC);
#endif

	SLC_PLL();
#endif
}

void RCC_Periph_Enable(u8 reg,u8 periph){

#if(reg==0)
		SET_BIT(RCC->AHBENR,periph);
#elif(reg==1)
		SET_BIT(RCC->APB1ENR,periph);
#else
		SET_BIT(RCC->APB2ENR,periph);
#endif
}

void RCC_Periph_Disable(u8 reg,u8 periph){

#if(reg==0)
		CLR_BIT(RCC->AHBENR,periph);
#elif(reg==1)
		CLR_BIT(RCC->APB1ENR,periph);
#else
		CLR_BIT(RCC->APB2ENR,periph);
#endif
}
