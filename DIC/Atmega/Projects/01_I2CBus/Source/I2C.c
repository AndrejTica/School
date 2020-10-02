/* *********************************************************
	File: I2C.c
	Description:	
		I2C ( TWT ) interface to the Atmel micro-controller ATMega644P.
		Only master is supported.
***********************************************************/

#include <avr/io.h>
#include "I2C.h"
#include "twi.h"
#include "HtlStddef.h"

/************************* Prototypes ***********************/
static TBool
I2CStart( void );

static void
I2CStop( void );

static TBool
I2CSendByte(
unsigned char aByte);

static TBool
I2CSendAddressWrite(
unsigned char aAddress);

static TBool
I2CSendAddressRead(
unsigned char aAddress);

static TBool
I2CReceiveByte(
unsigned char* aByte);

static TBool
I2CReceiveLastByte(
unsigned char* aByte);


/**********************************************************
	Function: I2CInit
	Description:
		Initialises the TWI interface.
		
	Parameters:
		aClkFrequency	- The system clock of the micro-controller in Hz
		aBitrate		- The I2C bitrate
		
	Return:
		ETRUE if successful otherwise EFALSE
***********************************************************/
TBool
I2CInit( 
  unsigned long aClkFrequency, 
  unsigned long aBitrate,
  TI2CMode		aMode	)
{	
	  // Seite 290
	  // Calculate the registers for the bus CLK 
	  // Enable pullup resisitors 
	  
	  unsigned char PRESCALER[] = {1, 4, 16, 64 };  
	  unsigned long lTWBR = 256;
	  unsigned int i;
	  
	  for(i=0;i<4;i++)
	  {
		  if(((aClkFrequency)/(PRESCALER[i]*aBitrate*2)-8)<lTWBR)
		  {
		  TWSR |= (i<<TWPS0);
		  TWBR = ((aClkFrequency)/(PRESCALER[i]*aBitrate*2)-8);
		  }
		  
		  PORTC |= (1<<PC1) | (1<<PC0);					// Pull-Up Wid
	  }
	  
	  return ETRUE;	  
  }
