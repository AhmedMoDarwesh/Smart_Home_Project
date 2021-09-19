/*
 * SPI.h
 *
 *  Created on: Aug 23, 2021
 *      Author: ahmed
 */

#ifndef MCAL_SPI_SPI_H_
#define MCAL_SPI_SPI_H_

#include <avr/io.h>
#include <util/delay.h>
#include "SPI_Cfg.h"
#include "../Dio/Dio_Types.h"
#include "../../BIT_MATH.h"
#include "../../STD_Types.h"

void SPI_MASTER_INIT();
void SPI_MSTR_TRNSMT(uint8 data);

#endif /* MCAL_SPI_SPI_H_ */
