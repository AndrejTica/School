/*
1.  Übungen zum Suchen in Arrays
Binäre Suche auf Struktur-Arrays in C
Iterative bzw. rekursive Algorithmen
Verwendung der C-Standardbibliothek: bsearch()

1.1.  Aufgabe: structMyBsearch.c (iterativ,rekursiv)
Bringen Sie das folgende Programm zum Laufen.
*/

// structMyBsearch.c
// Name: 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int persnr;
	char name[80];
} TPERSON;


// F-decl
// ------------------------------------------------------------------------
TPERSON* myBsearchName(TPERSON* key, TPERSON* a, int left, int right) {
	// gesucht wird nach der Strukturkomponente name
	// wenn key->name im Array a vorhanden ist, wird
	// die Adresse des gefundenen Elementes in a zurückgegeben.
	// wenn nicht vorhanden, wird NULL zurückgegeben.

	// Algorithmus: binäre Suche (iterativ)

	?????????????????????????  
}


TPERSON* 
myBsearchPersonNrRek(TPERSON* key, TPERSON* a, int left, int right){
	// gesucht wird nach der Strukturkomponente persnr
	// wenn key->persnr im Array a vorhanden ist, wird
	// die Adresse des gefundenen Elementes in a zurückgegeben.
	// wenn nicht vorhanden, wird NULL zurückgegeben.

	// Algorithmus: binäre Suche (rekursiv)

	???????????????????????
}



// main
// --------------------------------------------------------------------
int main(){
	// WEIL die Arrays für die binäre Suche sortiert sein müssen,
	//	verwenden wir 2 Arrays:

TPERSON wirName[5]= {
    {23, "Bierer"},
    {23, "Geher"},
    {-23, "Maurer"},
    {3, "Singer"},
    {93, "Ziegler"}
    };

TPERSON wirNummer[5]= {
    {-23, "Maurer"},
    {3, "Singer"},
    {23, "Geher"},
    {23, "Bierer"},
    {93, "Ziegler"}
    };

	TPERSON* pgefunden;
	TPERSON search;

	int i;
	
	//ausgabe
	printf("PERSONS sorted by Name .................\n");
	for (i=0; i < 5; i++){
		printf("%5d: <%s>\n", wirName[i].persnr, wirName[i].name);
	}
	printf("\n");
	
	printf("Enter Name to search: ");
	scanf("%s", search.name);
	
	pgefunden= myBsearchName(&search, wirName, 0, 4);

	if (NULL==pgefunden){
		printf("NOT FOUND: <%s> \n", search.name);
	}
	else{
		printf("FOUND: %-5d %s\n", pgefunden->persnr, pgefunden->name);
	}

// ---------------------------------------------------------------------
	//ausgabe
	printf("\n\nPERSONS sorted by Persnr .................\n");
	for (i=0; i < 5; i++){
		printf("%5d: <%s>\n", wirNummer[i].persnr, wirNummer[i].name);
	}
	printf("\n");
	
	printf("Enter PersNr to search: ");
	scanf("%i", & search.persnr);
	

	pgefunden= myBsearchPersonNrRek(&search, wirNummer, 0, 4);

	if (NULL==pgefunden){
		printf("NOT FOUND: Persnr= <%i> \n", search.persnr);
	}
	else{
		printf("FOUND: %-5d %s\n",pgefunden->persnr, pgefunden->name);
	}

	return 0;
}

