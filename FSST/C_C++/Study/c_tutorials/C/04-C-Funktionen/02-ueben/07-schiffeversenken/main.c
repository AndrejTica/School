/*
* main.c
* ahofmann, 2013
*
* schiffe versenken
*/

#include <stdio.h>
#include <string.h>
#include "spiel.h"


int main(){
	char name[128];
	int ready=0;

	printf("\n*** Schiffe versenken ***\n");
	printf("name: ");
	fgets(name, 128, stdin);
	name[strlen(name)-1]= '\0';

	newGame(name);

	while( ! ready){

		ready= doLogic();
	}

	return 0;
}


