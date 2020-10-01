
#include <avr/io.h>
#include <avr/interrupt.h>
#include "Adc.h"

uint16_t *analogRead_addressVar = 0;  


void initADC(TADCRefVoltage refVoltage, TADCPrescaler prescaler){
	ADCSRA = 0;
	ADCSRB = 0;
	ADMUX = 0;
	
	ADCSRA |= ((prescaler+1) << ADPS0);
	ADMUX |= (refVoltage << REFS0);
	ADCSRA |= (1<<ADEN);
}

uint16_t analogRead(uint8_t adcPin){
	ADMUX |= (adcPin<<MUX0);
	ADCSRA |= (1<<ADSC);
	while ((ADCSRA>>ADSC)&0x01){}
	uint16_t result = ADCL;
	result += ADCH<<8;
	return result;
}

void analogRead_v(uint8_t adcPin, uint16_t *addressVar){
	analogRead_addressVar = addressVar;
	ADMUX |= (adcPin<<MUX0);
	ADCSRA |= (1<<ADIE);
	sei();
	ADCSRA |= (1<<ADSC);
}

uint16_t analogRead_FreeRunMode(){
	uint16_t result = ADCL;
	result += ADCH<<8;
	return result;
}

void analogRead_Noiseless(uint8_t adcPin, uint16_t *addressVar){
	analogRead_addressVar = addressVar;
	ADCSRA &= ~(1<<ADATE);
	ADCSRA |= (1<<ADIE);
	ADMUX |= (adcPin<<MUX0);
	sei();
	SMCR |= (1<<SM0);
	SMCR &= ~((1<<SM1) | (1<<SM2));
	SMCR |= (1<<SE);
}
	
void startADC_FreeRunMode(uint8_t adcPin){
	ADMUX |= (adcPin<<MUX0);
	ADCSRA |= (1<<ADATE);
	ADCSRA |= (1<<ADSC);
}
	
void stopADC_FreeRunMode(){
	ADCSRA &= ~(1<<ADATE);
}

void stopADC(){
	ADCSRA = 0;
	ADMUX = 0;
	ADCSRB = 0;
}

ISR(ADC_vect){
	SMCR &= ~(1<<SE);
	uint16_t result = ADCL;
	result += ADCH<<8;
	*analogRead_addressVar = result;
}
