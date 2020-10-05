// Dieses Programm erzeugt ein Rechtecksignal von 10kHz
// am Pin PA_0
// Oszillatorfrequenz = 1MHz

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



#define TIMERDEFAULT (0xFF-50+1)

void InitTimer0(void) {
  //PA_0 auf Ausgang setzen
  DDRA |=  (1<<BIT0);
  // no prescaling
  TCCR0 |= (1<<BIT0);
  TCCR0 &= ~(1<<BIT1);
  TCCR0 &= ~(1<<BIT2);

  TCNT0 = TIMERDEFAULT;
  // enable timerinterrupt at overflow
  TIMSK |= (1<<BIT0);
  
  sei();
}


int main(void) {

  InitTimer0();
  while(1) { 
    PORTD = PORTD+1;

  }
}


// Interrupt Service Routine für Timer0 Overflow
ISR (TIMER0_OVF_vect) {

  volatile unsigned char VarPort;

  VarPort = PORTA & 0x01;

  if (VarPort) {
    PORTA &= ~(1<<BIT0);
  }
  else {
    PORTA |= (1<<BIT0);
  }
  // Timer neu laden
  TCNT0 = TIMERDEFAULT;
}
