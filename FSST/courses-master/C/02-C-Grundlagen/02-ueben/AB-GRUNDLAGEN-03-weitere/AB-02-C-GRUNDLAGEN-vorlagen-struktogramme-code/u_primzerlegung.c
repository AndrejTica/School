/* 
u_primzerlegung.c
Ein Programm soll nach Eingabe einer natürlichen Zahl n,
die Zerlegung von n in Primfaktoren angeben. 

Beispiel für eine Ausgabe zu n = 100 : 
        100 = 2 * 2 * 5 * 5 . 

Man muss dazu keine Primzahlen kennen; 
es genügt, die Teiler d = 2, 3, ... zu testen und im Erfolgsfalle statt 
mit n jeweils nur noch mit n / d  > 1 fortzufahren.
 
Geht ein Teiler (schliesslich) nicht mehr,  nimmt man den nächsten. 

*/

# include <stdio.h>

int main ( ){
	int d , n ;

	printf ("\nPrimfaktorzerlegung der Zahl ..." ) ;
	scanf ("%d", &n) ;
	
	printf ("\n%d = ", n ) ;
	
	d = 2 ; //Beginne mit Faktor 2
	while (n > 1 && d ?????){
		if (?????){
			// d ist ein pfaktor
			printf ("%d", d );
			n = n / ?????? ;
			if (n > 1){
				printf (" * ") ; //multiplikator
			}
		}
		else{
			//versuche naechste zahl
			???? ;
		}
	}
	
	return 0;
}

