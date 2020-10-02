/*
 * 03_SPI_Test.c
 *
 * Created: 18.12.2019 13:59:25
 * Author : Andre
 */ 

#include <avr/io.h>
#include "SPI.h"

int main(void)
{
	TSPIMODE mode1;
	
	SPIGetDefaultValue(&mode1);
	SPIInit(mode1);
	
	unsigned char counter = 0;
	
    while (1)
	{
		
		PORTB &= ~(1<<4);
		DelayMs(100);
		SPIWriteByte(counter++);
		PORTB |= (1<<4);
		DelayMs(100);
    }
}

