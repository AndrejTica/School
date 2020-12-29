/* =====================================================================
 Name        : chararray.c
 Author      : ahofmann
 Version     :
 Copyright   : open source
 Description : Arrays und Texte in C
======================================================================*/

/*
Erstellen Sie ein Programm, das

3 char-arrays mit 128 Elementen definiert
von der Tastatur Text in das erste Array einliest.

Bestimmt wie lang der eingegebene Text ist und diese ausgibt
das erste char-Array in das zweite char-Array kopiert und beide ausgibt
das erste char-Array in das zweite char-Array anhaengt und beide ausgibt

von der Tastatur Text in das dritte Array einliest.
ausgibt, ob das erste Array und das dritte Array den gleichen Inhalt haben.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // !!!!!!!!!!!!!!!!!!!

int main(void) {
	char s1[128];
	char s2[128];
	char s3[128];
	int len;
	int i;


	puts("\nchar-Arrays und Texte in C:");
	puts("// ----------------------------------------------------------------");

	puts("\nText?");
	gets(s1);

	printf("\n\n// laenge ermitteln -----------------------------------------");
	// ???????????????????
	printf("\nDer Text <%s> hat %i Zeichen", s1, len);



	printf("\n\n// kopieren: s1 nach s2 kopieren ----------------------------");
	// ???????????????????
	printf("\nText1: <%s>\nText2: <%s>", s1, s2);


	printf("\n\n// anhaengen s1 bei s2 anhaengen ----------------------------");
	// ???????????????????
	printf("\nText1: <%s>\nText2: <%s>", s1, s2);


	printf("\n\n//vergleichen --------------------------");
	puts("\nText?");
	gets(s3);
	// ???????????????????

	if (istGleich== ??????????????????????){
		printf("\nGLEICH: \n<%s>\n<%s>", s1, s3);
	}
	else{
		printf("\nUNGLEICH: \n<%s>\n<%s>", s1, s3);
	}


	printf("\n\n");

	return EXIT_SUCCESS;
}

