/*
 * AUTHOR: 
 * DATE:
 * FILE: rek_palin.c
  
	1.3.2.  Aufgabe: rek_palin.c
	Erstellen Sie eine rekursive Funktion namens 
	
	int rek_palin(char w[], int erstes, int letztes),
	
	die rekursiv prüfen soll, ob ein gegebenes Wort ein Palindrom ist 
	(vorwärts gelesen==rückwärts gelesen). Ihr wird das Wort w übergeben und
	die Stelle des ersten und des letzten Zeichens. Stimmen beide überein, 
	so kann man mit dem Prüfen des verkürzten Wortes fortfahren.
	Schreiben Sie ein Testprogramm, um die Funktion zu testen.

	Hinweis:
	man strlen
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

bool rek_palin(char w[], int erstes, int letztes){

	// ENTER CODE HERE

}




int main(){	
	printf("\nSTART testing rek_palin ...\n"); system("date");fflush(stdout);


	assert( rek_palin("12321", 0, 4) == true && "Testing: 12321");	
	assert( rek_palin("1111111111", 0, 9) == true && "Testing: 1111111111");	
	assert( rek_palin("1", 0, 0) == true && "Testing: 1");
	assert( rek_palin("12345", 0, 4) == false && "Testing: 12345");
	
	printf("\nEND testing rek_palin ...\n"); system("date");fflush(stdout);
	printf("\nAll Tests are OK ...\n\n");
	
	return 0;
}
