/* *********************************************************
	File: I2C.h
	Description:	
		I2C ( TWT ) interface to the Atmel micro-controller ATMega644P.
		Only master is supported.
***********************************************************/
#include "HtlStddef.h"

#ifndef I2C_H
#define I2C_H
	
typedef enum{											// enum zur durchnummerierung 
EI2C_MODE_MASTER,
EI2C_MODE_SLAVE
	}TI2CMode;

TBool I2CInit(
unsigned long aClkFrequency,
unsigned long aBitrate,
TI2CMode	  aMode	);

TBool
I2CSendData(
unsigned char		aAddress,
unsigned char*		aData,
unsigned int		aSize	);

TBool
I2CReceiveData(
unsigned char		aAddress,
unsigned char*		aData,
unsigned int		aSize );

#endif