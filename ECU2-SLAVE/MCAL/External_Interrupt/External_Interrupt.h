/*
 * External_Interrupt.h
 *
 *  Created on: Aug 13, 2021
 *      Author: ahmed
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_H_
#define MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include "External_Interrupt_Cfg.h"
#include "../../BIT_MATH.h"
#include "../../STD_Types.h"

void XTRN_INT_init();
void CallBack_INT0(void (*p2func)(void));
void CallBack_INT1(void (*p2func)(void));
void CallBack_INT2(void (*p2func)(void));

#endif /* MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_H_ */
