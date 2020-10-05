#include <avr/interrupt.h>
#include <avr/io.h>


// Initiate TWI as Master with clk = 100kHz
void TWI_init();

// Start transmission + transmit address
unsigned char TWI_Start(unsigned char adress,unsigned char dir);

//Transmit data 
unsigned char TWI_transmit(unsigned char transmit);

//Receive one byte of data or last byte of string with NAK
unsigned char TWI_receive_NAK();

//Receive one byte from a data-string with ACK
unsigned char TWI_receive_ACK();

//Stop transmission
void TWI_stop();

//Repeated start

void TWI_RS();
