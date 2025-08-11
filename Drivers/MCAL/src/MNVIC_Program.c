#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include <MNVIC_Config.h>
#include <MNVIC_Interface.h>
#include <MNVIC_Private.h>



void MNVIC_voidEnable(u8 Copy_u8Position)
{
	NVIC->ISER[Copy_u8Position/REG_DIV]|=(1<<(Copy_u8Position%REG_DIV)); 
}
void MNVIC_voidDisable(u8 Copy_u8Position)
{
	NVIC->ICER[Copy_u8Position/REG_DIV]|=(1<<(Copy_u8Position%REG_DIV));
}
void MNVIC_voidSetPendingFlag(u8 Copy_u8Position)
{
	NVIC->ISPR[Copy_u8Position/REG_DIV]|=(1<<(Copy_u8Position%REG_DIV));
}
void MNVIC_voidClearPendingFlag(u8 Copy_u8Position)
{
	NVIC->ICPR[Copy_u8Position/REG_DIV]|=(1<<(Copy_u8Position%REG_DIV));
}
u8 MNVIC_u8ReadingActiveState(u8 Copy_u8Position)
{
	return GET_BIT(NVIC->IABR[Copy_u8Position/REG_DIV],(Copy_u8Position%REG_DIV));
}

void MNVIC_voidSetGroupMode(NVIC_Group_t Copy_uddtGroupMode)
{
   u32 AIRCR_Reg;
   AIRCR_Reg |= VECTKEY<<16;
   AIRCR_Reg |=  Copy_uddtGroupMode<<8;
	SCB_AIRCR =  AIRCR_Reg;
}

void MNVIC_voidSetInterruptPeriority(u8 Copy_u8Position,u8 Copy_u8Group,u8 Copy_u8SubGroub)
{
	u8 prigroup_val =(SCB_AIRCR<<8)&0x7;
	u8 Group_Bits=7-prigroup_val;
	u8 SubGroup_Bits=prigroup_val-3;
    u8 priority = (Copy_u8Group << SubGroup_Bits) | (SubGroup_Bits);
    NVIC->IPR[Copy_u8Position] = (priority << 4);



}


