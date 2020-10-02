/******************************************************************************************************************************************
	File: Lcd.h
	Description:
		Driver for an alphanumeric LCD with paralell interface. Only 4Bit Interface is supported.
*******************************************************************************************************************************************/

#ifndef	LCD_H		//
#define LCD_H



void
LcdInit( void );

void
LcdWriteString(
	char * aString );

void
LcdClear( void );

void
LcdWriteChar( char aCharacter );

void
LcdSetPosition(
	unsigned char aRow,			// bei 4 bit unsigned char effizientesten  //
	unsigned char aCalumn);	

#endif	





 
 
