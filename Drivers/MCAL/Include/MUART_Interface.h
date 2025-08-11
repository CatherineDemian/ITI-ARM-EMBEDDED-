/*
 * uart_Interface.h
 *
 *  Created on: Jul 23, 2025
 *      Author: Catherine Nader
 */

#ifndef MUART_INTERFACE_H_
#define MUART_INTERFACE_H_

#include "STD_TYPES.H"
#include "BIT_MATH.h"
#include "MUART_config.h"
#include "MUART_Private.h"


void HUART_voidInit(UART_t Copy_uddtUART);
void HUART_voidWrite(UART_t Copy_uddtUART,u8 u8data);
u8 HUART_u8Read(UART_t Copy_uddtUART);
void HUART_voidSendString(UART_t Copy_uddtUART, const char* string);



#endif /* HUART_INTERFACE_H_ */
