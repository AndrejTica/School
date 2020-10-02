/******************************************************************************************************************************************
	File: Lcd.c
	Description:
		Driver for an alphanumeric LCD with paralell interface. Only 4Bit Interface is supported.
*******************************************************************************************************************************************/

#include "Lcd.h"	//�nderungen in c file werden nicht in h file mitge�ndert / compiler kompeliert jede file allein
#include "LcdConstants.h"
#include "HtlStddef.h"

/********** Declaration of private functions ********/

void LcdOut4Bit( unsigned char aByte );
void LcdEnable( void );
TBool LcdReadBusyFlag( void );
TBool LcdCommand( unsigned char acmd);
TBool LcdCheckBusy ( void );
unsigned char LcdReadAdress( void );
unsigned char LcdRead4Bit( void );





/********** Public functions *******/
void
LcdInit(void)
{
LCD_PORT_DATA &= ~( 0xF << LCD_DB );
LCD_DDR_DATA  |=  ( 0xF << LCD_DB );

LCD_PORT_RS &= ~( 1 << LCD_RS );
LCD_DDR_RS  |=  ( 1 << LCD_RS );

LCD_PORT_RW &= ~( 1 << LCD_RW );
LCD_DDR_RW  |=  ( 1 << LCD_RW );

LCD_PORT_EN &= ~( 1 << LCD_EN );
LCD_DDR_EN  |=  ( 1 << LCD_EN );

DelayMs( LCD_BOOTUP_MS );

// Software reset 3 times

LcdOut4Bit( LCD_SOFT_RESET );	// ersten 4 bit immer nach oben geschrieben
DelayMs( LCD_SOFT_RESET_MS1);
LcdOut4Bit( LCD_SOFT_RESET );
DelayMs( LCD_SOFT_RESET_MS2);
LcdOut4Bit( LCD_SOFT_RESET );
DelayMs( LCD_SOFT_RESET_MS3 );
	// Set to 4 bit mode
	LcdOut4Bit( LCD_SET_FUNCTION |
				LCD_FUNCTION_4BIT );
	DelayMs(LCD_SET_4BITMODE_MS );
	//Initialise 2 lines 5x7 matrix
	LcdCommand( LCD_SET_FUNCTION |
				LCD_FUNCTION_4BIT |
				LCD_FUNCTION_2LINE |
				LCD_FUNCTION_5X7 );
	//Initialise coursor
	LcdCommand( LCD_SET_DISPLAY |
				LCD_DISPLAY_ON |
				LCD_CURSOR_OFF |
				LCD_BLINKING_OFF );
	LcdClear();
}


void
LcdWriteString(
	char * aString )
	{
		unsigned int i;

		for( i=0 ; aString[i] !=0; i++)
		LcdWriteChar( aString[i] );
	}

void
LcdWriteChar( char aCharacter )
{
	LCD_PORT_RS |= (1<< LCD_RS);
	LCD_PORT_RW &= ~(1<< LCD_RW);
	LcdOut4Bit( aCharacter );
	LcdOut4Bit( aCharacter << 4 );
	LcdCheckBusy();

}

void
LcdClear( void )
{
	LcdCommand( LCD_CLEAR_DISPLAY);
	DelayMs(LCD_CLEAR_DISPLAY_MS);
}
/*
	Function: LcdSetPosition
	Description: Sets the position of the next characters
	Parameters:
		aRow	-	Row of the display, 1 or 2
		aColumn	-	Column of the display, starting with 0
		*/

void
LcdSetPosition(
	unsigned char aRow,			// bei 4 bit unsigned char effizientesten  //
	unsigned char aColumn) {

		if (aRow == 1 ) {
			LcdCommand( LCD_SET_DDADR + aColumn );
		}
		else {
			LcdCommand( LCD_SET_DDADR + aColumn + LCD_DDADR_LINE2);
		}
	}

/********** Definition of private functions ********/

/*
	Function: LcdOut4Bit
	Description:
	 LcdOut4Bit writes the upper nibble ( Bit 4 to 7 )
	 out to the data lines. Ine enable impulse triggers
	 the transfer.
	Parameters:
	 aByte - The upper 4 databits of this byte are written.
*/
void
LcdOut4Bit(
 unsigned char aByte )
 {
	 LCD_DDR_DATA	|=  ( 0xF << LCD_DB );
	 LCD_PORT_RW	&= ~(    1 << LCD_RW );
	 LCD_PORT_DATA	&= ~( 0xF << LCD_DB );
	 LCD_PORT_DATA	|=  ( (aByte & 0xF0 ) >> ( 4 - LCD_DB) );

	 LcdEnable();
 }

/*
	Function: LcdEnable
	Description:
	 Send an enable impuls with 5�s lenght.

*/
void
 LcdEnable( void )
 {
	 LCD_PORT_EN |= ( 1 << LCD_EN );
	 DelayUs( LCD_MIN_DELAY_US );
	 LCD_PORT_EN &= ~( 1 << LCD_EN );
	 DelayUs( LCD_MIN_DELAY_US );
 }
 
/*
	Function: LcdCommand
	Description:
	Send a command to the display and check the busy flag

	Parameters:
		acmd - The command to be executed.

	Returnvalue:
		ETRUE if the command can be executed otherwise
		EFLASE.

*/


 TBool
 LcdCommand( unsigned char acmd )
 {
	 LCD_PORT_RS &= ~(1 << LCD_RS);
	 LCD_PORT_RW &= ~(1 << LCD_RW);
	 LcdOut4Bit(acmd);
	 LcdOut4Bit(acmd<<4);

	 return LcdCheckBusy();
 }
/*
	Function: LcdCheckBusy
	Description:
		Check the busy flag and return EFALSE if it is not cleared after a time out.
*/
 TBool
 LcdCheckBusy ( void )
 {
	 unsigned int busyCounter = 0;

	 while ( LcdReadBusyFlag() )
	 {
	 if( busyCounter++ > LCD_MAX_BUSY_COUNTER )
		return EFALSE;

		DelayUs( 100 );
	 }

	return ETRUE;
 }
/*
	Function: LcdCheckBusyFlag
	Description:
		Read the busy flag and return EFALSE if it si cleared and ETRUE if it is set.
*/
TBool
LcdReadBusyFlag( void )
{
	unsigned char address;

	address = LcdReadAdress();

	if (address & 0x08 ){
	return ETRUE;
}
	else return EFALSE;
}

/*
Function: LcdReadAddress
Description:
	Read the address
*/

unsigned char LcdReadAdress(void) {

	LCD_PORT_RS &= ~(1 << LCD_RS);
	LCD_PORT_RW |= (1 << LCD_RW);

	unsigned char address;
	address = LcdRead4Bit() & 0xF0;
	address |= (LcdRead4Bit() >> 4);

	return address;
}

/*
	Fuction: LcdRead4Bit();
	Description:
		Read 4 bits of the LCD and return and move it the upper nibble.
*/

unsigned char
LcdRead4Bit( void )
{
	unsigned char data;
	LCD_PORT_RW |= ( 1<< LCD_RW );
	LCD_DDR_DATA &= ~(0xF << LCD_DB );		// 0 einlesen 1 ausgeben
	LCD_PORT_EN |= ( 1 << LCD_EN );
	DelayUs( LCD_ENABLE_US );
	data = LCD_PIN_DATA << (4 - LCD_DB );
	LCD_PORT_EN &= ~( 1 << LCD_EN );
	return data;
	
}