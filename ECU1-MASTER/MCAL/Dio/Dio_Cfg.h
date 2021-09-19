/*
 * Dio_Cfg.h
 *
 *  Created on: Aug 5, 2021
 *      Author: ahmed
 */

#ifndef MCAL_DIO_DIO_CFG_H_
#define MCAL_DIO_DIO_CFG_H_

#include <avr/io.h>
#include "Dio_Types.h"
#include "../../BIT_MATH.h"
#include "../../STD_Types.h"

typedef struct Dio_config_Type {

	uint8 port;
	uint8 pin;
	Dir dir;
	LEVEL level;
}Dio_config_Type;


void Dio_init();

#endif /* MCAL_DIO_DIO_CFG_H_ */
