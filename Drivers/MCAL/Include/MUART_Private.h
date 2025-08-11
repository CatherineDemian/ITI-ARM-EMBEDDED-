/*
 * HUART_Private.h
 *
 *  Created on: Jul 23, 2025
 *      Author: Catherine Nader
 */

#ifndef MUART_PRIVATE_H_
#define MUART_PRIVATE_H_


typedef struct
{
u32 SR;
u32 DR;
u32 BRR;
u32 CR1;
u32 CR2;
u32 CR3;
u32 GTPR;
}Uart_t;

typedef enum
{
	UART1=1,
	UART2=2,
	UART6=6
}UART_t;

//OVER8 bit 15
#define over16 0
#define over8 1

//USART ENABLE
#define USARTDis 0
#define USARTEn 1

//M 12 bit for data
#define Bits8 0
#define Bits9 1

//Parity Selection bit 9
#define OddParity 0
#define EvenParity 1

#define Disable 0
#define Enable 1

//RECEIVER WAKEUP
#define Active 0
#define Mute 1

//SendBreak
#define NoBreak 0
#define Break 1

//wake
#define IdleLine 0
#define AddressMark 1

#define UART1_BASE_ADDRESS  0x40011000
#define UART_1 ((volatile Uart_t*)UART1_BASE_ADDRESS)

#define UART2_BASE_ADDRESS  0x40004400
#define UART_2 ((volatile Uart_t*)UART2_BASE_ADDRESS)


#define UART6_BASE_ADDRESS  0x40011400
#define UART_6 ((volatile Uart_t*)UART6_BASE_ADDRESS)


#endif /* HUART_PRIVATE_H_ */
