// a.hofmann
// 2009
// smk_ziffernsumme.c

#include <stdio.h>
#include <string.h>


// Funkt. Deklaration
int getZiffernSumme(char s[]);

int main(){
	int sum;
	char text[128];
	
	// einlesen
	printf("Text mit Ziffern eingeben: ");
	fgets(text, 128, stdin);
	text[strlen(text) -1]= '\0';   // wegen enter
	
	// Aufruf der Funktion
	sum= getZiffernSumme(text);

	// ausgabe
	printf("Ziffernsumme von %s = %i\n", text, sum);
	
	return 0;
}

// ausprogrammierte Funktionen
int getZiffernSumme(char s[]){
	int sum=0;
	int i;
	
	for(i=0; s[i] != '\0' ;i++){
		sum= sum + (s[i] - '0');
	}

	return sum;	
}


