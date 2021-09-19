/*
 * SPI.c
 *
 *  Created on: Aug 23, 2021
 *      Author: ahmed
 */

#include "SPI.h"

void SPI_SLAVE_INIT() {

// Enable SPI.
#if SPI_STATUS == ENABLE
	SET_BIT(SPCR, SPE);
#elif SPI_STATUS == DISABLE
	CLR_BIT(SPCR, SPE);
#endif

// Enabling Slave/Master.
#if SPI_MSTR_SLVE_SET == MASTER
	SET_BIT(SPCR, MSTR);
#elif SPI_MSTR_SLVE_SET == SLAVE
	CLR_BIT(SPCR, MSTR);
#endif

// Setting Speed mode and Frequency
	switch (SPI_CLOCK_SPEED) {

	case NORMAL_SPEED_BIT:
#if SPI_CLOCK_FREQ == FOSC_4
		CLR_BIT(SPCR, SPR0);
		CLR_BIT(SPCR, SPR1);
		CLR_BIT(SPSR, SPI2X);
#elif SPI_CLOCK_FREQ == FOSC_16
		SET_BIT(SPCR, SPR0);
		CLR_BIT(SPCR, SPR1);
		CLR_BIT(SPSR, SPI2X);
#elif SPI_CLOCK_FREQ == FOSC_64
		CLR_BIT(SPCR, SPR0);
		SET_BIT(SPCR, SPR1);
		CLR_BIT(SPSR, SPI2X);
#elif SPI_CLOCK_FREQ == FOSC_128
		SET_BIT(SPCR, SPR0);
		SET_BIT(SPCR, SPR1);
		CLR_BIT(SPSR, SPI2X);
#endif
		break;
	case DOUBLE_SPEED_BIT:
#if SPI_CLOCK_FREQ == FOSC_2
		CLR_BIT(SPCR, SPR0);
		CLR_BIT(SPCR, SPR1);
		SET_BIT(SPSR, SPI2X);
#elif SPI_CLOCK_FREQ == FOSC_8
		SET_BIT(SPCR, SPR0);
		CLR_BIT(SPCR, SPR1);
		SET_BIT(SPSR, SPI2X);
#elif SPI_CLOCK_FREQ == FOSC_32
		CLR_BIT(SPCR, SPR0);
		SET_BIT(SPCR, SPR1);
		SET_BIT(SPSR, SPI2X);
#elif SPI_CLOCK_FREQ == FOSC_64
		SET_BIT(SPCR, SPR0);
		SET_BIT(SPCR, SPR1);
		SET_BIT(SPSR, SPI2X);
#endif
		break;
	default:
		break;
	}

// Plarity Setting.
#if SPI_MODE == LeSampRise_TrSetFall
	CLR_BIT(SPCR, CPHA);
	CLR_BIT(SPCR, CPOL);
#elif SPI_MODE == LeSetRise_TrSampFall
	SET_BIT(SPCR, CPHA);
	CLR_BIT(SPCR, CPOL);
#elif SPI_MODE == LeSampFall_TrSetRise
	CLR_BIT(SPCR, CPHA);
	SET_BIT(SPCR, CPOL);
#elif SPI_MODE == LeSetFall_TrSampRise
	SET_BIT(SPCR, CPHA);
	SET_BIT(SPCR, CPOL);
#endif
}


uint8 SPI_SLV_RECEV(void) {
/* Wait for reception complete */
while(!(SPSR & (1<<SPIF)));
/* Return data register */
return SPDR;
}
