/*
 * N.N.
 * 2019

Aufgabe: mystr_ersetze.c
Schreiben Sie ein Testprogramm und die Funktion mystr_ersetze(). 

Sie soll als Input einen Text und das zu ersetzende Zeichen bekommen und 
folgendes zurückgeben:

    • Anzahl der ersetzten Zeichen und
    • Die Adresse des Textes.

(also 2 Rückgabewerte. D.h: wir müssen mittels call-by-reference arbeiten)

Hier die Funktionsdeklaration:

char* mystr_ersetze(char* s, char old, char new, int* anzahl);

(Anm: anzahl wird mittels call-by-reference übergeben)

    • Erstellen Sie ein kleines Testprogramm und
    • programmieren Sie die Funktion mystr_ersetze aus.

 */
 
#include <stdio.h>


char* mystr_ersetze(char* s, char old, char new, int* anzahl);

 
int main(){

	char txt[128+1]= "hello edi";
	char* p;
 	int anz_chars;
 	
 	printf("Der alte Text: %s\n" , ___________);
 	
 	p= mystr_ersetze(txt, 'e', 'a', ______________);
 	
 	printf("Der ersetzte Text: %s\n" , ___________);
 	printf("Anzahl der ersetzten Zeichen: %i\n\n", anz_chars);
 
 	return 0;
}

char* mystr_ersetze(char* s, char old, char new, int* anzahl){





}


