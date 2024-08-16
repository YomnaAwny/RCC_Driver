/*
 * RCC_Config.h
 *
 *  Created on: May 7, 2024
 *      Author: Dell
 */

#ifndef RCC_RCC_CONFIG_H_
#define RCC_RCC_CONFIG_H_

#define BDRST 16
//HSE
#define HSEBYP 18
#define HSERDY 17 //NEW
#define HSEON 16
//HSI
#define HSION 0
#define HSIRDY 1
//PLL
#define PLLON 24
#define PLLRDY 25
#define PLLSRC 16
#define PLLXTPRE 17
#define PLLMULL1 18
#define PLLMULL2 19
#define PLLMULL3 20
#define PLLMULL4 21
#define PLLSLC  HSE //HSE or HSI
#define Halfed 1 //1 if hse is halfed
#define PLLMULL 4 //bet 2 and 16
//clk select
#define clk HSE_Crystal //HSE_Bybass,HSE_Crystal,HSI,PLL

//AHB Prescaler
#define PSC_1   0b0000
#define PSC_2   0b1000
#define PSC_4   0b1001
#define PSC_8   0b1010
#define PSC_16  0b1011
#define PSC_64  0b1100
#define PSC_128  0b1101
#define PSC_256  0b1110
#define PSC_512  0b1111

#define AHB_PSC  PSC_8


//periph select for enable
#define Rcc_periph AHB //AHB,APB1,APB2

typedef enum
{DMA1EN,
DMA2EN,
SRAMEN,
FLITFEN=4,
CRCEN=6,
FSMCEN=8,
SDIOEN=10} AHB;


typedef enum
{AFIOEN,IOPAEN=2,
IOPBEN,IOPCEN,
IOPDEN,IOPEEN,
IOPFEN,IOPGEN,
ADC1EN,ADC2EN,
TIM1EN,SPI1EN,
TIM8EN,USART1EN,
ADC3EN,TIM9EN=19,
TIM10EN,TIM11EN}APB2;


typedef enum
{TIM2EN,TIM3EN,TIM4EN,
TIM5EN,TIM6EN,TIM7EN,
TIM12EN,TIM13EN,TIM14EN,
WWDGEN=11,SPI2EN=14,SPI3EN,
USART2EN=17,USART3EN,USART4EN,
USART5EN,I2C1EN,I2C2EN,
USBEN,CANEN=25,BKPEN=27,PWREN,DACEN}APB1;



#endif /* RCC_RCC_CONFIG_H_ */
