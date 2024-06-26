/*
 * RCC_Config.h
 *
 *  Created on: May 7, 2024
 *      Author: Yomna Awmy Salh
 */

#ifndef RCC_RCC_CONFIG_H_
#define RCC_RCC_CONFIG_H_

#define HSEBYP 18
#define HSEON 16
#define HSION 0
#define PLLON 24
#define PLLSRC 16
#define PLLXTPRE 17
#define PLLMUL1 18
#define PLLMUL2 19
#define PLLMUL3 20
#define PLLMUL4 21

#define HSE
#define Halfed
#define MULL 4


enum RCC_Periph{AHB,APB1,APB2};
enum CLKSLC{HSE_Bybass,HSE_Crystal,HSI,PLL};
enum AHB{DMA1EN,DMA2EN,SRAMEN,FLITFEN=4,CRCEN=6,FSMCEN=8,SDIOEN=10};
enum APB2{AFIOEN,IOPAEN=2,IOPBEN,IOPCEN,IOPDEN,IOPEEN,IOPFEN,IOPGEN,
		ADC1EN,ADC2EN,TIM1EN,SPI1EN,TIM8EN,USART1EN,ADC3EN,TIM9EN=19,TIM10EN,TIM11EN};
enum APB1{TIM2EN,TIM3EN,TIM4EN,TIM5EN,TIM6EN,TIM7EN,TIM12EN,TIM13EN
		,TIM14EN,WWDGEN=11,SPI2EN=14,SPI3EN,USART2EN=17,USART3EN,USART4EN,
		USART5EN,I2C1EN,I2C2EN,USBEN,CANEN=25,BKPEN=27,PWREN,DACEN};

#define SLC_HSE_BYBASS()(SET_BIT(RCC->CR,HSEBYP); SET_BIT(RCC->CR,HSEON))
#define SLC_HSE_CRYSTAL()(SET_BIT(RCC->CR,HSEON))
#define SLC_HSI()(SET_BIT(RCC->CR,HSION))
#define SLC_PLL()(SET_BIT(RCC->CR,PLLON))


#endif /* RCC_RCC_CONFIG_H_ */
