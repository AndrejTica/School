/** Ein Testprogramm für Mystring
*   
*  @author Anton Hofmann
*  @date 2010
*  @file test-mystring.c
* 
*  @version 0.2 
*  Alten Code entfernt. 
* 
*  @version 0.1 
*  Kommentare hinzugefügt (Doxygen). 
* 
* 
*  @todo Für Linux und Windows lauffähig machen
* 
*  @warning Lernstoff
* 
*  @test Kann zum Test kommen
*/

#include <stdio.h>
#include <stdlib.h>

#include "mystring.h"

#define MAXCHARS 128

// Linux
//#define PAUSE printf("\nEnter ... ");fgetc(stdin);
//#define CLS system("clear")

// windows
#define PAUSE system("pause")
#define CLS system("cls")


int main(){
	char s1[MAXCHARS+1];
	char s2[MAXCHARS+1];

	int len;

	int ende=0;
	while (ende==0){
		CLS;
		logo();

		//Menu

		printf("\n***** MYSTRING (a.hofmann) ******\n\n");

		printf("   1) Laenge:      int  mystrlen(const char s[])\n");
		printf("   2) Kopieren:    void mystrcpy(char s[], const char t[])\n");
		printf("   3) Anhaengen:   void mystrcat(char s[], const char t[])\n");
		printf("   4) Vergleichen: int  mystrcmp(const char s[], const char t[])\n");
		printf("   5) Umwandeln:   void mystrtoupper(char s[]) \n");
		printf("   6) Palindrom:   int  isPalindrom(const char s[])  (z.B.: otto)\n");
		printf("   7) Sortieren:   void mystrsort(char s[])\n");
		printf("   8) Enthaelt:    int  mystrcontains(const char s[],char ch) \n");
		printf("   9) Caesar:      void mystrcaesar(unsigned char s[],int schluessel) \n");
		printf("   a) Einfuegen:   void mystrchins (char s[],int stelle, char ch) \n");
		printf("   b) Loeschen:    void mystrchdel (char s[],int stelle) \n");
		printf("   0) Ende\n");


		ch= fgetc(stdin);
		fgetc(stdin); //ENTER aus dem tastaturbuffer löschen

		switch(ch){
			case '0':   
				ende=1;
				break;

			case '1':  
				printf("   1) Laenge:      int  mystrlen(const char s[])\n");

				printf("Text ? ");
				gets(s1);

				len= mystrlen(s1);
				printf("\n<%s> ist %i Zeichen lang\n", s1, len);

				PAUSE;
			break;
		


			default:    
				printf("\n**** Falsche Eingabe .... ");
				PAUSE;

		} //end switch

	} // while

	return 0;
}//end main

