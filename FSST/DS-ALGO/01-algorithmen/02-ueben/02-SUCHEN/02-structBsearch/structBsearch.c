/*
1.  Übungen zum Suchen in Arrays
Binäre Suche auf Struktur-Arrays in C
Iterative bzw. rekursive Algorithmen
Verwendung der C-Standardbibliothek: bsearch()

1.2.  Aufgabe: structBsearch.c - Die C-Funktion bsearch()
Bringen Sie dieses Programm zum Laufen. 
*/


// structBsearch.c
// Name: 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

typedef struct { 
	int persnr; 
	char name[80]; 
} TPERSON; 


// F-decl 
// Vergleichsfunktionen
// ----------------------------------------------------------------------------- 
int vergl_name(const void* a, const void*b){ 
	?????????????????
} 

int vergl_persnr(const void* a, const void*b){ 
	????????????
} 


// main 
// --------------------------------------------------------------------------------------------------------------- 
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
	 
	pgefunden= bsearch(&search, wirName,??????????????????????????????????); 

	if (NULL==pgefunden){ 
		printf("NOT FOUND: <%s> \n", search.name); 
	} 
	else{ 
		printf("FOUND: %-5d %s\n", pgefunden->persnr, pgefunden->name); 
	} 

// ----------------------------------------------------------------------------- 
	//ausgabe 
	printf("\n\nPERSONS sorted by Persnr .................\n"); 
	for (i=0; i < 5; i++){ 
		printf("%5d: <%s>\n", wirNummer[i].persnr, wirNummer[i].name); 
	} 
	printf("\n"); 
	 
	printf("Enter PersNr to search: "); 
	scanf("%i", & search.persnr); 
	 

	pgefunden= bsearch(&search, wirNummer, ????????????????????????????????); 

	if (NULL==pgefunden){ 
		printf("NOT FOUND: Persnr= <%i> \n", search.persnr); 
	} 
	else{ 
		printf("FOUND: %-5d %s\n", pgefunden->persnr, pgefunden->name); 
	} 



	return 0; 
} 

