/*
 * MFLASH_Private.h
 *
 *  Created on: Aug 5, 2025
 *      Author: Catherine Nader
 */

#ifndef MFLASH_PRIVATE_H_
#define MFLASH_PRIVATE_H_

#define FMI_BASE_ADDRESS (0x40023C00)

typedef struct
{
	u32 ACR;
	u32 KEYR;
	u32 OPTKEYR;
	u32 SR;
	u32 CR;
	u32 OPTCR;
}FMI_t;


#define FMI ((volatile FMI_t*)FMI_BASE_ADDRESS)

#define KEY1 0x45670123
#define KEY2  0xCDEF89AB
#define OPTKEY1  0x08192A3B
#define OPTKEY2  0x4C5D6E7F

#define BUSY 16

/* CR Register Bits */
#define PG         0
#define SER        1
#define MER        2
#define SNB        3
#define PSIZE      8
#define STRT       16
#define LOCK       31


#define MASK_SIZE 3
#define MASK_SECTOR 15


#endif /* MFLASH_PRIVATE_H_ */
