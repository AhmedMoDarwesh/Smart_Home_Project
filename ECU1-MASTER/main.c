/*
 * main.c
 *
 *  Created on: Aug 5, 2021
 *      Author: ahmed
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "MCAL/Dio/Dio.h"
#include "HAL/LCD/LCD.h"
#include "HAL/7_Segm/7_Segma.h"
#include "MCAL/ADC/ADC.h"
#include "MCAL/External_Interrupt/External_Interrupt.h"
#include "MCAL/SPI/SPI.h"
#include "MCAL/USART/USART.h"
#include "BIT_MATH.h"
#include "STD_Types.h"



int main() {

	// I/O DDRs/PORTS/PINS Initialization.
	Dio_init();
	// SPI_MASTER_Communication_Protocol_Intializtaion.
	SPI_MASTER_INIT();
	// UART Communication Protocol Intializtaion.
	USART_Init(103);

	uint8 data = 0;

	while (1) {
		_delay_ms(10);

		// Receiving Bluetooth data by UART.
		data = USART_Receive();

		// Transmitting data received
		SPI_MSTR_TRNSMT(data);
		 _delay_ms(10);
	}
}
