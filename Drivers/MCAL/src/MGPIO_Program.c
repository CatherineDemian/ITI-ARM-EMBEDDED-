#include "STD_TYPES.H"
#include "BIT_MATH.h"
#include <MGPIO_Config.h>
#include <MGPIO_Interface.h>
#include <MGPIO_Private.h>


PIN_t oddpin;

//Setting the mode for each port mode is 	INPUT, OUTPUT, ALTERNATIVE FNC OR ANALOG
void MGPIO_voidSetMode(Port_t Copy_uddtPort,PIN_t Copy_uddtPin,Modes_t Copy_uddtMode)
{

	switch(Copy_uddtPort)
	{
	case PORTA: GPIOA->MODER &= ~(musk2bit<<Copy_uddtPin*2); GPIOA->MODER |= (Copy_uddtMode<<Copy_uddtPin*2); break;
	
	case PORTB: GPIOB->MODER &= ~(musk2bit<<Copy_uddtPin*2); GPIOB->MODER |= (Copy_uddtMode<<Copy_uddtPin*2); break;

	case PORTC: GPIOC->MODER &= ~(musk2bit<<Copy_uddtPin*2); GPIOC->MODER |= (Copy_uddtMode<<Copy_uddtPin*2); break;

	case PORTD: GPIOD->MODER &= ~(musk2bit<<Copy_uddtPin*2); GPIOD->MODER |= (Copy_uddtMode<<Copy_uddtPin*2); break;

	case PORTE: GPIOE->MODER &= ~(musk2bit<<Copy_uddtPin*2); GPIOE->MODER |= (Copy_uddtMode<<Copy_uddtPin*2); break;

	case PORTH: GPIOH->MODER &= ~(musk2bit<<Copy_uddtPin*2); GPIOH->MODER |= (Copy_uddtMode<<Copy_uddtPin*2); break;


	}
}

//SETTING THE OUTPUT AS SOURCE-DRAIN OR PUSHPULL AND CHOOSING THE SPEED WHICH IS 10MHZ 16 MHZ OR 50 MHZ
void MGPIO_voidSetOutputConfig(Port_t Copy_uddtPort,PIN_t Copy_uddtPin,Output_t Copy_uddtType,Speed_t Copy_uddtSpeed)
{


	if(Copy_uddtType==1)
		{
	switch(Copy_uddtPort)
	{



	case PORTA: GPIOA->OTYPER |= (1<<Copy_uddtPin); GPIOA->OSPEEDER &= ~(musk2bit<<Copy_uddtPin*2);  GPIOA->OSPEEDER |= (Copy_uddtSpeed<<Copy_uddtPin*2); break;

	case PORTB: GPIOB->OTYPER |= (1<<Copy_uddtPin); GPIOB->OSPEEDER &= ~(musk2bit<<Copy_uddtPin*2);  GPIOB->OSPEEDER |= (Copy_uddtSpeed<<Copy_uddtPin*2); break;

	case PORTC: GPIOC->OTYPER |= (1<<Copy_uddtPin); GPIOC->OSPEEDER &= ~(musk2bit<<Copy_uddtPin*2);  GPIOC->OSPEEDER |= (Copy_uddtSpeed<<Copy_uddtPin*2); break;

	case PORTD: GPIOD->OTYPER |= (1<<Copy_uddtPin); GPIOD->OSPEEDER &= ~(musk2bit<<Copy_uddtPin*2);  GPIOD->OSPEEDER |= (Copy_uddtSpeed<<Copy_uddtPin*2); break;

	case PORTE: GPIOE->OTYPER |= (1<<Copy_uddtPin); GPIOE->OSPEEDER &= ~(musk2bit<<Copy_uddtPin*2);  GPIOE->OSPEEDER |= (Copy_uddtSpeed<<Copy_uddtPin*2); break;

	case PORTH: GPIOH->OTYPER |= (1<<Copy_uddtPin); GPIOH->OSPEEDER &= ~(musk2bit<<Copy_uddtPin*2);   GPIOH->OSPEEDER |= (Copy_uddtSpeed<<Copy_uddtPin*2); break;
	}
		}
	
	else
	{
		switch(Copy_uddtPort)
			{


	case PORTA: GPIOA->OTYPER &= ~(1<<Copy_uddtPin); GPIOA->OSPEEDER &= ~(musk2bit<<Copy_uddtPin*2); GPIOA->OSPEEDER |= (Copy_uddtSpeed<<Copy_uddtPin*2); break;

	case PORTB: GPIOB->OTYPER &= ~(1<<Copy_uddtPin); GPIOB->OSPEEDER &= ~(musk2bit<<Copy_uddtPin*2); GPIOB->OSPEEDER |= (Copy_uddtSpeed<<Copy_uddtPin*2); break;

	case PORTC: GPIOC->OTYPER &= ~(1<<Copy_uddtPin); GPIOC->OSPEEDER &= ~(musk2bit<<Copy_uddtPin*2); GPIOC->OSPEEDER |= (Copy_uddtSpeed<<Copy_uddtPin*2); break;

	case PORTD: GPIOD->OTYPER &= ~(1<<Copy_uddtPin); GPIOD->OSPEEDER &= ~(musk2bit<<Copy_uddtPin*2); GPIOD->OSPEEDER |= (Copy_uddtSpeed<<Copy_uddtPin*2); break;

	case PORTE: GPIOE->OTYPER &= ~(1<<Copy_uddtPin); GPIOE->OSPEEDER &= ~(musk2bit<<Copy_uddtPin*2); GPIOE->OSPEEDER |= (Copy_uddtSpeed<<Copy_uddtPin*2); break;

	case PORTH: GPIOH->OTYPER &= ~(1<<Copy_uddtPin); GPIOH->OSPEEDER &= ~(musk2bit<<Copy_uddtPin*2); GPIOH->OSPEEDER |= (Copy_uddtSpeed<<Copy_uddtPin*2); break;
	}

	}
}

