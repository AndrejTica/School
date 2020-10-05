/*Hinweis: Der Timer ist für die 1Mhz vom interne Takt des ATMEGAs*/
#include <avr/io.h>
#include <avr/interrupt.h>
 
//Variablen für die Zeit
volatile unsigned int  millisekunden=0;
volatile unsigned int  sekunde=0;
volatile unsigned int  minute=0;
volatile unsigned int  stunde=0;
int main()
{
 
   //Timer 0 konfigurieren
 
   TCCR0 =(1<<WGM01) |(1<<CS01);
   OCR0=125;
 
   //Compare Interrupt aktivieren
   TIMSK|=(1<<OCIE0);
   //Globale Interrupts aktivieren
   sei();
   while(1)
   {
    /*Hier kann die aktuelle Zeit ausgeben werden*/
   }
 
}
 
// Der Compare Interrupt Handler
// Wird aufgerufen wenn TCNT0 = 125
ISR (TIMER0_COMP_vect)
{
   millisekunden++;
   if(millisekunden==1000)
   {
      sekunde++;
      millisekunden=0;
      if(sekunde==60)
      {
         minute++;
         sekunde=0;
      }
      if(minute ==60)
      {
        stunde++;
        minute=0;
      }
   }
}