/**********************************************************
	Function: I2CSendData
	Description:
		Sends data from the TWI.
		
	Parameters:
		aAddress - Address from the slave
		aData    - Data that needs to be sent
		aSize	 - Size of the Data
		
	Return:
		ETRUE if successful otherwise EFALSE
***********************************************************/  
TBool
I2CSendData(
  unsigned char		aAddress,
  unsigned char*	aData,
  unsigned int		aSize	)
{
  if( !I2CStart())
	return EFALSE;	
	
  if( !I2CSendAddressWrite(aAddress))
  {
	  I2CStop();
	  return EFALSE;
  }
  
  for(int i = 0; i < aSize; i++ )
  {
	  if ( !I2CSendByte( aData[i] )) 
	  {
		I2CStop();
		return EFALSE;
	  }
  }
  
  I2CStop();	

  return ETRUE;
} 
 
 /**********************************************************
	Function: I2CReceiveData
	Description:
		Receives data from the TWI.
		
	Parameters:
		aAddress - Address from the slave
		aData    - Data that needs to be sent
		aSize	 - Size of the Data
		
	Return:
		ETRUE if successful otherwise EFALSE
***********************************************************/  
TBool
I2CReceiveData(
  unsigned char		aAddress,
  unsigned char*	aData,
  unsigned int		aSize )
 {
	  unsigned int	i;
	if( !I2CStart())
	  return EFALSE;
	
	if( !I2CSendAddressRead(aAddress))
	{
		I2CStop();
		return EFALSE;
	}
  
	for(i = 0; i < aSize -1 ; i++ )
	{
		if ( !I2CReceiveByte( &aData[i] ))
		{
			I2CStop();
			return EFALSE;
		}
	}
	
	
	if ( !I2CReceiveLastByte( &aData[i] ))
	{
		I2CStop();
		return EFALSE;
	}
	
	I2CStop();
	return ETRUE;
 }
 
 /*********************** private functions *******************************/
 
 /**********************************************************
	Function: I2CStart
	Description:
		Starts the TWI
		
	Parameters:
		None
		
	Return:
		ETRUE if successful otherwise EFALSE
***********************************************************/  
 static TBool
 I2CStart( void )
 {
	 TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	 
	 while (!(TWCR & (1<<TWINT)));
	 
	 if ((TWSR & TW_SR_INFO_MASK) != TW_START)  
	 return EFALSE;

	return ETRUE;
	
 }
 
 /**********************************************************
	Function: I2CStop
	Description:
		Stops the TWI
		
	Parameters:
		None
		
	Return:
		ETRUE if successful otherwise EFALSE
***********************************************************/  
 static void
 I2CStop( void )
 {
	  TWCR = (1<<TWINT) | (1<<TWSTO) | (1<<TWEN);
 }
 
 /**********************************************************
	Function: I2CSendByte
	Description:
		Sends byte from the TWI.
		
	Parameters:
		aByte - the byte that we want to sent to the TWI
		
	Return:
		ETRUE if successful otherwise EFALSE
***********************************************************/  
 static TBool
 I2CSendByte(
	unsigned char aByte)
{
	TWDR = aByte;
	TWCR = (1<<TWINT) | (1<<TWEN);
	
	 while (!(TWCR & (1<<TWINT)));

	if ((TWSR & TW_SR_INFO_MASK) != TW_MR_DATA_ACK)
	 return EFALSE;
	
	return ETRUE;
	
}	
 
 /**********************************************************
	Function: I2CSendAddressWrite
	Description:
		Sends address with writebit to the TWI.
		
	Parameters:
		aAddress - Address from the slave
		
	Return:
		ETRUE if successful otherwise EFALSE
***********************************************************/  
 static TBool
 I2CSendAddressWrite(
 unsigned char aAddress)
{
	unsigned char address;
	address = aAddress &= ~0x01;
	
	TWDR = address; 
	TWCR = (1<<TWINT) | (1<<TWEN);
	
	while (!(TWCR & (1<<TWINT)));
	
	if ((TWSR & TW_SR_INFO_MASK) != TW_MT_SLA_ACK)
	{
	 return EFALSE;
	}
	return ETRUE;

} 
 
  /**********************************************************
	Function: I2CSendAddressRead
	Description:
		Receives address with writebit from the TWI.
		
	Parameters:
		aAddress - Address from the slave
		
	Return:
		ETRUE if successful otherwise EFALSE
***********************************************************/  
 static TBool
 I2CSendAddressRead(
   unsigned char aAddress)
{
   	unsigned char address;
   	address= aAddress |= 0x01;
   	
   	TWDR = address;
   	TWCR = (1<<TWINT) | (1<<TWEN);
   	
   	while (!(TWCR & (1<<TWINT)));
   	
   	if ((TWSR & TW_SR_INFO_MASK) != TW_MR_SLA_ACK)
   	{
	  
	   	return EFALSE;
   	}
   	return ETRUE;

   
   }
 /**********************************************************
	Function:  I2CReceiveByte

	Description:
		Receives Byte from the TWI.		
	Parameters:
		aByte - the byte that we want to sent to the TWI
		
	Return:
		ETRUE if successful otherwise EFALSE
***********************************************************/  
   
 static TBool 
 I2CReceiveByte(
	unsigned char* aByte)
	{
		TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
		
		while (!(TWCR & (1<<TWINT)));

		if ((TWSR & TW_SR_INFO_MASK) != TW_MR_DATA_ACK)
		return EFALSE;
		
		*aByte = TWDR;
		return ETRUE;
	}
 /**********************************************************
	Function:  I2CReceiveLastByte

	Description:
		Receives last Byte from the TWI.
	Parameters:
		aByte - the byte that we want to sent to the TWI
		
	Return:
		ETRUE if successful otherwise EFALSE
***********************************************************/	
 static TBool
 I2CReceiveLastByte(
 unsigned char* aByte)
 {
	 TWCR = (1<<TWINT) | (1<<TWEN);
	 while (!(TWCR & (1<<TWINT)));

	 if ((TWSR & TW_SR_INFO_MASK) != TW_MR_DATA_NACK)
	 return EFALSE;
	 
	 *aByte = TWDR;
	 return ETRUE;
 }
 	
 
 

  