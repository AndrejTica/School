// ahofmann, 2014
// ptrSort.c
// sortieren in Arrays mit Zeiger-Array
// bubblesort
// qsort

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Type decl
// –-----------------------------------------------------------
typedef struct {
	int persnr;
	char name[80+1];
} TPERSON;

// F-Decl.
// –-----------------------------------------------------------
void structAusgabe(TPERSON** palle, int len);

void structBubbleSort(TPERSON** palle, int len); // sortiert nach Name


// F-Decl f. qsort
// –-----------------------------------------------------------
int vergl_struct_name(const void* pa, const void* pb);


int main(){
	// Array def.
	TPERSON wir[]={
		{34, 	"zeppelin"},
		{134, "maier"},
		{3, 	"mustermann"},
		{11, 	"wiese"},
		{4, 	"pilz"}
		};

	// Array mit den Adressen
	TPERSON* pwir[]={????????????????????????????????};

		
#define BUBBLESORT
#ifdef BUBBLESORT
	printf("\nVOR dem Sortieren mit BUBBLESORT ...\n");
	structAusgabe(pwir, sizeof(pwir)/sizeof(pwir[0]));
	
	
	structBubbleSort(pwir, sizeof(pwir)/sizeof(pwir[0]));
	
	printf("\nNACH dem Sortieren mit BUBBLESORT...\n");
	structAusgabe(pwir, sizeof(pwir)/sizeof(pwir[0]));
#endif	
	
#ifdef QSORT
	printf("\nVOR dem Sortieren mit QSORT ...\n");
	structAusgabe(pwir, sizeof(pwir)/sizeof(pwir[0]));
		
	qsort(pwir, sizeof(pwir)/sizeof(pwir[0]), sizeof(pwir[0]), vergl_struct_name);
	
	
	printf("\nNACH dem Sortieren mit QSORT...\n");
	structAusgabe(pwir, sizeof(pwir)/sizeof(pwir[0]));

#endif	

	return 0;
}


void structAusgabe(TPERSON** palle, int len){
	int i;
	for(i = 0; i < len; i++){
		printf("%20s:%5i\n", ????????????????????????????);
	}
	printf("\n");
}




void structBubbleSort(TPERSON** palle, int len){

	
}



// Vergleichsfunktionen f. qsort
// –-----------------------------------------------------------

int vergl_struct_name(const void* pa, const void* pb){

	//?????????????????????????????????
	
	return 0;
}
