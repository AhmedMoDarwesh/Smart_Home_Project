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

// Func. To Turn all Devices OFF
void Turn_All_OFF() {

	Dio_write_PORT(LED_0, LOW);
	Dio_write_PORT(LED_1, LOW);
	Dio_write_PORT(LED_2, LOW);
}

int main() {

	// I/O DDRs/PORTS/PINS Initialization.
	Dio_init();
	// SPI_SLAVE_Communication_Protocol_Intializtaion.
	SPI_SLAVE_INIT();
	// External Interrupt Initialization.
	XTRN_INT_init();

	while (1) {

		_delay_ms(10);
		uint8 x = SPI_SLV_RECEV();

		if (x == '1') {					// Toggling 1st Device.
			Dio_Toggle_Channel(LED_0);
		} else if (x == '2') {			// Toggling 2nd Device.
			Dio_Toggle_Channel(LED_1);
		} else if (x == '3') {			// Toggling 3rd Device.
			Dio_Toggle_Channel(LED_2);
		} else if (x == '0') {			// Switch All Devices OFF.
			Turn_All_OFF();
		}
	}

}
