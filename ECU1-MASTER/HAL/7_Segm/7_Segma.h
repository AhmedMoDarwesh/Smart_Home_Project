/*
 * 7_Segma.h
 *
 *  Created on: Aug 20, 2021
 *      Author: ahmed
 */

#ifndef HAL_7_SEGM_7_SEGMA_H_
#define HAL_7_SEGM_7_SEGMA_H_

#include <avr/io.h>
#include <util/delay.h>
#include "../../BIT_MATH.h"
#include "../../STD_Types.h"
#include "../../MCAL/Dio/Dio.h"

void Sev_Seg_write(uint8 num);
void Test_7_Segment();

#endif /* HAL_7_SEGM_7_SEGMA_H_ */
