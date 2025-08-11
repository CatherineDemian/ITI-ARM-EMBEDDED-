/*
 * MINT_Interface.h
 *
 *  Created on: Jul 15, 2025
 *      Author: Catherine Nader
 */

#ifndef MINT_INTERFACE_H_
#define MINT_INTERFACE_H_

#include "STD_TYPES.H"
#include "BIT_MATH.h"
#include <MINT_Private.h>

typedef enum
{
 EXTI_LINE0,
 EXTI_LINE2,
 EXTI_LINE3,
 EXTI_LINE4,
 EXTI_LINE5,
 EXTI_LINE6,
 EXTI_LINE7,
 EXTI_LINE8,
 EXTI_LINE9,
 EXTI_LINE10,
 EXTI_LINE11,
 EXTI_LINE12,
 EXTI_LINE13,
 EXTI_LINE14,
 EXTI_LINE15
} EXTILINE_t;

typedef enum
{
	EXTI_PORT_A,
	EXTI_PORT_B,
	EXTI_PORT_C,
	EXTI_PORT_D,
	EXTI_PORT_E,
	EXTI_PORT_H

}EXTI_PORT_t;


void void_SetInterrupt(EXTILINE_t copyuddtLine,EXTI_PORT_t copyuddtPort);
void MEXTI_voidDisable(EXTILINE_t copyuddtLine);
void MEXTI_voidEnable(EXTILINE_t copyuddtLine);
void MEXTI_voidSetTrigger(EXTILINE_t copyuddtLine,EXTI_Trigger_t copyuddtTrigger);
void EXTI0_voidCallBack(void(*ptr)(void));
void EXTI0_IRQHandler();
void EXTI10_voidCallBack(void(*ptr)(void));
void EXTI10_IRQHandler();


#endif /* MINT_INTERFACE_H_ */
