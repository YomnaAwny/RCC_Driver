/*
 * RCC_Regis.h
 *
 *  Created on: May 7, 2024
 *      Author: Dell
 */

#ifndef RCC_RCC_REGIS_H_
#define RCC_RCC_REGIS_H_

#include "STD_TYPES.h"


#define RCC_BASE_ADDR 0x40021000

typedef struct{
	u32 CR;
	u32 CFGR;
	u32 CIR;
	u32 APB2RSTR;
	u32 APB1RSTR;
	u32 AHBENR;
	u32 APB2ENR;
	u32 APB1ENR;
	u32 BDCR;
	u32 CSR;

}RCC_REGDEF;

#define RCC		(RCC_REGDEF *)RCC_BASE_ADDR

#endif /* RCC_RCC_REGIS_H_ */
