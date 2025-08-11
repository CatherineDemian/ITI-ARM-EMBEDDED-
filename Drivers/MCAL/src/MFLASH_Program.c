/*
 * MFLASH_Program.c
 *
 *  Created on: Aug 5, 2025
 *      Author: Catherine Nader
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <MFLASH_Interface.h>

void MFMI_voidMassErase()
{

	//wait for busy flag
	while(GET_BIT(FMI->SR,BUSY)==1);
	//unlock cr REG
	if(GET_BIT(FMI->CR,LOCK)==1)
	{
		FMI->KEYR=KEY1;
		FMI->KEYR=KEY2;
	}
	//SELECT MASS ERASE
FMI->CR=(1<<MER);
//Start Operation
FMI->CR=(1<<STRT);
//wait on busy flag
	while(GET_BIT(FMI->SR,BUSY)==1);
//disable mass erase
FMI->CR&=~(1<<MER);


	}
void MFMI_voidSectorErase(Sector_t Copy_uddtSectorNumber)
{

	//wait for busy flag
	while(GET_BIT(FMI->SR,BUSY)==1);
	//unlock cr REG
	if(GET_BIT(FMI->CR,LOCK)==1)
	{
		FMI->KEYR=KEY1;
		FMI->KEYR=KEY2;
	}
	//CLEAR SECTOR
	FMI->CR &= ~(MASK_SECTOR<<SNB);
	//SELECT SECTOR
	FMI->CR |= (Copy_uddtSectorNumber<<SNB);


	//SELECT SECTOR ERASE
FMI->CR=(1<<SER);
//Start Operation
FMI->CR=(1<<STRT);
//wait on busy flag
	while(GET_BIT(FMI->SR,BUSY)==1);
//disable SECTOR erase
FMI->CR&=~(1<<SER);

}
void MFMI_voidMultiSectorErase(Sector_t Copy_uddtSectorNumberStart,Sector_t Copy_uddtSectorNumberEnd)
{
	u8 Local_u8Iterator=0;
	for(Local_u8Iterator=Copy_uddtSectorNumberStart;Local_u8Iterator<=Copy_uddtSectorNumberEnd;Local_u8Iterator++)
	{
		MFMI_voidSectorErase(Local_u8Iterator);

	}

	}
void MFMI_voidProgramFlash(u32 Copy_u32Address,u16*Copy_pu16PTR, u8 Copy_u8DataLength)
{
	while(GET_BIT(FMI->SR,BUSY)==1);
		//unlock cr REG
		if(GET_BIT(FMI->CR,LOCK)==1)
		{
			FMI->KEYR=KEY1;
			FMI->KEYR=KEY2;
		}

		//select width to be programmed
		FMI->CR &= ~(MASK_SIZE<<PSIZE);
		FMI->CR |=(1<<PSIZE);

		for(u8 Local_u8Iterator=0;Local_u8Iterator<Copy_u8DataLength;Local_u8Iterator++)
		{
			//select program made
			FMI->CR|=(1<<PG);
			*((volatile u16*)Copy_u32Address)=Copy_pu16PTR[Local_u8Iterator];
			Copy_u32Address+=2;
			//wait busy flag
			while(GET_BIT(FMI->SR,BUSY)==1);

			//disable program mode
			FMI->CR&=~(1<<PG);

		}

	}

