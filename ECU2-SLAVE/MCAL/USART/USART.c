/*
 * USART.c
 *
 *  Created on: Sep 18, 2021
 *      Author: ahmed
 */


#include "USART.h"

void USART_Init( unsigned int baud )
{
/* Set baud rate */
UBRRH = (unsigned char)(baud>>8);
UBRRL = (unsigned char)baud;
/* Enable receiver and transmitter */
UCSRB = (1<<RXEN)|(1<<TXEN);
/* Set frame format: 8data, 2stop bit */
UCSRC = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);
}


void USART_Transmit_5_8( unsigned char data )
{
/* Wait for empty transmit buffer */
while ( !( UCSRA & (1<<UDRE)) );
/* Put data into buffer, sends the data */
UDR = data;
}

void USART_Transmit_9( unsigned int data )
{
/* Wait for empty transmit buffer */
while ( !( UCSRA & (1<<UDRE)));
/* Copy 9th bit to TXB8 */
UCSRB &= ~(1<<TXB8);
if (data & 0x0100)
UCSRB |= (1<<TXB8);
/* Put data into buffer, sends the data */
UDR = data;
}
