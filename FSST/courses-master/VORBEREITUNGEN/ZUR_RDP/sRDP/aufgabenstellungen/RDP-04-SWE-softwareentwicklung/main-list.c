/*
Gegeben:
typedef struct {char* data; SLIST* next;} SLIST;
typedef struct {SLIST* first; int len; SLIST* last;} SLIST_HEADER;

*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "o_strlist.h"


int main(){
	char* array;	
	SLIST_HEADER * cmdSList;    /* History Liste                  */	
	
	/* --------------------------------------------
	* Liste zur Speicherung der Kommandos erzeugen
	* --------------------------------------------*/
	cmdSList= createSList();
	if (cmdSList == (SLIST_HEADER *) NULL){
		fprintf(stderr,"Not enough memory\n");
		exit(1);
	}
	
	insertLast(cmdSList, "ps");
	insertLast(cmdSList, "kill");
	insertLast(cmdSList, "who");


/* sRDP Vorbereitung
*/
	array= list2array(cmdSList);
	printf("Alle Strings in der Liste: %s\n" , array);

	free(array);

	rm_SList(cmdSList);

	return 0;
}

	

