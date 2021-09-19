/*
 * External_Interrupt.c
 *
 *  Created on: Aug 13, 2021
 *      Author: ahmed
 */

#include <avr/io.h>
#include "External_Interrupt.h"


void (*p2f0)(void);
void (*p2f1)(void);
void (*p2f2)(void);

void XTRN_INT_init() {
#if EXTI_INT0 == ENABLED
	SET_BIT(GICR, INT0);
#else
	CLR_BIT(GICR, INT0);
#endif

#if EXTI_INT0_EDGE == Low_Level
	CLR_BIT(MCUCR, ISC00);
	CLR_BIT(MCUCR, ISC01);
#elif EXTI_INT0_EDGE == Both_Edges
	SET_BIT(MCUCR, ISC00);
	CLR_BIT(MCUCR, ISC01);
#elif EXTI_INT0_EDGE == Falling_Edge
	CLR_BIT(MCUCR, ISC00);
	SET_BIT(MCUCR, ISC01);
#elif EXTI_INT0_EDGE == Raising_Edge
	SET_BIT(MCUCR, ISC00);
	SET_BIT(MCUCR, ISC01);
#endif

#if EXTI_INT1 == ENABLED
	SET_BIT(GICR, INT1);
#else
	CLR_BIT(GICR, INT1);
#endif

#if EXTI_INT1_EDGE == Low_Level
	CLR_BIT(MCUCR, ISC10);
	CLR_BIT(MCUCR, ISC11);
#elif EXTI_INT1_EDGE == Both_Edges
	SET_BIT(MCUCR, ISC10);
	CLR_BIT(MCUCR, ISC11);
#elif EXTI_INT1_EDGE == Falling_Edge
	CLR_BIT(MCUCR, ISC10);
	SET_BIT(MCUCR, ISC11);
#elif EXTI_INT1_EDGE == Raising_Edge
	SET_BIT(MCUCR, ISC10);
	SET_BIT(MCUCR, ISC11);
#endif

#if EXTI_INT2 == ENABLED
	SET_BIT(GICR, INT2);
#else
	CLR_BIT(GICR, INT2);
#endif

#if EXTI_INT2_EDGE == Falling_Edge
	CLR_BIT(MCUCR, ISC2);
#elif EXTI_INT2_EDGE == Raising_Edge
	SET_BIT(MCUCR, ISC2);
#endif

	SET_BIT(SREG, 7);
}


void CallBack_INT0(void (*p2func)(void)) {
	p2f0 = p2func;
}

void CallBack_INT1(void (*p2func)(void)) {
	p2f1 = p2func;
}

void CallBack_INT2(void (*p2func)(void)) {
	p2f2 = p2func;
}

ISR(INT0_vect) {
	p2f0();
}

ISR(INT1_vect) {
	p2f1();
}

ISR(INT2_vect) {
	p2f2();
}