//SETTING THE OUTPUT DATA REGISTER
void MGPIO_voidSetPinValue(Port_t Copy_uddtPort,PIN_t Copy_uddtPin,PinValue_t Copy_uddtPinValue)
{
	if(Copy_uddtPinValue==1){
		switch(Copy_uddtPort)
		{
		case PORTA: GPIOA->ODR |= (1<<Copy_uddtPin); break;

		case PORTB: GPIOB->ODR |= (1<<Copy_uddtPin); break;

		case PORTC: GPIOC->ODR |= (1<<Copy_uddtPin); break;

		case PORTD: GPIOD->ODR |= (1<<Copy_uddtPin); break;

		case PORTE: GPIOE->ODR |= (1<<Copy_uddtPin); break;

		case PORTH: GPIOH->ODR |= (1<<Copy_uddtPin); break;
		}

		}

		else{

			switch(Copy_uddtPort)
			{
			case PORTA: GPIOA->ODR &= ~(1<<Copy_uddtPin); break;

			case PORTB: GPIOB->ODR &= ~(1<<Copy_uddtPin); break;

			case PORTC: GPIOC->ODR &= ~(1<<Copy_uddtPin); break;

			case PORTD: GPIOD->ODR &= ~(1<<Copy_uddtPin); break;

			case PORTE: GPIOE->ODR &= ~(1<<Copy_uddtPin); break;

			case PORTH: GPIOH->ODR &= ~(1<<Copy_uddtPin); break;
			}

			}
}

//SETTING THE BIT BANDING BITS
void MGPIO_voidSetPinValueAtomic(Port_t Copy_uddtPort,PIN_t Copy_uddtPin,PinValue_t Copy_uddtPinValue)
{

	if(Copy_uddtPin<16){
	switch(Copy_uddtPort)
	{
	u32 pin_locH=(1<<Copy_uddtPin);
	case PORTA: GPIOA->BSRR = pin_locH; break;
	
	case PORTB: GPIOB->BSRR = pin_locH; break;

	case PORTC: GPIOC->BSRR = pin_locH; break;

	case PORTD: GPIOD->BSRR = pin_locH; break;

	case PORTE: GPIOE->BSRR = pin_locH; break;

	case PORTH: GPIOH->BSRR = pin_locH; break;
	}

	}

	else{
		Copy_uddtPin+=16;
		u32 pin_locL=(1<<Copy_uddtPin);
		switch(Copy_uddtPort)
		{
		case PORTA: GPIOA->BSRR = pin_locL; break;

		case PORTB: GPIOB->BSRR = pin_locL; break;

		case PORTC: GPIOC->BSRR = pin_locL; break;

		case PORTD: GPIOD->BSRR = pin_locL; break;

		case PORTE: GPIOE->BSRR = pin_locL; break;

		case PORTH: GPIOH->BSRR = pin_locL; break;
		}

		}

	}

