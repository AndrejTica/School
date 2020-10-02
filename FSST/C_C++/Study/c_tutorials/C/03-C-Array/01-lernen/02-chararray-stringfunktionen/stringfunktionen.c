/* =====================================================================
 Name        : stringfunktionen.c
 Author      : ahofmann
 Version     :
 Copyright   : open source
 Description : Stringfunktionen
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
	int istGleich;
	int iZahl;
	double dZahl;
	double realTeil, imaginaerTeil;


	puts("\nSTRINGFUNKTIONEN:");
	puts("// ----------------------------------------------------");
	puts("// strlen, strcpy, strcat, strcmp");
	puts("// ----------------------------------------------------");

	puts("\nText?");
	gets(s1);

	printf("\n\n// laenge ermitteln --------------------------");
	//	len=0;
	//	while (s1[len] != '\0')
	//		len++;

	len=strlen(???????????????!!!!!!!!!!!!!!!!!!!
	printf("\nDer Text <%s> hat %i Zeichen", s1, len);

	printf("\n\n// kopieren: s1 nach s2 kopieren ----------------------------");
	//	for(i=0; s1[i] != '\0' ; i++){
	//		s2[i]= s1[i];
	//	}
	//	s2[i]= '\0';
	strcpy(????????????????????!!!!!!!!!!!!!!!1
	printf("\nText: <%s>\nText: <%s>", s1, s2);


	printf("\n\n// anhaengen s1 bei s2 anhaengen ----------------------------");
	//  len=strlen(s2);
	//	for(i=0; s1[i] != '\0' ; i++){
	//		s2[i+len]= s1[i];
	//	}
	//	s2[i+len]= '\0';
	strcpy(????????????????????!!!!!!!!!!!!!!!1



	printf("\n\n//vergleichen --------------------------");
	puts("\nText?");
	gets(s3);

	//	istGleich=1;
	//	for(i=0; s1[i] != '\0' && istGleich ; i++){
	//		if (s1[i] != s3[i])
	//			istGleich=0;
	//	}
	//	if (istGleich==1){ // Abbruch d. Schleife war EOS von s1
	//		istGleich= (s3[i]=='\0');  // auch s3 muss am ende sein
	//	}

	istGleich= strcmp(??????????????????????????
	if (istGleich== ??????????????????????){
		printf("\nGLEICH: \n<%s>\n<%s>", s1, s3);
	}
	else{
		printf("\nUNGLEICH: \n<%s>\n<%s>", s1, s3);
	}


	puts("\n\nWEITERE STRINGFUNKTIONEN");
	puts("// ----------------------------------------------------");
	puts("// Typkonvertierung mit sprintf(), sscanf()");
	puts("// ----------------------------------------------------");

	// int → string
	sprintf(s1, "%i", 4711);
	// string → int
	sscanf(s1, "%i", &iZahl);

	printf("\nDie int-Zahl %i als Text %s", iZahl, s1);


	// double → string
	sprintf(s1, "%.2lf", 47.11);
	// string → double
	sscanf(s1, "%lf", &dZahl);

	printf("\nDie double-Zahl %.2lf als Text %s", dZahl, s1);


	// ein weiteres Beispiel
	realTeil= 11.1;
	imaginaerTeil= 99.9;

	sprintf(s1, "%.2lf+%.2lfi", realTeil, imaginaerTeil);
	printf("\nDie KomplexZahl als Text %s", s1);

	// Demo für das Einlesen v. vorformatierten Texten (Bsp: 11.1+99.9i)
	// es soll der Real und Imaginärteil gelesen werden.
	realTeil=0.0;
	imaginaerTeil=0.0;

	sscanf(s1, "%lf+%lfi",  &realTeil, &imaginaerTeil);
	printf("\nRealteil= %.2lf", realTeil);
	printf("\nImaginärteil= %.2lf", imaginaerTeil);

	printf("\n\n");

	return EXIT_SUCCESS;
}

