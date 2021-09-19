/*
 * LCD.h
 *
 *  Created on: Aug 7, 2021
 *      Author: ahmed
 */

#ifndef HAL_LCD_LCD_H_
#define HAL_LCD_LCD_H_

#include "../../STD_Types.h"
#include "../../BIT_MATH.h"
#include "../../MCAL/Dio/Dio.h"
#include <util/delay.h>

void LCD_init();
void LCD_cmd(uint8 cmd);
void LCD_data_write(uint8 data);
void LCD_Custom_Char(void);
void LCD_GoTo(uint8 column, uint8 row);
void LCD_data_read(uint16 data);
void LCD_String(uint8 *string);
void CLR_LCD();

#endif /* HAL_LCD_LCD_H_ */
