/*
 * uart.c
 *
 *  Created on: Jul 23, 2025
 *      Author: Catherine Nader
 */

#include <MUART_Interface.h>

void HUART_voidInit(UART_t Copy_uddtUART)
{
	Uart_t* UARTx;
switch(Copy_uddtUART)
{

case 1: UARTx=UART_1; break;
case 2: UARTx=UART_2; break;
case 6: UARTx=UART_6; break;
default: break;
}

UARTx->CR1 &= ~(0X1FFF<<0);

UARTx->CR1|=(Over8<<15);

UARTx->CR1|=(wordlength<<12);
UARTx->CR1|=(WAKE<<11);
UARTx->CR1|=(PCE<<10);
UARTx->CR1|=(ParitySel<<9);
UARTx->CR1|=(PEIE<<8);
UARTx->CR1|=(TXEIE<<7);
UARTx->CR1|=(TCIE<<6);
UARTx->CR1|=(RXNEIE<<5);
UARTx->CR1|=(IDLEIE<<4);

UARTx->CR1|=(RWU<<1);
UARTx->CR1|=(SBK<<0);

UARTx->BRR = (BaudRate << 4) | (BaudRateFloat & 0xF);

UARTx->CR1|=(TE<<3);
UARTx->CR1|=(RE<<2);
UARTx->CR1|=(USARTENABLE<<13);

}
void HUART_voidWrite(UART_t Copy_uddtUART,u8 u8data)
{


	Uart_t* UARTx;
switch(Copy_uddtUART)
{

case 1: UARTx=UART_1; break;
case 2: UARTx=UART_2; break;
case 6: UARTx=UART_6; break;
default: break;
}

if((UARTx->CR1 & (TXEIE<<7))==0)
{
	UARTx->CR1|=(1<<7);
	}
while (!(UARTx->SR & (1 << 7))); //TXE FLAG
UARTx->DR = u8data;


}

u8 HUART_u8Read(UART_t Copy_uddtUART)
{
	Uart_t* UARTx;
switch(Copy_uddtUART)
{

case 1: UARTx=UART_1; break;
case 2: UARTx=UART_2; break;
case 6: UARTx=UART_6; break;
default: break;
}

if((UARTx->CR1 & (RXNEIE<<5))==0)
{
	UARTx->CR1|=(1<<5);
	}
while (!(UARTx->SR & (1 << 5))); //RXNE FLAG
return((u8)UARTx->DR);

}

void HUART_voidSendString(UART_t Copy_uddtUART, const char* string)
{
    while (*string!='\0')
    {
        HUART_voidWrite(Copy_uddtUART, *string++);
    }
}

