
#include <avr/io.h>
void usart_init();
void usart_transmit(unsigned char data);
unsigned char usart_receive();
void int2usart(unsigned int);
