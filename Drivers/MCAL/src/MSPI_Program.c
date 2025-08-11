/*
 * MSPI_Program.c
 *
 *  Created on: Jul 30, 2025
 *      Author: Catherine Nader
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <MSPI_Interface.h>

void MSPI_voidMasterInit()
{
	SPI1->CR1 |= (1<<SSM);
	SPI1->CR1 |= (1<<SSI);

	SPI1->CR1 |= (1<<MSTR);
	SPI1->CR1 |= (1<<CPOL);

	SPI1->CR1 |= (1<<SPE);


}

void MSPI_voidSlaveInit()
{
	SPI1->CR1 &= ~(1<<MSTR);
	SPI1->CR1 |= (1<<CPOL);
	SPI1->CR1 |= (1<<SPE);


}

u16 MSPI_u16Tranceive(u16 Copy_u16Data)
{
	while(!GET_BIT(SPI1->SR,TXE));
	SPI1->DR=Copy_u16Data;

	while(!GET_BIT(SPI1->SR,RXNE));
	return (u16)(SPI1->DR);

}
