#ifndef SPI_H
#define SPI_H

#include <avr/io.h>
#include <stdlib.h>
#include <stdio.h>
#include "HtlStddef.h"
#include <string.h>

typedef enum{
	
	/*Prescaler values for clockgenerator */
	ESPI_PRESCALER_2 = 4,
	ESPI_PRESCALER_4 = 0,
	ESPI_PRESCALER_8 = 5,
	ESPI_PRESCALER_16 = 1,
	ESPI_PRESCALER_32 = 6,	
	ESPI_PRESCALER_64 = 2,
	ESPI_PRESCALER_128 = 3
		
}TSPIPRESCALER;

typedef enum{
	EACPOL_RISING = 0,
	EACPOL_FALLING = 1
	
}TCPOL;

typedef enum{
	
	ECPHA_LEAD_SAMPLE = 0,
	ECPHA_TRAIL_SAMPLE =1
		
}TCPHA;

typedef enum{
	
	EDATAORDER_MSB_FIRST = 0,
	EDATAORDER_LSB_FIRST = 1
	
}TDATAORDER;

typedef enum{
	
	EMASTER = 1,
	ESLAVE = 0
	
}TMASTERSLAVE;

typedef struct{
	
	TSPIPRESCALER	Prescaler;
	TCPOL			Cpol;
	TCPHA			CPha;
	TDATAORDER		DataOrder;
	TMASTERSLAVE	MasterSlave;
	
}TSPIMODE;


TBool SPIInit(TSPIMODE aSPIMode);
void SPIGetDefaultValue(TSPIMODE *aSpiMode);
TBool SPIWriteByte(unsigned char aData);
TBool SPIReadByte(unsigned char *aData);
TBool SPIReadWriteBuffer(unsigned char *aReadBuffer, unsigned char *aWriteBuffer, unsigned char sSize);
#endif