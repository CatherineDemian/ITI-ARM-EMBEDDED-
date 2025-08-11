/*
 * HTFT_Program.c
 *
 *  Created on: Jul 31, 2025
 *      Author: Catherine Nader
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include <MGPIO_Interface.h>
#include <MSTK_Interface.h>
#include <MSPI_Interface.h>
#include <HTFT_Config.h>
#include <HTFT_Interface.h>







void HTFT_voidInit()
{
	MGPIO_voidSetMode(TFT_PORT,TFT_RST,OUTPUT);
	MGPIO_voidSetOutputConfig(TFT_PORT,TFT_RST,Push_Pull,Low_Speed);

	MGPIO_voidSetMode(TFT_PORT,TFT_CTRL,OUTPUT);
	MGPIO_voidSetOutputConfig(TFT_PORT,TFT_CTRL,Push_Pull,Low_Speed);

	//Reset Sequence

	MGPIO_voidSetPinValue(TFT_PORT,TFT_RST,HIGH);
	MSTK_voidDelayus(100);
	MGPIO_voidSetPinValue(TFT_PORT,TFT_RST,LOW);
	MSTK_voidDelayus(1);
	MGPIO_voidSetPinValue(TFT_PORT,TFT_RST,HIGH);
	MSTK_voidDelayus(100);
	MGPIO_voidSetPinValue(TFT_PORT,TFT_RST,LOW);
	MSTK_voidDelayus(100);
	MGPIO_voidSetPinValue(TFT_PORT,TFT_RST,HIGH);
	MSTK_voidDelayms(120);

	//Sleep Out
	HTFT_voidWriteCommand(SLEEP_OUT);
	MSTK_voidDelayms(10);

	//SELECT COLOR MODE
	HTFT_voidWriteCommand(COLOR_MODE);
	HTFT_voidWriteData(RGB565);

	//DISPLAY ON
	HTFT_voidWriteCommand(DISPLAY_ON);
	}
void HTFT_voidWriteCommand(u8 Copy_u8CMD)
{

//WRITE command
	MGPIO_voidSetPinValue(TFT_PORT,TFT_CTRL,LOW);
	(void)MSPI_u16Tranceive(Copy_u8CMD);


}
void HTFT_voidWriteData(u8 Copy_u8DATA)
{
	//WRITE DATA
	MGPIO_voidSetPinValue(TFT_PORT,TFT_CTRL,HIGH);
	(void)MSPI_u16Tranceive(Copy_u8DATA);

}
void HTFT_voidDisplay(const u16*Copy_pu16PTR)
{
u16 Local_u16Iterator;
u8 Local_u8HighPart;
u8 Local_u8LowPart;


//SET X
HTFT_voidWriteCommand(SET_X);
HTFT_voidWriteData(START_X_B0);
HTFT_voidWriteData(START_X_B1);
HTFT_voidWriteData(END_X_B0);
HTFT_voidWriteData(END_X_B1);

//SET Y
HTFT_voidWriteCommand(SET_Y);
HTFT_voidWriteData(START_Y_B0);
HTFT_voidWriteData(START_Y_B1);
HTFT_voidWriteData(END_Y_B0);
HTFT_voidWriteData(END_Y_B1);

//WRITE ON SCREEN
HTFT_voidWriteCommand(SCREEN_WRITE);
for(Local_u16Iterator=0;Local_u16Iterator<IMG_SIZE;Local_u16Iterator++)
{

	Local_u8LowPart=(u8)(Copy_pu16PTR[Local_u16Iterator]);
	Local_u8HighPart=(u8)(Copy_pu16PTR[Local_u16Iterator]>>8);
	HTFT_voidWriteData(Local_u8HighPart);
	HTFT_voidWriteData(Local_u8LowPart);
}
}

