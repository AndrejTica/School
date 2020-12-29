// ahofmann, 2014
// int-txt-struct-sort.c
// sortieren in Arrays
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
void intAusgabe(int* a, int len);
void txtAusgabe(char txt[][80+1], int zeilen);
void structAusgabe(TPERSON* alle, int len);

void intBubbleSort(int* a, int len);
void txtBubbleSort(char txt[][80+1], int zeilen);
void structBubbleSort(TPERSON* alle, int len); // sortiert nach Name


// F-Decl f. qsort
// –-----------------------------------------------------------
int vergl_int(const void* pa, const void* pb);
int vergl_txt(const void* pa, const void* pb);
int vergl_struct_name(const void* pa, const void* pb);


int main(){
	// Array def.
	int arr[]= {7,23,-9,12,3};
	char txt[][80+1]={
		"wiese",
		"wald",
		"blume",
		"baum",
		"pilz"
		};

	TPERSON wir[]={
		{34, 	"zeppelin"},
		{134, "maier"},
		{3, 	"mustermann"},
		{11, 	"wiese"},
		{4, 	"pilz"}
		};

#define BUBBLESORT
#ifdef BUBBLESORT
	printf("\nVOR dem Sortieren mit BUBBLESORT ...\n");
	intAusgabe(arr, sizeof(arr)/sizeof(arr[0]));
	txtAusgabe(txt, sizeof(txt)/sizeof(txt[0]));
	structAusgabe(wir, sizeof(wir)/sizeof(wir[0]));
	
	
	intBubbleSort(arr, sizeof(arr)/sizeof(arr[0]));
	txtBubbleSort(txt, sizeof(txt)/sizeof(txt[0]));
	structBubbleSort(wir, sizeof(wir)/sizeof(wir[0]));
	
	printf("\nNACH dem Sortieren mit BUBBLESORT...\n");
	intAusgabe(arr, sizeof(arr)/sizeof(arr[0]));
	txtAusgabe(txt, sizeof(txt)/sizeof(txt[0]));
	structAusgabe(wir, sizeof(wir)/sizeof(wir[0]));
#endif	
	
#ifdef QSORT
	printf("\nVOR dem Sortieren mit QSORT ...\n");
	intAusgabe(arr, sizeof(arr)/sizeof(arr[0]));
	txtAusgabe(txt, sizeof(txt)/sizeof(txt[0]));
	structAusgabe(wir, sizeof(wir)/sizeof(wir[0]));
	
	
	qsort(arr, sizeof(arr)/sizeof(arr[0]), sizeof(arr[0]), vergl_int);
	qsort(txt, sizeof(txt)/sizeof(txt[0]), sizeof(txt[0]), vergl_txt);
	qsort(wir, sizeof(wir)/sizeof(wir[0]), sizeof(wir[0]), vergl_struct_name);
//	qsort(wir, sizeof(wir)/sizeof(wir[0]), sizeof(wir[0]), vergl_struct_persnr);
	
	
	printf("\nNACH dem Sortieren mit QSORT...\n");
	intAusgabe(arr, sizeof(arr)/sizeof(arr[0]));
	txtAusgabe(txt, sizeof(txt)/sizeof(txt[0]));
	structAusgabe(wir, sizeof(wir)/sizeof(wir[0]));

#endif	

	return 0;
}



void intAusgabe(int* a, int len){
	int i;
	for(i=0; i < len;i++)
		printf("%3i, ", a[i]);
	printf("\n");
}



void txtAusgabe(char txt[][80+1], int zeilen){

}



void structAusgabe(TPERSON* alle, int len){

}

void intBubbleSort(int* a, int len){
	int fertig=0;
	int i, h;
	while(fertig==0){
		fertig=1;
		
		for(i=0; i< len -1; i++){
			if(a[i]>a[i+1]){
				h= a[i];
				a[i]= a[i+1];
				a[i+1]= h;
				
				fertig=0;
			}
		}
	}
}


void txtBubbleSort(char txt[][80+1], int zeilen){

}


void structBubbleSort(TPERSON* alle, int len){

}

// Vergleichsfunktionen f. qsort
// –-----------------------------------------------------------


