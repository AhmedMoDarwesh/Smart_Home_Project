/*
 * Dio.c
 *
 *  Created on: Aug 4, 2021
 *      Author: ahmed
 */


#include "Dio.h"


void Dio_write(Dio_Channel_Type channel, Dir dir) {

	Dio_PORT_Type port = channel / 8;
	Dio_Channel_Type pin = channel % 8;

	switch (port) {

	case PORT_A:
		if (dir == OUTPUT) {
			SET_BIT(DDRA, pin);
		} else {
			CLR_BIT(DDRA, pin);
		}
		break;

	case PORT_B:
		if (dir == OUTPUT) {
			SET_BIT(DDRB, pin);
		} else {
			CLR_BIT(DDRB, pin);
		}
			break;

	case PORT_C:
		if (dir == OUTPUT) {
			SET_BIT(DDRC, pin);
		} else {
			CLR_BIT(DDRC, pin);
		}
			break;

	case PORT_D:
		if (dir == OUTPUT) {
			SET_BIT(DDRD, pin);
		} else {
			CLR_BIT(DDRD, pin);
		}
			break;

	default:
		break;
	}
}


void Dio_write_PORT(Dio_Channel_Type channel, LEVEL level) {

	Dio_PORT_Type port = channel / 8;
	Dio_Channel_Type pin = channel % 8;

	switch (port) {

	case PORT_A:
			if (level == HIGH) {
				SET_BIT(PORTA, pin);
			} else {
				CLR_BIT(PORTA, pin);
			}
			break;

		case PORT_B:
			if (level == HIGH) {
				SET_BIT(PORTB, pin);
			} else {
				CLR_BIT(PORTB, pin);
			}
				break;

		case PORT_C:
			if (level == HIGH) {
				SET_BIT(PORTC, pin);
			} else {
				CLR_BIT(PORTC, pin);
			}
				break;

		case PORT_D:
			if (level == HIGH) {
				SET_BIT(PORTD, pin);
			} else {
				CLR_BIT(PORTD, pin);
			}
				break;

		default:
			break;
		}
}


LEVEL Dio_Read_PORT(Dio_Channel_Type channel) {

	Dio_PORT_Type port = channel / 8;
	Dio_Channel_Type pin = channel % 8;

	LEVEL level;

	switch (port) {

	case PORT_A:
		level = GET_BIT(PORTA, pin);
		break;

	case PORT_B:
		level = GET_BIT(PORTB, pin);
		break;

	case PORT_C:
		level = GET_BIT(PORTC, pin);
		break;

	case PORT_D:
		level = GET_BIT(PORTD, pin);
		break;

	default:
		break;
	}

		return level;
}


LEVEL Dio_Read_PIN(Dio_Channel_Type channel) {

	Dio_PORT_Type port = channel / 8;
	Dio_Channel_Type pin = channel % 8;

	LEVEL level;

	switch (port) {

	case PORT_A:
		level = GET_BIT(PINA, pin);
		break;

	case PORT_B:
		level = GET_BIT(PINB, pin);
		break;

	case PORT_C:
		level = GET_BIT(PINC, pin);
		break;

	case PORT_D:
		level = GET_BIT(PIND, pin);
		break;

	default:
		break;
	}

		return level;
}


void Dio_Toggle_Channel(Dio_Channel_Type channel) {

	Dio_PORT_Type port = channel / 8;
	Dio_Channel_Type pin = channel % 8;

	switch (port) {

	case PORT_A:
		TOG_BIT(PORTA, pin);
		break;

	case PORT_B:
		TOG_BIT(PORTB, pin);
		break;

	case PORT_C:
		TOG_BIT(PORTC, pin);
		break;

	case PORT_D:
		TOG_BIT(PORTD, pin);
		break;

	default:
		break;
	}
}


