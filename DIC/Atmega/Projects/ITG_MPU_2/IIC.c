#include "IIC.h" 

//*******************************************************************************
// I2C-Programme
//---------------------------------------------------------------------------------
// I2C-Initialisierung
// // Register:
//	TWAR:	Address Register
//	TWAMR:	Adress Mask Register

void TWI_init()
{
	PRR = PRR & (!(1<<PRTWI));
	TWSR = 0x0;				//Clear Status Register	
	TWBR = 72;				//100kHz Takt
	TWCR = (1<<TWEN);		//Enable TWI
	//		(0<<TWIE)|		// Disable Interrupt
	//		(0<<TWINT)|		//Interrupt Flag
	//		(0<<TWEA)|		//Disable Acknowledge
	//		(0<<TWSTA)|		//Generate no Start-Condition
	//		(0<TWSTO)|		//Generate no Stop-Condition
	//		(0<<TWWC);		//Clear TWI-Collision Flag
  	PORTC |=(3);			//PULLUP setzen 

}
//
//---------------------------------------------------------------------------------

// Start Transmission

unsigned char TWI_Start(uint8_t adress,uint8_t dir)
{
	
	
//TWI Start	
	TWCR = 0;
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);	//Initiate START CONDITION
	while (!(TWCR & (1<<TWINT)));			//wait for START CONDITION done (TWINT set)
	if ((TWSR & 0xF8) != 0x08) return 1;	//break with error
	//TWCR &= ~(1<<TWSTA);					<--------------------------------------------------------?????????? loeschen!
	

//TWI Write Address & Direction	
	TWDR = ((adress<<1)|dir);
	TWCR = (1<<TWINT)|(1<<TWEN);			//Start transmission of address + direction
	while (!(TWCR & (1<<TWINT)));			//Wait for Transmission done	

//	if (((TWSR & 0xF8) != 0x18)&&(dir = 0)) return 1;	//write-error
//	else if (((TWSR & 0xF8) != 0x40)&&(dir!=0)) return 1;//read-error
		return 0;

}
//------------------------------------------------------------------------------------
void TWI_stop()
{

	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}

//-------------------------------------------------------------------------------------
void TWI_RS()
{
	TWCR &= ~(1<<TWSTO);
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);	//Initiate START CONDITION
	while (!(TWCR & (1<<TWINT)));			//wait for START CONDITION done (TWINT set)
	if ((TWSR & 0xF8) != 0x08) ;	//break with error
}


//------------------------------------------------------------------------------------
unsigned char TWI_transmit(unsigned char transmit)
{

	TWDR = transmit;
	TWCR = (1<<TWINT)|(1<<TWEN);			//Start Transmission of Data
	while (!(TWCR & (1<<TWINT)));
//	if ((TWSR & 0xF8) != 0x28) return 1;	//error

	return 0;		
}
//------------------------------------------------------------------------------------
unsigned char TWI_receive_NAK()
{
	
	TWCR = (1<<TWINT)|(1<<TWEN);
	while (!(TWCR & (1<<TWINT)));			//wait for data
//	if ((TWSR & 0xF8) != 0x58) return 1;
//	*receive = TWDR;
	
	return (TWDR);
}
//------------------------------------------------------------------------------------
unsigned char TWI_receive_ACK()
{
	
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while (!(TWCR & (1<<TWINT)));			//wait for data
//	if ((TWSR & 0xF8) != 0x58) return 1;
//	*receive = TWDR;
	
	return (TWDR);
}

//************************************************************************************
