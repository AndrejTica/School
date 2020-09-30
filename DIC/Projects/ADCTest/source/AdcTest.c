/*
 * ADCTest.c
 *
 * Created: 29.05.2019 14:37:36
 * Author : schwa
 */ 

#define F_CPU 16000000L

#include <avr/io.h>
#include <util/delay.h>
#include "Adc.h"

int a = 0;

unsigned char tabelle[10] = {
	0b10000000,	//0
	0b11110010,	//1
	0b01001000,	//2
	0b01100000,	//3
	0b00110010,	//4
	0b00100100,	//5
	0b00000100,	//6
	0b11110000,	//7
	0b00000000,	//8
	0b00100000	//9
	};

int main(void)
{
	initADC(ADC_RVOLTAGE_AVCC, ADC_P64);
	startADC_FreeRunMode(PA0);
	DDRC = 0xFF;
	while(1){
		a = analogRead_FreeRunMode();
		if (a < 50)
		{
			PORTC = ~tabelle[0];
		}
		else if (a < 100)
		{
			PORTC = ~tabelle[1];
		}
		else if (a < 150)
		{
			PORTC = ~tabelle[2];
		}
		else if (a < 200)
		{
			PORTC = ~tabelle[3];
		}
		else if (a < 250)
		{
			PORTC = ~tabelle[4];
		}
		else if (a < 300)
		{
			PORTC = ~tabelle[5];
		}
		else if (a < 350)
		{
			PORTC = ~tabelle[6];
		}
		else if (a < 400)
		{
			PORTC = ~tabelle[7];
		}
		else if (a < 450) //2,5 - 0,24
		{
			PORTC = ~tabelle[8];
		}
		else if (a < 500) // 2,5
		{
			PORTC = ~tabelle[9];
		}
		_delay_ms(500);
	}
}

