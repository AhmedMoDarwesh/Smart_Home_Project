/*
 * Dio_Types.h
 *
 *  Created on: Aug 3, 2021
 *      Author: ahmed
 */

#ifndef MCAL_DIO_DIO_TYPES_H_
#define MCAL_DIO_DIO_TYPES_H_

#include "../../STD_Types.h"

typedef enum{
	LOW,
	HIGH
}LEVEL;

typedef enum{
	INPUT,
	OUTPUT
}Dir;

typedef enum{
	PORT_A,
	PORT_B,
	PORT_C,
	PORT_D,
}Dio_PORT_Type;

typedef enum{
	PIN_0,
	PIN_1,
	PIN_2,
	PIN_3,
	PIN_4,
	PIN_5,
	PIN_6,
	PIN_7
}Dio_PIN_Type;


typedef enum{

	//PORT_A
	NoC,
	POT,
	REL,
	BUZ,
	D4,
	D5,
	D6,
	D7,

	//PORT_B
	BUT_0,
	Rs,
	Rw,
	E,
	SS,
	MOSI,
	MISO,
	SCK,

	//PORT_C
	SCL,
	SDA,
	LED_0,
	A1,
	A2,
	A3,
	A4,
	LED_1,

	//PORT_D
	RX,
	TX,
	BUT_2,
	LED_2,
	EN1,
	EN2,
	BUT_1,
	SRVO
}Dio_Channel_Type;

#endif /* MCAL_DIO_DIO_TYPES_H_ */
