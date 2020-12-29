/* 
u_quer.c
Quersumme 
Ein Programm soll zu einer grösseren positiven Ganzzahl z (z.B.: 8 432 101)
die Quersumme berechnen. 

Man kann das mit den Operatoren  /  und  %  erledigen.

Anwendung : Bei Scheckkartennummern kann man Lesesicherheit dadurch einbauen, 
dass die Quersumme gebildet und z.B. MOD 10 als letzte Ziffer hinzugefügt wird. 
Wird eine Ziffer falsch gelesen, stimmt die Quersumme nicht und die Karte wird zurückgewiesen.
*/

# include <stdio.h>
int main ( ){
	long s ;
	long quer = 0 ;

	printf ("\nQuersummenberechnung: Zahl ? : ") ; 
	scanf ("%ld", &s ) ;
	
	while (s > 0){
		quer = ?????? ;   //rest der div. 10 ist die Einer-stelle der zahl
		s =  ???????;      //zahl durch 10 div --> Einer-stelle faellt weg
	}

	printf ("\nQuersumme = %ld", quer) ;
	
	return 0;
}

