/*
 * 7_Segma.c
 *
 *  Created on: Aug 20, 2021
 *      Author: ahmed
 */

#include "7_Segma.h"

const uint8 Sev_Segment[10] = {0,1,2,3,4,5,6,7,8,9};

void Sev_Seg_write(uint8 num) {

	uint8 Firstno = num%10;
	uint8 Secondno = num/10;

	for(num = 0; num < 100; num++) {
	Dio_write_PORT(Rw, LOW);
	Dio_write_PORT(Rs, HIGH);

	Dio_write_PORT(D4, GET_BIT(Firstno, 0));
	Dio_write_PORT(D5, GET_BIT(Firstno, 1));
	Dio_write_PORT(D6, GET_BIT(Firstno, 2));
	Dio_write_PORT(D7, GET_BIT(Firstno, 3));

	_delay_ms(10);

	Dio_write_PORT(Rs, LOW);
	Dio_write_PORT(Rw, HIGH);

	Dio_write_PORT(D4, GET_BIT(Secondno, 0));
	Dio_write_PORT(D5, GET_BIT(Secondno, 1));
	Dio_write_PORT(D6, GET_BIT(Secondno, 2));
	Dio_write_PORT(D7, GET_BIT(Secondno, 3));

	_delay_ms(10);
	}
}

void Test_7_Segment() {

	for(int i = 0; i <10; i++) {
		Sev_Seg_write(Sev_Segment[i]);
		_delay_ms(1000);
	}
}
