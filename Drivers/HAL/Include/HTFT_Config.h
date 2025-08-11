/*
 * HTFT_Config.h
 *
 *  Created on: Jul 31, 2025
 *      Author: Catherine Nader
 */

#ifndef HTFT_CONFIG_H_
#define HTFT_CONFIG_H_

#define TFT_RST PIN0
#define TFT_CTRL PIN1
#define TFT_PORT PORTA

#define SLEEP_OUT 0x11
#define COLOR_MODE 0x3A
#define DISPLAY_ON 0x29
#define SET_X 0x2A
#define SET_Y 0x2B
#define SCREEN_WRITE 0x2C


#define RGB565 0x05

#define START_X_B0 0
#define START_X_B1 0
#define END_X_B0 0
#define END_X_B1 127

#define START_Y_B0 0
#define START_Y_B1 0
#define END_Y_B0 0
#define END_Y_B1 159

#define IMG_SIZE 20480

#endif /* HTFT_CONFIG_H_ */
