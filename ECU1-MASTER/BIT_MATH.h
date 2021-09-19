/*
 * BIT_MATH.h
 *
 *  Created on: Aug 2, 2021
 *      Author: ahmed
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG,BIT)		REG |= (1<<BIT)
#define GET_BIT(REG,INDEX) 		(REG >> INDEX) & 0x01
#define CLR_BIT(REG,BIT)		REG &= ~(1<<BIT)
#define TOG_BIT(REG,PIN)		REG ^= (1<<(PIN))

#endif /* BIT_MATH_H_ */
