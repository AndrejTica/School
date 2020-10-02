/*
 * I2CTestAvr644P.c
 *
 * Created: 07.11.2019 10:49:42
 * Author : domeeze
 */ 

#include <avr/io.h>
#include <stdio.h>		// wegen sprintf
#include "I2C.h"
#include "Lcd.h"
#include "twi.h"



int main(void)
{
	
	unsigned char slaAdd	= 0xA0;
	unsigned char reg[] = {0x02};
	
	I2CInit(16000000,100000,EI2C_MODE_MASTER);
	LcdInit();
	LcdClear();

	unsigned char data[3];
	char buffer[100];					// nicht unsinged wegen sprintf, der will nur char
	
    while (1) 
    {
		//LcdClear();
		LcdSetPosition(1,0);
		I2CSendData(slaAdd,reg,0x01);		
		I2CReceiveData(slaAdd,data,0x02);
		
		sprintf(buffer, "%02x : %02x : %02x",data[2],data[1],data[0]);
		LcdWriteString(buffer);
		
		
    }
}

