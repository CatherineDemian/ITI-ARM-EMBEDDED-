/*
 * MINT_Private.h
 *
 *  Created on: Jul 15, 2025
 *      Author: Catherine Nader
 */

#ifndef MINT_PRIVATE_H_
#define MINT_PRIVATE_H_


#define SYSCFG_BASE_ADDRESS 0x40013800
#define EXTI_BASE_ADDRESS  0x40013C00
#define TIMER1_CC_BASE_ADDRESS 0x000000AC


typedef struct
{
u32 MEMRMP;
u32 PMC;
u32 EXTICR[4];
u32 Reserved1[2];
u32 CMPCR;
}SYSCFG_t;

typedef struct
{
	u32 IMR;
	u32 EMR;
	u32 RTSR;
	u32 FTSR;
	u32 SWIER;
	u32 PR;
}EXTI_t;


typedef enum
{
EXTI_Falling,
EXTI_Rising,
EXTI_NoChange
}EXTI_Trigger_t;

#define SYSCFG ((volatile SYSCFG_t*)SYSCFG_BASE_ADDRESS)
#define EXTI ((volatile EXTI_t*)EXTI_BASE_ADDRESS)

#define SYSDIV 4
#define SYSMask 15

#endif /* MINT_PRIVATE_H_ */
