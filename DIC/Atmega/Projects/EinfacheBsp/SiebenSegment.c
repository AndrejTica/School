/*
 * SiebenSegment.c
 *
 * Created: 2016-03-08
 * Author: SRES
 *
 * Led is on PortD Pin 7
 */ 


#include <avr/io.h>

unsigned char MappingArray[]=
{
	0x3F, // 0
	0x06  // 1	
};

int main(void)
{
	unsigned char counter;
	unsigned char siebenSegCode;
  	unsigned long  loopCounter = 0;
  	unsigned char ledState = 0;
	
	DDRA = 0x0;  // Input Port A
	DDRB = 0xFF; // Output Port B
  
  	DDRD |= 0x80;
  

	while(1)
    	{
      	loopCounter++;
      
      	counter = PINA & 0xF;
		
		  switch( counter )
		  {
  		  case 0:
  		  siebenSegCode = MappingArray[0];
  		  break;
  		  case 4:
  		  siebenSegCode = MappingArray[1];
  		  break;
  		  
  		  default:
  		  siebenSegCode = 0;
  		  break;
		  }
		
		
		  PORTB = siebenSegCode;
      
      if ( loopCounter % 10000 == 0 )
      {
        if ( ledState == 1)
        {
           PORTD &= ~0x80;
           ledState = 0;
        }           
        else
        {
           PORTD |= 0x80;
           ledState = 1;
        }           
           
      }        	
    }
}