#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <HLEDMATRIX_Config.h>
#include <HLEDMATRIX_Interface.h>
#include <MGPIO_Interface.h>
#include <MSTK_Interface.h>


void HLEDMATRIX_voidInit()
{
	u8 Local_u8Iterator=0;
	for(Local_u8Iterator=0;Local_u8Iterator<13;Local_u8Iterator++)
	{
		MGPIO_voidSetMode(PORTA,Local_u8Iterator,OUTPUT);
		MGPIO_voidSetOutputConfig(PORTA,Local_u8Iterator,Push_Pull,Low_Speed);
	}
	for(Local_u8Iterator=0;Local_u8Iterator<3;Local_u8Iterator++)
	{
		MGPIO_voidSetMode(PORTB,Local_u8Iterator,OUTPUT);
		MGPIO_voidSetOutputConfig(PORTB,Local_u8Iterator,Push_Pull,Low_Speed);
	}
}
static void HLEDMATRIX_voidSetRawValue(u8 Copy_u8RawVal)
{
	u8 Local_u8Iterator=0;
	for(Local_u8Iterator=0;Local_u8Iterator<8;Local_u8Iterator++)
	{
		MGPIO_voidSetPinValue(PORTA,Local_u8Iterator,GET_BIT(Copy_u8RawVal,Local_u8Iterator));
	}
}
static void HLEDMATRIX_voidDeactivateAllCol()
{
	u8 Local_u8Iterator=0;
	for(Local_u8Iterator=8;Local_u8Iterator<13;Local_u8Iterator++)
	{
		MGPIO_voidSetPinValue(PORTA,Local_u8Iterator,HIGH);
	}
	for(Local_u8Iterator=0;Local_u8Iterator<3;Local_u8Iterator++)
	{
		MGPIO_voidSetPinValue(PORTB,Local_u8Iterator,HIGH);
	}
}
void HLEDMATRIX_u8Display(u8*Copy_pu8Arr)
{
	u8 Local_u8Iterator=0;
	for(Local_u8Iterator=0;Local_u8Iterator<5;Local_u8Iterator++)
	{
		//set row value
		HLEDMATRIX_voidSetRawValue(Copy_pu8Arr[Local_u8Iterator]);
		//Activate col
		MGPIO_voidSetPinValue(PORTA,PIN8+Local_u8Iterator,LOW);
		//delay=2500usec
		MSTK_voidDelayus(2500);
		//Deactivate cols
		HLEDMATRIX_voidDeactivateAllCol();
	}
	for(Local_u8Iterator=0;Local_u8Iterator<3;Local_u8Iterator++)
	{
		//set row value
		HLEDMATRIX_voidSetRawValue(Copy_pu8Arr[Local_u8Iterator+5]);
		//Activate col
		MGPIO_voidSetPinValue(PORTB,PIN0+Local_u8Iterator,LOW);
		//delay=2500usec
		MSTK_voidDelayus(2500);
		//Deactivate cols
		HLEDMATRIX_voidDeactivateAllCol();
	}
}
