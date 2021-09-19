/*
 * Dio.h
 *
 *  Created on: Aug 4, 2021
 *      Author: ahmed
 */

#ifndef MCAL_DIO_DIO_H_
#define MCAL_DIO_DIO_H_

#include <avr/io.h>
#include "Dio_Types.h"
#include "Dio_Cfg.h"
#include "../../STD_Types.h"
#include "../../BIT_MATH.h"

void Dio_write(Dio_Channel_Type channel, Dir dir);
void Dio_write_PORT(Dio_Channel_Type channel, LEVEL level);
LEVEL Dio_Read_PORT(Dio_Channel_Type channel);
LEVEL Dio_Read_PIN(Dio_Channel_Type channel);
void Dio_Toggle_Channel(Dio_Channel_Type channel);

#endif /* MCAL_DIO_DIO_H_ */
