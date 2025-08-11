/*
 * HUART_Config.h
 *
 *  Created on: Jul 23, 2025
 *      Author: Catherine Nader
 */

#ifndef MUART_CONFIG_H_
#define MUART_CONFIG_H_

#define wordlength Bits8
#define Over8 over16
#define PCE Disable
#define ParitySel OddParity
#define USARTENABLE USARTEn
#define RE Enable
#define TE Enable
#define PEIE Disable
#define TXEIE Enable
#define TCIE Disable
#define RXNEIE Enable
#define IDLEIE Disable
#define WAKE IdleLine
#define RWU Active
#define SBK NoBreak

#define BaudRate 104
#define BaudRateFloat 3

#endif /* HUART_CONFIG_H_ */
