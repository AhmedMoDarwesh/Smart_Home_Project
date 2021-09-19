/*
 * Dio_Cfg.c
 *
 *  Created on: Aug 5, 2021
 *      Author: ahmed
 */


#include "Dio_Types.h"
#include <avr/io.h>
#include "Dio_Cfg.h"
#include "../../BIT_MATH.h"

Dio_config_Type PinCfg[] = {

		// PORTA, PINS configuration.
//		{PORT_A,PIN_1,INPUT, LOW},
//		{PORT_A,PIN_2,OUTPUT,LOW},
//		{PORT_A,PIN_3,OUTPUT,LOW},
//		{PORT_A,PIN_4,OUTPUT,LOW},
//		{PORT_A,PIN_5,OUTPUT,LOW},
//		{PORT_A,PIN_6,OUTPUT,LOW},
//		{PORT_A,PIN_7,OUTPUT,LOW},

		// PORTB, PINS configuration.
		{PORT_B,PIN_0,INPUT},
		{PORT_B,PIN_1,INPUT},
		{PORT_B,PIN_2,INPUT},
		{PORT_B,PIN_3,INPUT},
		{PORT_B,PIN_4,INPUT},
		{PORT_B,PIN_5,INPUT},
		{PORT_B,PIN_6,OUTPUT},
		{PORT_B,PIN_7,INPUT},

		// PORTC, PINS configuration.
		{PORT_C,PIN_2,OUTPUT},
//		{PORT_C,PIN_3,OUTPUT,LOW},
//		{PORT_C,PIN_4,INPUT,LOW},
//		{PORT_C,PIN_5,OUTPUT,LOW},
//		{PORT_C,PIN_6,INPUT,LOW},
		{PORT_C,PIN_7,OUTPUT},

		// PORTD, PINS configuration.
		{PORT_D,PIN_2,INPUT},
		{PORT_D,PIN_3,OUTPUT},
//		{PORT_D,PIN_4,OUTPUT,LOW},
//		{PORT_D,PIN_5,OUTPUT,LOW},
//		{PORT_D,PIN_6,INPUT,LOW},
};


void Dio_init() {

	for (int i = 0; i < (sizeof(PinCfg) / sizeof(PinCfg[0])); i++) {
		if (PinCfg[i].port == PORT_A) {
			if (PinCfg[i].dir == OUTPUT) {
				SET_BIT(DDRA, PinCfg[i].pin);
			} else {
				CLR_BIT(DDRA, PinCfg[i].pin);
			}
		}

		if (PinCfg[i].port == PORT_B) {
			if (PinCfg[i].dir == OUTPUT) {
				SET_BIT(DDRB, PinCfg[i].pin);
			} else {
				CLR_BIT(DDRB, PinCfg[i].pin);
			}
		}

		if (PinCfg[i].port == PORT_C) {
			if (PinCfg[i].dir == OUTPUT) {
				SET_BIT(DDRC, PinCfg[i].pin);
			} else {
				CLR_BIT(DDRC, PinCfg[i].pin);
			}
		}

		if (PinCfg[i].port == PORT_D) {
			if (PinCfg[i].dir == OUTPUT) {
				SET_BIT(DDRD, PinCfg[i].pin);
			} else {
				CLR_BIT(DDRD, PinCfg[i].pin);
			}
		}
	}
}
