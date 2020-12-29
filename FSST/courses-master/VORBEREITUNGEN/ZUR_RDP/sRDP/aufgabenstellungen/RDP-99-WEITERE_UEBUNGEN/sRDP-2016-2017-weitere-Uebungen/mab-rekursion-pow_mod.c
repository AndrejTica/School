/*
mab-rekursion-pow_mod.c
---------------------------------------------------------------------------

Aufgabe: Potenzieren mit int pow_mod(int x, int k, int b)
---------------------------------------------------------
In der Kryptografie benötigt man ganzzahlige Potenzen x hoch k mod b.

Definieren Sie die Funktion

	int pow_mod(int x, int k, int b)

zur Berechnung ganzzahliger Potenzen für positive Zahlen. 
Für die Berechnung soll ausschliesslich ganzzahlige Arithmetik verwendet 
werden, um Rundungsfehler zu vermeiden.

Es sollen zudem keine Überläufe vorkommen.

Prüfen Sie die Lösung mit den folgenden Beispielen:

	3 hoch 4 mod 5 = 1
	17 hoch 23 mod 13 = 19967568900859523802559065713 mod 13=10
	3 hoch 1733885101 mod 5 = 3


Die Lösung: 
-----------
Um nicht zu grosse Zahlen zu erhalten verwenden wir den
square_multiply Algorithmus

	x hoch k = (x hoch 2) hoch k/2		für gerade k
	x hoch k = x*(x hoch (k-1)) 		für ungerade k

Hinweis: Überlauf
Da es bei der Multiplikation zu einem Überlauf kommen kann,
verwenden wir in der Funktion den Datentyp long (java) bzw. 
long long int (C: http://gcc.gnu.org/onlinedocs/gcc/Long-Long.html).
************************************************************************/

#include <stdio.h>

int pow_mod (int x, int k, int b){
	long long int xL= x;
	long long int erg= 1L;
	
	while (k > 0){
		if (k%2 ==0){	
			// k wird halbiert und xL wird quadriert
			k= k / 2;
			xL= (xL*xL) % b; 	// xL*xL könnte zu einem int-Überlauf führen
								// daher long long int xL
		}
		else {
			// k wird dekrementiert und xL zum Ergebnis multipliziert
			k= k-1;
			erg= (erg * xL) % b ;
		}
	}
	return (int) erg;
}

int pow_mod_rek (int x, int k, int b){
	// TODO
	// ??????????????????????
	return 1;
}

int main(){
	int erg1, erg2, erg3;
	
	printf("ITERATIV --------------------------------------\n\n");
	erg1= pow_mod(3, 4, 5);
	erg2= pow_mod(17 , 23 , 13);
	erg3= pow_mod(3, 1733885101, 5);

	printf("\n\n3 hoch 4 mod 5 = 1 lieferte %i", erg1);
	printf("\n17 hoch 23 mod 13 = 19967568900859523802559065713 mod 13=10 lieferte %i", erg2);
	printf("\n3 hoch 1733885101 mod 5 = 3 lieferte %i\n\n", erg3);

	printf("REKURSIV --------------------------------------\n\n");
	erg1= pow_mod_rek(3, 4, 5);
	erg2= pow_mod_rek(17 , 23 , 13);
	erg3= pow_mod_rek(3, 1733885101, 5);

	printf("\n\n3 hoch 4 mod 5 = 1 lieferte %i", erg1);
	printf("\n17 hoch 23 mod 13 = 19967568900859523802559065713 mod 13=10 lieferte %i", erg2);
	printf("\n3 hoch 1733885101 mod 5 = 3 lieferte %i\n\n", erg3);

	return 0;
}

