/*
 * MINT_Program.c
 *
 *  Created on: Jul 15, 2025
 *      Author: Catherine Nader
 */

#include <MINT_Interface.h>
#include "STD_TYPES.h"



static void(*GlobalPTR_PtrEXTI0)(void)= NULL;
static void(*GlobalPTR_PtrEXTI10)(void)= NULL;

void void_SetInterrupt(EXTILINE_t copyuddtLine,EXTI_PORT_t copyuddtPort)
{

SYSCFG->EXTICR[copyuddtLine/SYSDIV]&= ~(SYSMask<<(copyuddtLine%SYSDIV)*4);
SYSCFG->EXTICR[copyuddtLine/SYSDIV] |= (copyuddtPort<<(copyuddtLine%SYSDIV)*4);
}

void MEXTI_voidEnable(EXTILINE_t copyuddtLine)
{
	EXTI->IMR |=(1<<copyuddtLine);
}

void MEXTI_voidDisable(EXTILINE_t copyuddtLine)
{
	EXTI->IMR &= ~(1<<copyuddtLine);
}

void MEXTI_voidSetTrigger(EXTILINE_t copyuddtLine,EXTI_Trigger_t copyuddtTrigger)
{
switch(copyuddtTrigger)
{
case EXTI_Falling:

	EXTI->RTSR &= ~(1<<copyuddtLine);
	EXTI->FTSR |= (1<<copyuddtLine);
	break;
case EXTI_Rising:
	EXTI->	FTSR &= ~(1<<copyuddtLine);
	EXTI->RTSR |= (1<<copyuddtLine);
	break;

case EXTI_NoChange:

	EXTI->RTSR |= (1<<copyuddtLine);
	EXTI->FTSR |= (1<<copyuddtLine);
	break;
default:
	break;
}

}

void EXTI0_voidCallBack(void(*ptr)(void))
{

	GlobalPTR_PtrEXTI0=ptr;
}

void EXTI0_IRQHandler()
{

if(GlobalPTR_PtrEXTI0!=NULL)
{
	GlobalPTR_PtrEXTI0();
	EXTI->PR|=(1<<0); //clear pending reg by setting 1
}

}
void EXTI10_voidCallBack(void(*ptr)(void))
{

	GlobalPTR_PtrEXTI10=ptr;
}

void EXTI15_10_IRQHandler()
{

if(GlobalPTR_PtrEXTI10!=NULL)
{
	GlobalPTR_PtrEXTI10();
	EXTI->PR|=(1<<10); //clear pending reg by setting 1
}

}
