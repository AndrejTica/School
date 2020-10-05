#include <avr/io.h>
#include <avr/interrupt.h>

// liest RC5 Code von Phillips ein
// Manchester Code 889 µs _|- 889 µs
// Fosz = 4 MHz

// Prinzip ab ext Interrupt 14 mal mit Timerinterrupt einlesen
//#define 

unsigned short rc5Data;
unsigned char rc5Ready;

void initExtInt0(void) {
  // falling edge
  MCUCR |= (1 << ISC01);
  MCUCR &= ~(1 << ISC00);
  // Interrupt enable
  GICR  |= (1<<INT0);
}

void initTimer1(void) {
  // erster Interrupt bei 889µs/2
  // Fosz = 4 MHz
  OCR1A = (889UL/4UL)/2UL;
  // CTC Mode
  TCCR1A &= ~((1<<WGM10)|(1<<WGM11));
  TCCR1B |= (1<<WGM12);
  TCCR1B &= ~(1<<WGM13);
  TIMSK  |= (1<<OCIE1A);

}

ISR (INT0_vect) {
  // Timer starten
  // Prescaler = 1
  TCCR1B |= (1<<CS10);

}


ISR (TIMER1_COMPA_vect) {
  static unsigned char rc5Count;
  // 1.Bit (mit Sicherheit "1")
  if (GICR & (1<<INT0)) {
    // ext Interrupt abschalten
    GICR &= ~(1<<INT0);
	//OCR Wert neu laden
    OCR1A = ((889UL/4UL)*2UL);
  }

  //Datenbit einlesen
  rc5Data |= PIND&(1<<PIND2);
  if (rc5Count == 14) {
    rc5Ready = 1;
	rc5Count = 1;
	// externe Interrupt disable
	GICR |= (1<<INT0);
	return;
  }

  rc5Data <<= 1;
  rc5Count++;
}


int main(void) {
  initExtInt0();
  initTimer1();
  sei();

  while(1) {
    PORTA++;
  }
}

