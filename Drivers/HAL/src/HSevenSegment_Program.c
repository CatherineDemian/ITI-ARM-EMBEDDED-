/*
 * SevenSegment.c
 *
 *  Created on: Jul 16, 2025
 *      Author: Catherine Nader
 */
#include "BIT_MATH.h"
#include "STD_TYPES.H"
#include <HSevenSegment_Interface.h>
#include <MGPIO_Interface.h>
#include <MRCC_Interface.h>


void HSevenSegment_voidInit(u8 port_no)
{


MGPIO_voidSetMode(port_no,PIN0,OUTPUT); //A
MGPIO_voidSetOutputConfig(port_no,PIN0,Push_Pull,Low_Speed);


MGPIO_voidSetMode(port_no,PIN1,OUTPUT); //B
MGPIO_voidSetOutputConfig(port_no,PIN1,Push_Pull,Low_Speed);

MGPIO_voidSetMode(port_no,PIN2,OUTPUT); //C
MGPIO_voidSetOutputConfig(port_no,PIN2,Push_Pull,Low_Speed);

MGPIO_voidSetMode(port_no,PIN3,OUTPUT); //D
MGPIO_voidSetOutputConfig(port_no,PIN3,Push_Pull,Low_Speed);

MGPIO_voidSetMode(port_no,PIN4,OUTPUT); //E
MGPIO_voidSetOutputConfig(port_no,PIN4,Push_Pull,Low_Speed);

MGPIO_voidSetMode(port_no,PIN5,OUTPUT); //F
MGPIO_voidSetOutputConfig(port_no,PIN5,Push_Pull,Low_Speed);

MGPIO_voidSetMode(port_no,PIN6,OUTPUT); //G
MGPIO_voidSetOutputConfig(port_no,PIN6,Push_Pull,Low_Speed);

MGPIO_voidSetMode(port_no,PIN7,OUTPUT); //DP
MGPIO_voidSetOutputConfig(port_no,PIN7,Push_Pull,Low_Speed);

}

