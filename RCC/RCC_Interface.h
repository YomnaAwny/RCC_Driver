/*
 * RCC_Interface.h
 *
 *  Created on: May 7, 2024
 *      Author: Dell
 */

#ifndef RCC_RCC_INTERFACE_H_
#define RCC_RCC_INTERFACE_H_

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "RCC_Regis.h"
#include "RCC_Config.h"


void RCC_Software_Rest();
void RCC_Init(void);
void RCC_Periph_Enable(AHB AHB_PER, APB1 APB1_PER, APB2 APB2_PER);
void RCC_Periph_Disable(AHB AHB_PER, APB1 APB1_PER, APB2 APB2_PER);



#endif /* RCC_RCC_INTERFACE_H_ */
