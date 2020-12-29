/*
## AUFGABE: dez2bin (v)
---

Um eine Dezimalzahl in eine Dualzahl umzuwandeln, kann man 
folgendermaßen vorgehen:

	13	:	2	= 	6	REST: 1	Stelle: 0
	6	:	2	=	3	REST: 0	Stelle: 1
	3	:	2	=	1	REST: 1	Stelle: 2
	1	:	2	=	0	REST: 1	Stelle: 3

Die Dualzahl lautet also: 1101

	Kontrolle: 	1*2^3 + 1*2^2 + 0*2^1 + 1*2^0=
			1*8 + 1*4 + 0*2 + 1*1 = 
			8 + 4 + 1=
			13

Schreiben Sie die rekursive Funktion 

`void dez2bin(int n)` 
*/

#include <stdio.h> 

// F- Prototyp 
void dez2bin(int n); 

// F-Aufrufen 
int main(){ 
	int zahl,i; 

	printf("\nDez2bin (rekursiv)"); 
	do{ 
		printf("\nBitte eine pos. Zahl: "); 
		scanf("%i", &zahl); 
	}while (zahl < 0); 


	dez2bin(zahl);

	putchar('\n'); 
	return 0; 
} 

// F ausprogrammieren 
void dez2bin(int n){ 
	?????????????
}
