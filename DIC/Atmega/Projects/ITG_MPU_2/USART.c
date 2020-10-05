#include "Usart.h"
//****************************************************************************

// UART-Programme

//----------------------------------------------------------------------------
// UART-Initialisierung: 9600Baud, Format: 8N1

#define Fosc  16000000UL
#define Baud  14400
#define quot  Fosc/Baud
#define UBRR  (Fosc/(16UL*Baud)-1) 
//****************************************************
void usart_init()
{

//enable USART
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);	//Freigabe Receiver und Transmitter
//frame format 8n2 (8data, no parity,2stop)
	UCSR0C = (1<<USBS0)|(3<<UCSZ00);
//set baud rate
	UBRR0 = ( unsigned int ) UBRR;

}

//----------------------------------------------------------------------------
// Transmit Data: wartet auf leeren Sendebuffer und sendet anschließend

void usart_transmit(unsigned char data)
{
//wait for empty buffer

	while (!(UCSR0A & (1<<UDRE0)));
	
	UDR0 = data;
}


	
//-----------------------------------------------------------------------------
// Receive Data

unsigned char usart_receive()
{
//wait for data
	while(!(UCSR0A & (1<<RXC0)));
	
	return UDR0;
}

//------------------------------------------------------------------------------------
void int2usart(uint16_t i)		//Rekursive Funktion, die ein unsigned Int auf die Usart ausgibt
{
	char temp;
    if(i > 0){
        int2usart(i/10);
        temp = (i%10) + '0';
        usart_transmit(temp);
    }

}
