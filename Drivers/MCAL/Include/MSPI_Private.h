/*
 * MSPI_Private.h
 *
 *  Created on: Jul 30, 2025
 *      Author: Catherine Nader
 */

#ifndef MSPI_PRIVATE_H_
#define MSPI_PRIVATE_H_


#define SPI_BASE_ADDRESS (0x40013000)

typedef struct
{

u32 CR1;
u32 CR2;
u32 SR;
u32 DR;
u32 CPCPR;
u32 RXCRCR;
u32 TXCRCR;
u32 I2SCFGR;
u32 I2SPT;


}MSPI_t;


#define SPI1 ((volatile MSPI_t*)SPI_BASE_ADDRESS)


#define DEF 11
#define SSM 9
#define SSI 8
#define LSBFIRST 7
#define SPE 6
#define MSTR 2
#define CPOL 1
#define CPHA 0

#define TXE 1
#define RXNE 0





#endif /* MSPI_PRIVATE_H_ */
