/*
 * RCC_Regis.h
 *
 *  Created on: May 7, 2024
 *      Author: Yomna Awmy Salh
 */

#ifndef RCC_RCC_REGIS_H_
#define RCC_RCC_REGIS_H_


#define RCC_BASE_ADDR 0x40021000
#define RCC_CR (u32 *)(RCC_BASE_ADDR+0x00)
#define RCC_CFGR (u32 *)(RCC_BASE_ADDR+0x04)
#define RCC_CIR (u32 *)(RCC_BASE_ADDR+0x08)
#define RCC_APB2RSTR (u32 *)(RCC_BASE_ADDR+0x0C)
#define RCC_APB1RSTR (u32 *)(RCC_BASE_ADDR+0x10)
#define RCC_AHBENR (u32 *)(RCC_BASE_ADDR+0x14)
#define RCC_APB2ENR (u32 *)(RCC_BASE_ADDR+0x18)
#define RCC_APB1ENR (u32 *)(RCC_BASE_ADDR+0x1C)
#define RCC_BDCR (u32 *)(RCC_BASE_ADDR+0x20)
#define RCC_CSR (u32 *)(RCC_BASE_ADDR+0x24)

/*typedef struct{
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

#define RCC		(RCC_REGDEF *)RCC_BASE_ADDR*/

#endif /* RCC_RCC_REGIS_H_ */
