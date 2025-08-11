/*
 * MSPI_Interface.h
 *
 *  Created on: Jul 30, 2025
 *      Author: Catherine Nader
 */

#ifndef MSPI_INTERFACE_H_
#define MSPI_INTERFACE_H_

#include <MSPI_Config.h>
#include <MSPI_Private.h>


void MSPI_voidMasterInit();
void MSPI_voidSlaveInit();
u16 MSPI_u16Tranceive(u16 Copy_u16Data);



#endif /* MSPI_INTERFACE_H_ */
