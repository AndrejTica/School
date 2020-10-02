/*
1.1.  Aufgabe: strcatdyn
Schreiben Sie eine Funktion mit dem Namen strcatdyn(), die die Zeiger auf 
zwei Zeichenketten entgegen nimmt. 

Die Funktion soll beide Zeichenketten hintereinander in einem von der 
Funktion dynamisch angelegten Speicherbereich kopieren und 
die Adresse auf den Beginn dieses Speicherbereichs zurückgeben. 

Im Fehlerfall soll ein Nullzeiger (NULL) zurückgeben werden. 
Die Verwendung von Stringfunktionen (siehe string.h) ist gewünscht.

char* strcatdyn(const char* str1, const char* str2);

Erstellen Sie ein Testprogramm.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* strcatdyn(const char* str1, const char* str2);

int main(){
	char input1[128+1];
	char input2[128+1];
	
	char* pnew_string;

	printf("1. Text eingeben: ");
	gets(input1);
	
	printf("2. Text eingeben: ");
	gets(input2);
	
	pnew_string= strcatdyn(input1, input2);
	if (pnew_string==NULL){
		fprintf(stderr, "%s:%i:error calling strcatdyn()\n", __FILE__,__LINE__);
		exit(1);
	}
	
	printf("New String: <%s>\n" , pnew_string);
	
	free(pnew_string);

	return 0;
}

char* strcatdyn(const char* str1, const char* str2){
	// enter code

}

