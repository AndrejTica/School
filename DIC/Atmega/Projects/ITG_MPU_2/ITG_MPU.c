/*****************************************************************************
* Programmname:		Test ITG/MPU Breakoutboard 
* Dateiname:		ITG_MPU.c
* Funktion:			6-Achs-Gyroskop MPU6050
* Compiler:			AVR Studio 7.0 Build 634
* Autor:			RECW
* Änderungsdatum:	21.1.16
* Version:			1.1
******************************************************************************/
#include <avr/io.h>
#include <avr/interrupt.h>

#include <stdint.h>
#include "Usart.h"
#include "IIC.h"
#include "MPU6050.h"
#ifndef F_CPU
#define F_CPU 16000000L
#endif
#include <util/delay.h>
#define RD 0x1
#define WR 0x0


//*******************************************************************************

int main()
{

	int16_t AccX,AccY,AccZ;
	int16_t LValue;
	int16_t HValue;

	TWI_init();
	usart_init();

//MPU6050 einschalten		
		

	while (1)
	{
		
		TWI_Start(MPU6050_I2C_ADDRESS,WR);
		TWI_transmit(PWR_MGMT_1);
		TWI_transmit(0);
		TWI_stop();
		_delay_us(50);
	
		usart_transmit(0x0D);					//CR +LF
		usart_transmit(0x0A);
		
		
//MPU6050 auslesen
		TWI_Start(MPU6050_I2C_ADDRESS,WR);		//select MPU6050 
		TWI_transmit(ACCEL_XOUT_H);	//select AccX, High Byte 0x3B

		TWI_Start(MPU6050_I2C_ADDRESS,RD);		//Start reading
		HValue=TWI_receive_ACK();				//X-Acc
		LValue= TWI_receive_ACK();
		AccX = (HValue<<8)|LValue;
		
		HValue = TWI_receive_ACK();
		LValue = TWI_receive_ACK();
		AccY = (HValue<<8)|LValue;				//Y-Acc
		
		HValue=TWI_receive_ACK();
		LValue = TWI_receive_NAK();
		TWI_stop();
		AccZ = (HValue<<8)|LValue;				//Z-Acc

		PORTC ^= (1 << 2);

		usart_transmit('X');
		usart_transmit(':');
		int2usart(AccX);
		usart_transmit(';');
		usart_transmit(' ');

		usart_transmit('Y');
		usart_transmit(':');
		int2usart(AccY);
		usart_transmit(';');
		usart_transmit(' ');

		usart_transmit('Z');
		usart_transmit(':');
		int2usart(AccZ);
		usart_transmit(';');

		_delay_ms(100);
	}

	return 0;
}
	


