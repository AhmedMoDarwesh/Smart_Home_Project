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

void USART_Init( unsigned int baud );
void USART_Transmit_5_8( unsigned char data );
void USART_Transmit_9( unsigned int data );


#endif /* MCAL_USART_USART_H_ */