void HSevenSegment_voidNumber(u8 u8_number,u8 port_no)
{

	switch(u8_number)
	{

	case 0:
		MGPIO_voidSetPinValue(port_no,PIN0,HIGH);
		MGPIO_voidSetPinValue(port_no,PIN1,HIGH);
		MGPIO_voidSetPinValue(port_no,PIN2,HIGH);
		MGPIO_voidSetPinValue(port_no,PIN3,HIGH);
		MGPIO_voidSetPinValue(port_no,PIN4,HIGH);
		MGPIO_voidSetPinValue(port_no,PIN5,HIGH);
		MGPIO_voidSetPinValue(port_no,PIN6,LOW);
		MGPIO_voidSetPinValue(port_no,PIN7,LOW);


		break;

	case 1:
		MGPIO_voidSetPinValue(port_no,PIN0,LOW);
		MGPIO_voidSetPinValue(port_no,PIN1,HIGH);
		MGPIO_voidSetPinValue(port_no,PIN2,HIGH);
		MGPIO_voidSetPinValue(port_no,PIN3,LOW);
		MGPIO_voidSetPinValue(port_no,PIN4,LOW);
		MGPIO_voidSetPinValue(port_no,PIN5,LOW);
		MGPIO_voidSetPinValue(port_no,PIN6,LOW);
		MGPIO_voidSetPinValue(port_no,PIN7,LOW);
		break;
	case 2:
		MGPIO_voidSetPinValue(port_no,PIN0,HIGH);
		MGPIO_voidSetPinValue(port_no,PIN1,HIGH);
		MGPIO_voidSetPinValue(port_no,PIN2,LOW);
		MGPIO_voidSetPinValue(port_no,PIN3,HIGH);
		MGPIO_voidSetPinValue(port_no,PIN4,HIGH);
		MGPIO_voidSetPinValue(port_no,PIN5,LOW);
		MGPIO_voidSetPinValue(port_no,PIN6,HIGH);
		MGPIO_voidSetPinValue(port_no,PIN7,LOW);

		break;

	case 3:
		MGPIO_voidSetPinValue(port_no,PIN0,HIGH);
		MGPIO_voidSetPinValue(port_no,PIN1,HIGH);
		MGPIO_voidSetPinValue(port_no,PIN2,HIGH);
		MGPIO_voidSetPinValue(port_no,PIN3,HIGH);
		MGPIO_voidSetPinValue(port_no,PIN4,LOW);
		MGPIO_voidSetPinValue(port_no,PIN5,LOW);
		MGPIO_voidSetPinValue(port_no,PIN6,HIGH);
		MGPIO_voidSetPinValue(port_no,PIN7,LOW);
		break;

	case 4:
		MGPIO_voidSetPinValue(port_no,PIN0,LOW);
		MGPIO_voidSetPinValue(port_no,PIN1,HIGH);
		MGPIO_voidSetPinValue(port_no,PIN2,HIGH);
		MGPIO_voidSetPinValue(port_no,PIN3,LOW);
		MGPIO_voidSetPinValue(port_no,PIN4,LOW);
		MGPIO_voidSetPinValue(port_no,PIN5,HIGH);
		MGPIO_voidSetPinValue(port_no,PIN6,HIGH);
		MGPIO_voidSetPinValue(port_no,PIN7,LOW);
		break;

	case 5:
		MGPIO_voidSetPinValue(port_no,PIN0,HIGH);
		MGPIO_voidSetPinValue(port_no,PIN1,LOW);
		MGPIO_voidSetPinValue(port_no,PIN2,HIGH);
		MGPIO_voidSetPinValue(port_no,PIN3,HIGH);
		MGPIO_voidSetPinValue(port_no,PIN4,LOW);
		MGPIO_voidSetPinValue(port_no,PIN5,HIGH);
		MGPIO_voidSetPinValue(port_no,PIN6,HIGH);
		MGPIO_voidSetPinValue(port_no,PIN7,LOW);
		break;

	case 6:
		MGPIO_voidSetPinValue(port_no,PIN0,HIGH);
		MGPIO_voidSetPinValue(port_no,PIN1,LOW);
		MGPIO_voidSetPinValue(port_no,PIN2,HIGH);
		MGPIO_voidSetPinValue(port_no,PIN3,HIGH);
		MGPIO_voidSetPinValue(port_no,PIN4,HIGH);
		MGPIO_voidSetPinValue(port_no,PIN5,HIGH);
		MGPIO_voidSetPinValue(port_no,PIN6,HIGH);
		MGPIO_voidSetPinValue(port_no,PIN7,LOW);

		break;
	case 7:
		MGPIO_voidSetPinValue(port_no,PIN0,HIGH);
		MGPIO_voidSetPinValue(port_no,PIN1,HIGH);
		MGPIO_voidSetPinValue(port_no,PIN2,HIGH);
		MGPIO_voidSetPinValue(port_no,PIN3,LOW);
		MGPIO_voidSetPinValue(port_no,PIN4,LOW);
		MGPIO_voidSetPinValue(port_no,PIN5,LOW);
		MGPIO_voidSetPinValue(port_no,PIN6,LOW);
		MGPIO_voidSetPinValue(port_no,PIN7,LOW);

		break;

	case 8:
		MGPIO_voidSetPinValue(port_no,PIN0,HIGH);
		MGPIO_voidSetPinValue(port_no,PIN1,HIGH);
		MGPIO_voidSetPinValue(port_no,PIN2,HIGH);
		MGPIO_voidSetPinValue(port_no,PIN3,HIGH);
		MGPIO_voidSetPinValue(port_no,PIN4,HIGH);
		MGPIO_voidSetPinValue(port_no,PIN5,HIGH);
		MGPIO_voidSetPinValue(port_no,PIN6,HIGH);
		MGPIO_voidSetPinValue(port_no,PIN7,LOW);


		break;

	case 9:
		MGPIO_voidSetPinValue(port_no,PIN0,HIGH);
		MGPIO_voidSetPinValue(port_no,PIN1,HIGH);
		MGPIO_voidSetPinValue(port_no,PIN2,HIGH);
		MGPIO_voidSetPinValue(port_no,PIN3,HIGH);
		MGPIO_voidSetPinValue(port_no,PIN4,LOW);
		MGPIO_voidSetPinValue(port_no,PIN5,HIGH);
		MGPIO_voidSetPinValue(port_no,PIN6,HIGH);
		MGPIO_voidSetPinValue(port_no,PIN7,LOW);


	break;
	default:
		break;

	}

}

