#include <avr/io.h>
#include <avr/interrupt.h>


#define BIT0 0
#define BIT1 1
#define BIT2 2
#define BIT3 3
#define BIT4 4
#define BIT5 5
#define BIT6 6
#define BIT7 7


// prototypes
void initExtInt0();


int main (void) {
  initExtInt0();
  while(1) {

    PORTB = PORTB+1;
  }

}

//------------ externer Interupt ---------------------------------------------*/
void initExtInt0() {

  // set extern Interrupt to falling edge
  //DDRD  |= (1<<BIT2);
  //MCUCR = MCUCR | (1<<BIT1);
  MCUCR = MCUCR & ~(1<<BIT1);
  MCUCR = MCUCR & ~(1<<BIT0);
  GICR  |= (1<<BIT6);  // enable externer Int0
  sei();

} /*--------------------------------------------------- end of initExtInt0 () */


ISR(INT0_vect)      
{
    /* Interrupt Code */
	PORTA=~PORTA;
}
