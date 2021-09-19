/*
 * LCD.c
 *
 *  Created on: Aug 7, 2021
 *      Author: ahmed
 */


#include "LCD.h"

void LCD_init() {
	Dio_write_PORT(Rw, LOW);
	_delay_ms(20);

	LCD_cmd(0x33);
	LCD_cmd(0x32); 	/* Send for 4 bit initialization of LCD  */
	LCD_cmd(0x28); 	// Select 4 Bit Mode, 5*7 dots
	LCD_cmd(0x0C);	// Display On, Cursor Blinking
	LCD_cmd(0x06);	// Entry Mode Increment cursor to right
	LCD_cmd(0x01);	// Clear Display
	_delay_ms(2);
}

void LCD_cmd(uint8 cmd) {
	Dio_write_PORT(Rs, LOW);
	Dio_write_PORT(Rw, LOW);

	Dio_write_PORT(D7, GET_BIT(cmd, 7));
	Dio_write_PORT(D6, GET_BIT(cmd, 6));
	Dio_write_PORT(D5, GET_BIT(cmd, 5));
	Dio_write_PORT(D4, GET_BIT(cmd, 4));
	Dio_write_PORT(E, HIGH);
	_delay_us(10);
	Dio_write_PORT(E, LOW);
	_delay_us(200);

	Dio_write_PORT(D7, GET_BIT(cmd, 3));
	Dio_write_PORT(D6, GET_BIT(cmd, 2));
	Dio_write_PORT(D5, GET_BIT(cmd, 1));
	Dio_write_PORT(D4, GET_BIT(cmd, 0));
	Dio_write_PORT(E, HIGH);
	_delay_us(10);
	Dio_write_PORT(E, LOW);
	_delay_us(200);
}



void LCD_data_write(uint8 data) {
	Dio_write_PORT(Rs, HIGH);
	Dio_write_PORT(Rw, LOW);

	Dio_write_PORT(D4, GET_BIT(data, 4));
	Dio_write_PORT(D5, GET_BIT(data, 5));
	Dio_write_PORT(D6, GET_BIT(data, 6));
	Dio_write_PORT(D7, GET_BIT(data, 7));

	Dio_write_PORT(E, HIGH);
	_delay_us(10);
	Dio_write_PORT(E, LOW);
	_delay_us(200);

	Dio_write_PORT(D4, GET_BIT(data, 0));
	Dio_write_PORT(D5, GET_BIT(data, 1));
	Dio_write_PORT(D6, GET_BIT(data, 2));
	Dio_write_PORT(D7, GET_BIT(data, 3));

	Dio_write_PORT(E, HIGH);
	_delay_us(10);
	Dio_write_PORT(E, LOW);
	_delay_us(200);
}


void LCD_data_read(uint16 data) {
	Dio_write_PORT(Rs, HIGH);
	Dio_write_PORT(Rw, HIGH);

	Dio_write_PORT(D4, GET_BIT(data, 4));
	Dio_write_PORT(D5, GET_BIT(data, 5));
	Dio_write_PORT(D6, GET_BIT(data, 6));
	Dio_write_PORT(D7, GET_BIT(data, 7));

	Dio_write_PORT(E, HIGH);
	_delay_us(10);
	Dio_write_PORT(E, LOW);
	_delay_us(200);

	Dio_write_PORT(D4, GET_BIT(data, 0));
	Dio_write_PORT(D5, GET_BIT(data, 1));
	Dio_write_PORT(D6, GET_BIT(data, 2));
	Dio_write_PORT(D7, GET_BIT(data, 3));

	Dio_write_PORT(E, HIGH);
	_delay_us(10);
	Dio_write_PORT(E, LOW);
	_delay_us(200);
}

void LCD_Custom_Char(void) {

	LCD_cmd(0x40);

	// heart shape:
	LCD_data_write(0b00000);
	LCD_data_write(0b00000);
	LCD_data_write(0b01010);
	LCD_data_write(0b11111);
	LCD_data_write(0b11111);
	LCD_data_write(0b01110);
	LCD_data_write(0b00100);
	LCD_data_write(0b00000);

	//Smile shape:
	LCD_data_write(0b00000);
	LCD_data_write(0b01010);
	LCD_data_write(0b01010);
	LCD_data_write(0b00000);
	LCD_data_write(0b10001);
	LCD_data_write(0b01110);
	LCD_data_write(0b00000);
	LCD_data_write(0b00000);

	//Wink:
	LCD_data_write(0b00000);
	LCD_data_write(0b00000);
	LCD_data_write(0b00011);
	LCD_data_write(0b11011);
	LCD_data_write(0b00000);
	LCD_data_write(0b10001);
	LCD_data_write(0b01110);
	LCD_data_write(0b00000);

	//Thumb up:
	LCD_data_write(0b00000);
	LCD_data_write(0b00000);
	LCD_data_write(0b00011);
	LCD_data_write(0b00011);
	LCD_data_write(0b00011);
	LCD_data_write(0b11111);
	LCD_data_write(0b11111);
	LCD_data_write(0b11111);
}

void LCD_GoTo(uint8 column, uint8 row) {

	if(column == 0) {
		LCD_cmd(0x80 | row);
	}else if(column == 1) {
		LCD_cmd(0xC0 | row);
	}

}


void LCD_String(uint8 *string) {

	for(int i = 0; string[i] != '\0'; i++) {


		LCD_data_write(string[i]);
		_delay_us(100);
	}
}

void CLR_LCD() {
	LCD_cmd(0x01);
	_delay_ms(2);
	LCD_cmd(0x80);
}

void Rtrn_Home_LCD() {
	LCD_cmd(0x02);
	_delay_us(2);
}
