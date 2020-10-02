/***********************************************************
File: SPI.c
Creater: Andre
Date: 18.12.2019
Usage: SPI-Interface transfer
***********************************************************/

#include <avr/io.h>
#include <stdlib.h>
#include <stdio.h>
#include "HtlStddef.h"
#include "SPI.h"
#include <string.h>

TBool SPIInit(TSPIMODE aSpiMode){
	
	
	DDRB |= (1<<4)|(1<<5)|(1<<7);	//4 -> PB5 = SS
									//5 -> PB6 = MOSI
									//6 -> PB7 = CLK
	
	//DDRB &= ~(1<<6);				//7 -> PB6 = MISO
	
	
	SPCR |= (1<<SPE) | (aSpiMode.DataOrder<<DOR0) | (aSpiMode.MasterSlave<<MSTR) | (aSpiMode.Prescaler<<SPR0) | (aSpiMode.CPha<<CPHA) | (aSpiMode.Cpol<<CPOL) | ((aSpiMode.Prescaler&0x3)<<SPR0);
	SPSR |= ((aSpiMode.Prescaler>3)?1:0) << SPI2X;
	
	return ETRUE;
}

void SPIGetDefaultValue(TSPIMODE *aSpiMode){
	
	memset(aSpiMode, 0, sizeof(TSPIMODE));
	aSpiMode->Prescaler		= ESPI_PRESCALER_4;
	aSpiMode->Cpol			= EACPOL_RISING;
	aSpiMode->CPha			= ECPHA_LEAD_SAMPLE;
	aSpiMode->DataOrder		= EDATAORDER_MSB_FIRST;
	aSpiMode->MasterSlave	= EMASTER;
	
}

TBool SPIWriteByte(unsigned char aData){
	
	SPDR = aData;
	while(!(SPSR & (1<<SPIF)));
	
	return ETRUE;
}

TBool SPIReadByte(unsigned char *aData){
	
	return ETRUE;
}


/*NOT POSSIBLE
TBool SPIReadWriteBuffer(unsigned char *aReadBuffer, unsigned char *aWriteBuffer, unsigned char sSize){}
*/