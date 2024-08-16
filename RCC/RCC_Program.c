/*
 * RCC_Program.c
 *
 *  Created on: May 7, 2024
 *      Author: Yomna Awny Salh
 */

#include "RCC_Interface.h"




void RCC_Software_Rest(){

	RCC->BDCR |= (1<<BDRST);


}


void RCC_Init(void){
#if clk==HSE_Bybass

	RCC->CR |= (1<<HSEON);
	RCC->CR |= (1<<HSEBYP);
	while(!((RCC->CR &(1<< HSERDY))>>HSERDY));
	RCC->CFGR &=~(0b11 <<0);
	RCC->CFGR |= (0b01 <<0);


#elif clk==HSE_Crystal

	RCC->CR |= (1<<HSEON);
	while(!((RCC->CR &(1<<HSERDY ))>>HSERDY ));
	RCC->CFGR &=~(0b11 <<0);
	RCC->CFGR |= (0b01 <<0);
#elif clk==HSI

	RCC->CR |= (1<<0);
	while(!((RCC->CR &(1<< HSIRDY))>>1));
	RCC->CFGR &=~(0b11 <<0);
#else

#if PLLSLC==HSE
 //HSE 1 FOR PLL
RCC->CR |= (1<<PLLSRC);
#if Halfed==1

RCC->CR |= (1<<PLLSRC);
#else

RCC->CFGR &=~(1 <<PLLXTPRE);
#endif
#else //PLL SLC IS HSI
 // 0 FOR HSI IN PLL
RCC->CFGR &=~(1 <<PLLSRC);
#endif

switch(PLLMULL){
case 2:
 RCC->CFGR &=~(0b1111 <<PLLMULL1);
   break;
case 3:
	RCC->CFGR &=~(0b1111 <<PLLMULL1);
    RCC->CFGR |=(0b0001 <<PLLMULL1);
    break;
case 4:
	RCC->CFGR &=~(0b1111 <<PLLMULL1);
	RCC->CFGR |=(0b0010 <<PLLMULL1);
break;
case 5:
	RCC->CFGR &=~(0b1111 <<PLLMULL1);
	RCC->CFGR |=(0b0011 <<PLLMULL1);
case 6:
    RCC->CFGR &=~(0b1111 <<PLLMULL1);
    RCC->CFGR |=(0b0100 <<PLLMULL1);
break;
case 7:
	RCC->CFGR &=~(0b1111 <<PLLMULL1);
	RCC->CFGR |=(0b0101 <<PLLMULL1);
break;
case 8:
    RCC->CFGR &=~(0b1111 <<PLLMULL1);
    RCC->CFGR |=(0b0110 <<PLLMULL1);
   break;
case 9:
	RCC->CFGR &=~(0b1111 <<PLLMULL1);
    RCC->CFGR |=(0b0111 <<PLLMULL1);
    break;
case 10:
	RCC->CFGR &=~(0b1111 <<PLLMULL1);
	RCC->CFGR |=(0b1000 <<PLLMULL1);
break;
case 11:
	RCC->CFGR &=~(0b1111 <<PLLMULL1);
	RCC->CFGR |=(0b1001 <<PLLMULL1);
break;
case 12:
    RCC->CFGR &=~(0b1111 <<PLLMULL1);
	RCC->CFGR |=(0b1010 <<PLLMULL1);
   break;
case 13:
	RCC->CFGR &=~(0b1111 <<PLLMULL1);
	RCC->CFGR |=(0b1011<<PLLMULL1);
    break;
case 14:
	RCC->CFGR &=~(0b1111 <<PLLMULL1);
	RCC->CFGR |=(0b1100 <<PLLMULL1);
break;
case 15:
	RCC->CFGR &=~(0b1111 <<PLLMULL1);
	RCC->CFGR |=(0b1101 <<PLLMULL1);
break;
default:
	RCC->CFGR |=(0b1111 <<PLLMULL1);
}

    RCC->CR |= (1<<PLLON);
	while(!((RCC->CR &(1<< PLLRDY))>>PLLRDY));
	RCC->CFGR &=(0b10 <<0);
	RCC->CFGR &=~(0b11 <<0);
	RCC->CFGR |= (0b01 <<0);


#endif

	//to check
	while((RCC->CFGR & (0b11<<2))!=(RCC->CFGR & 0b11));

	//AHB Prescaler
	RCC->CFGR &=~(0b1111 <<4);
	RCC->CFGR |=(AHB_PSC <<PLLMULL1);

}

void RCC_Periph_Enable(AHB AHB_PER, APB1 APB1_PER, APB2 APB2_PER){

#if(Rcc_periph==AHB)
		RCC->AHBENR |= (1<<AHB_PER);
#elif(Rcc_periph==APB1)
		RCC->APB1ENR |= (1<<APB1_PER);
#else
		RCC->APB2ENR |= (1<<APB2_PER);
#endif
}

void RCC_Periph_Disable(AHB AHB_PER, APB1 APB1_PER, APB2 APB2_PER){

#if(Rcc_periph==AHB)
		RCC->AHBENR &= ~(1<<AHB_PER);
#elif(Rcc_periph==APB1)
	    RCC->APB1ENR &= ~(1<<APB1_PER);
#else
		RCC->APB2ENR&= ~(1<<APB2_PER);
#endif
}
