/*
 * ADC.c
 *
 *  Created on: Aug 13, 2021
 *      Author: ahmed
 */

#include "ADC.h"

void ADC_init() {

#if ADC_ENABLE == ENABLE
	SET_BIT(ADCSRA, ADEN);
#else
	CLR_BIT(ADCSRA, ADEN);
#endif

#if ADC_SOURCE == ADC_SOURCE_AREF
	CLR_BIT(ADMUX, REFS0);
	CLR_BIT(ADMUX, REFS1);
#elif ADC_SOURCE == ADC_SOURCE_AVCC
	SET_BIT(ADMUX, REFS0);
	CLR_BIT(ADMUX, REFS1);
#elif ADC_SOURCE == ADC_SOURCE_RESERVED
	CLR_BIT(ADMUX, REFS0);
	SET_BIT(ADMUX, REFS1);
#elif ADC_SOURCE == ADC_SOURCE_VREF
	SET_BIT(ADMUX, REFS0);
	SET_BIT(ADMUX, REFS1);
#endif

#if ADC_PRESCALER_MODE == ADC_PRESCALER_2
	SET_BIT(ADCSRA, ADPS0);
	CLR_BIT(ADCSRA, ADPS1);
	CLR_BIT(ADCSRA, ADPS2);
#elif ADC_PRESCALER_MODE == ADC_PRESCALER_4
	CLR_BIT(ADCSRA, ADPS0);
	SET_BIT(ADCSRA, ADPS1);
	CLR_BIT(ADCSRA, ADPS2);
#elif ADC_PRESCALER_MODE == ADC_PRESCALER_8
	SET_BIT(ADCSRA, ADPS0);
	SET_BIT(ADCSRA, ADPS1);
	CLR_BIT(ADCSRA, ADPS2);
#elif ADC_PRESCALER_MODE == ADC_PRESCALER_16
	CLR_BIT(ADCSRA, ADPS0);
	CLR_BIT(ADCSRA, ADPS1);
	SET_BIT(ADCSRA, ADPS2);
#elif ADC_PRESCALER_MODE == ADC_PRESCALER_32
	SET_BIT(ADCSRA, ADPS0);
	CLR_BIT(ADCSRA, ADPS1);
	SET_BIT(ADCSRA, ADPS2);
#elif ADC_PRESCALER_MODE == ADC_PRESCALER_64
	CLR_BIT(ADCSRA, ADPS0);
	SET_BIT(ADCSRA, ADPS1);
	SET_BIT(ADCSRA, ADPS2);
#elif ADC_PRESCALER_MODE == ADC_PRESCALER_128
	SET_BIT(ADCSRA, ADPS0);
	SET_BIT(ADCSRA, ADPS1);
	SET_BIT(ADCSRA, ADPS2);
#endif
}

uint16 ADC_READ(uint8 channel) {

	ADMUX = (ADMUX & 0b11100000) | channel;
	SET_BIT(ADCSRA, ADSC);

	while(GET_BIT(ADCSRA, ADIF) == 0);

	_delay_us(10);

	SET_BIT(ADCSRA, ADIF);

	return ADC;
}