//SETTING THE INPUT CONFIG PULL UP OR PULL DOWN
void MGPIO_voidSetInputConfig(Port_t Copy_uddtPort,PIN_t Copy_uddtPin,Input_t Copy_uddtType)
{
	switch(Copy_uddtPort)
		{
		case PORTA: GPIOA->PUPDR &= ~(musk2bit<<Copy_uddtPin*2); GPIOA->PUPDR |= (Copy_uddtType<<Copy_uddtPin*2); break;

		case PORTB: GPIOB->PUPDR &= ~(musk2bit<<Copy_uddtPin*2); GPIOB->PUPDR |= (Copy_uddtType<<Copy_uddtPin*2); break;

		case PORTC: GPIOC->PUPDR &= ~(musk2bit<<Copy_uddtPin*2); GPIOC->PUPDR |= (Copy_uddtType<<Copy_uddtPin*2); break;

		case PORTD: GPIOD->PUPDR &= ~(musk2bit<<Copy_uddtPin*2); GPIOD->PUPDR |= (Copy_uddtType<<Copy_uddtPin*2); break;

		case PORTE: GPIOE->PUPDR &= ~(musk2bit<<Copy_uddtPin*2); GPIOE->PUPDR |= (Copy_uddtType<<Copy_uddtPin*2); break;

		case PORTH: GPIOH->PUPDR &= ~(musk2bit<<Copy_uddtPin*2); GPIOH->PUPDR |= (Copy_uddtType<<Copy_uddtPin*2); break;
		}
}
//READING THE PIN
u8 MGPIO_voidGetPinValue(Port_t Copy_uddtPort,PIN_t Copy_uddtPin)
{
	u8 pinvalue;
	switch(Copy_uddtPort)
			{
			case PORTA: pinvalue=GET_BIT(GPIOA->IDR,Copy_uddtPin); break;

			case PORTB: pinvalue=GET_BIT(GPIOB->IDR,Copy_uddtPin); break;

			case PORTC: pinvalue=GET_BIT(GPIOC->IDR,Copy_uddtPin); break;

			case PORTD: pinvalue=GET_BIT(GPIOD->IDR,Copy_uddtPin); break;

			case PORTE: pinvalue=GET_BIT(GPIOE->IDR,Copy_uddtPin); break;

			case PORTH: pinvalue=GET_BIT(GPIOH->IDR,Copy_uddtPin); break;

			}
	return pinvalue;
}

//SETTING THE ALTERNATIVE FNC HIGH AND LOW
void MGPIO_voidSetAlternativeConfig(Port_t Copy_uddtPort,PIN_t Copy_uddtPin,Alternative_t Copy_uddtType)

{    if(Copy_uddtPin<8)
{
	switch(Copy_uddtPort)
		{
		case PORTA: GPIOA->AFRL &= ~(musk4bit<<Copy_uddtPin*4); GPIOA->AFRL |= (Copy_uddtType<<Copy_uddtPin*4); break;

		case PORTB: GPIOB->AFRL &= ~(musk4bit<<Copy_uddtPin*4); GPIOB->AFRL |= (Copy_uddtType<<Copy_uddtPin*4); break;

		case PORTC: GPIOC->AFRL &= ~(musk4bit<<Copy_uddtPin*4); GPIOC->AFRL |= (Copy_uddtType<<Copy_uddtPin*4); break;

		case PORTD: GPIOD->AFRL &= ~(musk4bit<<Copy_uddtPin*4); GPIOD->AFRL |= (Copy_uddtType<<Copy_uddtPin*4); break;

		case PORTE: GPIOE->AFRL &= ~(musk4bit<<Copy_uddtPin*4); GPIOE->AFRL |= (Copy_uddtType<<Copy_uddtPin*4); break;

		case PORTH: GPIOH->AFRL &= ~(musk4bit<<Copy_uddtPin*4); GPIOH->AFRL |= (Copy_uddtType<<Copy_uddtPin*4); break;
		}
}

else
{
	Copy_uddtPin-=8;
	switch(Copy_uddtPort)
		{

		case PORTA: GPIOA->AFRH &= ~(musk4bit<<Copy_uddtPin*4); GPIOA->AFRH |= (Copy_uddtType<<Copy_uddtPin*4); break;

		case PORTB: GPIOB->AFRH &= ~(musk4bit<<Copy_uddtPin*4); GPIOB->AFRH |= (Copy_uddtType<<Copy_uddtPin*4); break;

		case PORTC: GPIOC->AFRH &= ~(musk4bit<<Copy_uddtPin*4); GPIOC->AFRH |= (Copy_uddtType<<Copy_uddtPin*4); break;

		case PORTD: GPIOD->AFRH &= ~(musk4bit<<Copy_uddtPin*4); GPIOD->AFRH |= (Copy_uddtType<<Copy_uddtPin*4); break;

		case PORTE: GPIOE->AFRH &= ~(musk4bit<<Copy_uddtPin*4); GPIOE->AFRH |= (Copy_uddtType<<Copy_uddtPin*4); break;

		case PORTH: GPIOH->AFRH &= ~(musk4bit<<Copy_uddtPin*4); GPIOH->AFRH |= (Copy_uddtType<<Copy_uddtPin*4); break;
		}
}

}


