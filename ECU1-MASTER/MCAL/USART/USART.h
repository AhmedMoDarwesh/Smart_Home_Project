/*
 * USART.h
 *
 *  Created on: Sep 18, 2021
 *      Author: ahmed
 */

#ifndef MCAL_USART_USART_H_
#define MCAL_USART_USART_H_

#include <avr/io.h>
#include <util/delay.h>
#include "../../BIT_MATH.h"
#include "../../STD_Types.h"

void USART_Init(uint32 baud);
void USART_Transmit_5_8(uint8 data);
uint8 USART_Receive(void);

#endif /* MCAL_USART_USART_H_ */
