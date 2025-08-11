/*
 * MFLASH_Interface.h
 *
 *  Created on: Aug 5, 2025
 *      Author: Catherine Nader
 */

#ifndef MFLASH_INTERFACE_H_
#define MFLASH_INTERFACE_H_

#include <MFLASH_Config.h>
#include "MFLASH_Private.h"

typedef enum
{
Sector0,
Sector1,
Sector2,
Sector3,
Sector4,
Sector5

}Sector_t;


void MFMI_voidMassErase();
void MFMI_voidSectorErase(Sector_t Copy_uddtSectorNumber);
void MFMI_voidMultiSectorErase(Sector_t Copy_uddtSectorNumberStart,Sector_t Copy_uddtSectorNumberEnd);
void MFMI_voidProgramFlash(u32 Copy_u32Address,u16*Copy_pu16PTR, u8 Copy_u8DataLength);

#endif /* MFLASH_INTERFACE_H_ */
