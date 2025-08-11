/*
 * HSTP_Program.c
 *
 *  Created on: Aug 3, 2025
 *      Author: Catherine Nader
 */

#include "BIT_MATH.h"
#include "HSTP_Interface.h"
#include "MGPIO_Interface.h"

void HSTP_voidInit(void)
{

	MGPIO_voidSetMode(HSTP_u8_SDI_PORT,HSTP_u8_SDI_PIN,OUTPUT);
	MGPIO_voidSetMode(HSTP_u8_SHIFT_PORT,HSTP_u8_SHIFT_PIN,OUTPUT);
	MGPIO_voidSetMode(HSTP_u8_LATCH_PORT,HSTP_u8_LATCH_PIN,OUTPUT);

	MGPIO_voidSetOutputConfig(HSTP_u8_SDI_PORT,HSTP_u8_SDI_PIN,Push_Pull,Low_Speed);
	MGPIO_voidSetOutputConfig(HSTP_u8_SHIFT_PORT,HSTP_u8_SHIFT_PIN,Push_Pull,Low_Speed);
	MGPIO_voidSetOutputConfig(HSTP_u8_LATCH_PORT,HSTP_u8_LATCH_PIN,Push_Pull,Low_Speed);

	}

void HSTP_voidShiftData(u8 Copy_u8Data)
{

    for (s8 i = 7; i >= 0; i--)  // MSB first (change to i=0 to 7 for LSB first)
    {
        u8 bit = GET_BIT(Copy_u8Data, i);

        // Set the data pin (SDI)
        MGPIO_voidSetPinValue(HSTP_u8_SDI_PORT, HSTP_u8_SDI_PIN, bit);

        // Pulse the shift clock (SHCP)
        MGPIO_voidSetPinValue(HSTP_u8_SHIFT_PORT, HSTP_u8_SHIFT_PIN, HIGH);
        MSTK_voidDelayms(10);
        MGPIO_voidSetPinValue(HSTP_u8_SHIFT_PORT, HSTP_u8_SHIFT_PIN, LOW);

    }

	}
void HSTP_voidSendData(void)
{
		MGPIO_voidSetPinValue(HSTP_u8_LATCH_PORT,HSTP_u8_LATCH_PIN,LOW);
		MSTK_voidDelayms(10);
	MGPIO_voidSetPinValue(HSTP_u8_LATCH_PORT,HSTP_u8_LATCH_PIN,HIGH);


}
