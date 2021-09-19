/*
 * USART.c
 *
 *  Created on: Sep 18, 2021
 *      Author: ahmed
 */


#include "USART.h"

void USART_Init(uint32 baud) {
/* Set baud rate */
UBRRH = (uint8)(baud>>8);
UBRRL = (uint8)baud;
/* Enable receiver and transmitter */
UCSRB = (1<<RXEN)|(1<<TXEN);
/* Set frame format: 8data, 2stop bit */
UCSRC = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);
}


void USART_Transmit_5_8(uint8 data) {
/* Wait for empty transmit buffer */
while ( !( UCSRA & (1<<UDRE)) );
/* Put data into buffer, sends the data */
UDR = data;
}


uint8 USART_Receive(void) {
/* Wait for data to be received */
while ( !(UCSRA & (1<<RXC)) );
/* Get and return received data from buffer */
return UDR;
}
