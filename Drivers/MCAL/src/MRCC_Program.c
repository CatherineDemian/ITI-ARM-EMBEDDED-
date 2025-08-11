#include "STD_TYPES.H"
#include "BIT_MATH.h"

#include <MRCC_Config.h>
#include <MRCC_Interface.h>
#include <MRCC_Private.h>



void MRCC_voidInit(void)
{
	#if (SYSTEM_CLOCK==HSI_CLOCK)
		//HSI ON
	     RCC->CR|=(1<<HSION);
	    //Wait till HSI ready
		while(!GET_BIT(RCC->CR,HSIRDY));
		//Switch to HSI
		RCC->CFGR&=(MUSK<<SW0);
		RCC->CFGR|=(HSI_Oscillator<<SW0);
    #elif (SYSTEM_CLOCK==HSE_CLOCK)
		//Choose Between Mechanical clock or RC clock
		#if(HSE_OS==RC_CLOCK)
			RCC->CR|=(1<<HSEBYP);
		#elif (HSE_OS==Mechanical_CLOCK)
			RCC->CR&=(1<<HSEBYP);
		#endif
		//HSE ON
	    RCC->CR|=(1<<HSEON);
	    //Wait till HSE ready
		while(!GET_BIT(RCC->CR,HSERDY));
		//Switch to HSE
	    RCC->CFGR&=(MUSK<<SW0);
		RCC->CFGR|=(HSE_Oscillator<<SW0);
		//Disable HSI
		RCC->CR&=(1<<HSION);
	#endif
}

void MRCC_voidEnablePeripheralClock(System_Bus Copy_uddtBus,u32 Copy_u32Peripheral)
{
	if(Copy_u32Peripheral<32)
	{
		switch(Copy_uddtBus)
		{
			case AHB1_BUS: RCC->AHB1ENR|=(1<<Copy_u32Peripheral);        break;
			case AHB2_BUS: RCC->AHB2ENR|=(1<<Copy_u32Peripheral);        break;
			case APB1_BUS: RCC->APB1ENR|=(1<<Copy_u32Peripheral);        break;
			case APB2_BUS: RCC->APB2ENR|=(1<<Copy_u32Peripheral);        break;
		}
	}
	else
	{
		//Do Nothing
	}
}
void MRCC_voidDisablePeripheralClock(System_Bus Copy_uddtBus,u32 Copy_u32Peripheral)
{
		if(Copy_u32Peripheral<32)
	{
		switch(Copy_uddtBus)
		{
			case AHB1_BUS: RCC->AHB1ENR&=(1<<Copy_u32Peripheral);        break;
			case AHB2_BUS: RCC->AHB2ENR&=(1<<Copy_u32Peripheral);        break;
			case APB1_BUS: RCC->APB1ENR&=(1<<Copy_u32Peripheral);        break;
			case APB2_BUS: RCC->APB2ENR&=(1<<Copy_u32Peripheral);        break;
		}
	}
	else
	{
		//Do Nothing
	}	
}
