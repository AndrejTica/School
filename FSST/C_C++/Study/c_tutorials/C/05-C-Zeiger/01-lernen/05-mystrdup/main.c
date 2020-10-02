/*
 * N.N.
 * 2019

Aufgabe: mystrdup.c
bringen Sie folgendes Programm zum Laufen.
*/

#include <stdio.h>
??????????????????

char* mystrdup(const char* );

int main(){
	char str[128];
	char* p;	
	
	printf("\nstrdup-test: Bitte einen Text: ");
	gets(str);
	
	p= mystrdup(str);
	if (NULL==p){ 
		printf("Error"); exit(1);
	}
	printf("\nmystrdup() lieferte: <%s>\n", p);
	
	?????????????????????(p);
	
	return 0;
}

/*
1. schau, wie lange der string in s ist? tipp: int strlen(const char*);
2. hole Speicher vom Betriebssystem: tipp: void* malloc(int);
3. string s in den neuen Speicher kopieren tipp: char* strcpy(char* ziel, const char* quelle);
4. gib neuen speicher mit return zurueck
*/
char* mystrdup(const char* s){
	// ENTER CODE
	
}
