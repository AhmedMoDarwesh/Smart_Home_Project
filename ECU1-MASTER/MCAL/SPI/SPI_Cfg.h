/*
 * SPI_Cfg.h
 *
 *  Created on: Aug 23, 2021
 *      Author: ahmed
 */

#ifndef MCAL_SPI_SPI_CFG_H_
#define MCAL_SPI_SPI_CFG_H_

#define DISABLE						0
#define ENABLE						1

#define SPI_MSTR_SLVE_SET			MASTER

#define NORMAL_SPEED_BIT			0
#define DOUBLE_SPEED_BIT			1

#define FOSC_4						0
#define FOSC_16						1
#define	FOSC_64						2
#define	FOSC_128					3
#define	FOSC_2						4
#define	FOSC_8						5
#define	FOSC_32						6

#define LeSampRise_TrSetFall		0
#define LeSetRise_TrSampFall		1
#define LeSampFall_TrSetRise		2
#define LeSetFall_TrSampRise  		3

#define	MASTER						0
#define SLAVE						1

#define	SPI_STATUS					ENABLE

#define	SPI_CLOCK_SPEED				NORMAL_SPEED_BIT

#define SPI_CLOCK_FREQ				FOSC_16

#define	SPI_MODE					LeSampRise_TrSetFall


#endif /* MCAL_SPI_SPI_CFG_H_ */
