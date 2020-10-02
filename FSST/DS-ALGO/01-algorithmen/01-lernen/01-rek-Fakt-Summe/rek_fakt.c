/*
## 1. Fakultät (v)
* Rekursive Definition
		= 1			wenn n==0
	n!
		= n*(n-1)!	sonst

 * rek_fakt.c
*/

#include <stdio.h> 

// F- Prototyp 
int fakt(int n); 

// F-Aufrufen 
int main(){ 
	int zahl, fakt_zahl; 

	printf("\nFakultaet (rekursiv)"); 
	do{ 
		printf("\nBitte eine pos. Zahl: "); 
		scanf("%i", &zahl); 
	}while (zahl < 0); 


	fakt_zahl= fakt(zahl);
	printf("\n%i! = %i\n\n" , zahl, fakt_zahl);

	putchar('\n'); 
	return 0; 
} 

// F ausprogrammieren 
int fakt(int n){ 
	?????????????
}
