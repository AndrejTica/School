// A.hofmann okt. 2002
// Taschenrechner   : umgekehrte polnische Notation
// testprogramm     : test_taschenrechner.c
// verwendete Module: doubleStack.c, doubleStack.h
#include <stdio.h>
#include <ctype.h>		// wegen isdigit()
#include <stdlib.h>		// wegen atof()
#include "doubleStack.h"

#define IL_MAX   20
#define END_CHAR '='

????????? getline(?????????????????????????){
	// ---------------------------------------------------------------
	// input     : char-Vektor , laenge des char-Vektors
	// output    : wenn eine zahl eingegeben wurde -> '0'
	//             wenn ein operator (+,-,...)     -> der jeweilige operator
	scanf ("????????????", ????????????str);
	if (isdigit(str[0]))
		return(?????????????????????);
	else
		return(???????????????????????);
}

	// ---------------------------------------------------------------------------
int  main(){
   double  op2;			// operand zum zwischenspeichern
   char input_line[IL_MAX]; 	//Eingabe
   char ch; 			//return wert v. getline()

   // --------- initialisiert den Stack
   init();
   printf("\nTaschenrechner: Geben Sie Zahlen in umgekehrter polnischer Notation ein.\n");
   printf("\npostfix: 12 2 * 4 + 2 / = \ndies entspricht: (12 * 2 + 4) / 2   Ergebnis=14.00");
   do {
      ch=getline(input_line,IL_MAX);

      switch(???????????){
         case '+':
            push(pop()+pop());
            break;
         case '-':
            ?????????????????????
         case '*':
            ?????????????????????
         case '/':
            ?????????????????????
         case '0':
            push(atof(input_line));
            break;
         case END_CHAR:
            printf("\nErgebnis = %.2lf \n\n",pop());
            break;
         }
      } while (input_line[0]!=END_CHAR);
} /* main() */
