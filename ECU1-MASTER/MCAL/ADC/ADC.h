/*
 * ADC.h
 *
 *  Created on: Aug 13, 2021
 *      Author: ahmed
 */

#ifndef MCAL_ADC_ADC_H_
#define MCAL_ADC_ADC_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "ADC_Cfg.h"
#include "../../BIT_MATH.h"
#include "../../STD_Types.h"

void ADC_init();
uint16 ADC_READ(uint8 channel);

#endif /* MCAL_ADC_ADC_H_ */
