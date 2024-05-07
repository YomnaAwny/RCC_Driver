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


void RCC_Software_Rest(){};
void RCC_Init(u8 clk){};
void RCC_Periph_Enable(u8 reg,u8 periph){};
void RCC_Periph_Disable(u8 reg,u8 periph){};



#endif /* RCC_RCC_INTERFACE_H_ */
