/*
AB-qsort-myBubbleSort-bsearch-myBsearch.c
===========================================================================

Aufgabe:

1. Verwenden Sie im folgenden Testbeispiel die C-Standardfunktionen
	qsort() und bsearch.
	Testen Sie das Programm durch
	#define AUFGABE1
	//#define AUFAGBE2

2. Verwenden Sie nun ihre eigenen Funktionen myBubbleSort(), myBsearch().
	Testen Sie das Programm durch
	//#define AUFGABE1
	#define AUFGABE2


	Hinweis: siehe: qsort(), bsearch(), memcpy(), malloc(), free()
*/

// Einstellungen
// -----------------------------------------
#define AUFGABE1
//#define AUFGABE2



#include <stdlib.h>
#include <stdio.h>



// F-Decl
// ------------------------------------------------------------------------
void myBubbleSort(void* a, int nelements, int nsize, 
				int (*comp)(const void*, const void*));

void* myBsearch(void* key, void* a, int nelements, int nsize, 
				int (*comp)(const void*, const void*));


// struct-Decl
// ------------------------------------------------------------------------
struct pers{ int persnr; char name[128+1];};
typedef struct pers TPERSON;


// Hier das Testprogramm:
// ------------------------------------------------------------------------
#define ANZ 5


int main(int argc, char *argv[]){
// Für die Suche
	int isearch;
	int* ifound;

	TPERSON psearch;
	TPERSON* pfound;

// Die Arrays: a, wir
    int i;    
    int a[ANZ];
    TPERSON wir[5]= {{23, "Geher"}, {3, "Singer"}, {23, "Bierer"}, 
		{-23, "Maurer"},{93, "Ziegler"}};
  
    srand(time(NULL));
    for (i=0; i < ANZ; i++)
        a[i]= rand()%100;


#ifdef AUFGABE1
	printf("\nDie Arrays unsortiert ....\n");
    for (i=0; i < ANZ; i++)
		printf("%3i," , a[i]);
    printf("\n");
    for (i=0; i < ANZ; i++)
		printf("%3i:<%s>\n," , wir[i].persnr, wir[i].name);
    printf("\n");
	

	// 1. Aufgabe: Die C-Standardfunktion verwenden
	// int-Array: a sortieren
	//	qsort(?????????????????????????????????????????????????);  
	// TPERSON-Array: wir nach persnr sortieren
	//	qsort(?????????????????????????????????????????????????);  


    printf("\nINT Array sortiert ************************************\n");
    for (i=0; i < ANZ; i++)
        printf("%3i,", a[i]);
    printf("\n");
    
    printf("\nPERSON nach persnr sortieren  *************************\n");
    for (i=0; i < ANZ; i++)
        printf("%3d %s\n", wir[i].persnr, wir[i].name);
#endif


#ifdef AUFGABE2
    printf("\nINT-Array unsortiert ***********************************\n");
    for (i=0; i < ANZ; i++)
		printf("%3i," , a[i]);
    printf("\n");
    printf("\nTPERSON-Array unsortiert *******************************\n");
    for (i=0; i < ANZ; i++)
		printf("%3i:<%s>\n," , wir[i].persnr, wir[i].name);
    printf("\n");
	

	// 2. Aufgabe: Die eigene Funktion verwenden
	// int-Array: a sortieren
	//	myBubbleSort(??????????????????????????????????????);
	// TPERSON-Array: wir nach persnr sortieren
	//	myBubbleSort(??????????????????????????????????????);


    printf("\nINT-Array sortiert *************************************\n");
    for (i=0; i < ANZ; i++)
        printf("%3i,", a[i]);
    printf("\n");
    
    printf("\nTPERSON-Array: nach persnr sortieren  ******************\n");
    for (i=0; i < ANZ; i++)
        printf("%3d %s\n", wir[i].persnr, wir[i].name);

#endif


#ifdef AUFGABE1
	printf)"\nINT-ARRAY: SUCHE nach dem Wert 5 mit bsearch()....");
	isearch= 5;
	ifound= bsearch(&isearch, ????????????????????????);
	if (ifound){
		printf("%i gefunden\n" , *ifound);
	}else{
		printf("LEIDER nicht gefunden\n");
	}

	printf)"\nTPERSON-ARRAY: SUCHE nach persnr 5 mit bsearch()....");
	int* found;

	psearch.persnr=5;
	pfound= bsearch(&psearch, ????????????????????);
	if (pfound){
		printf("%i gefunden\n" , *found);
	}else{
		printf("LEIDER nicht gefunden\n");
	}
#endif

#ifdef AUFGABE2
	printf)"\nINT-ARRAY: SUCHE nach dem Wert 5 mit bsearch()....");
	isearch= 5;
	ifound= myBsearch(&isearch, ????????????????????????);
	if (ifound){
		printf("%i gefunden\n" , *ifound);
	}else{
		printf("LEIDER nicht gefunden\n");
	}

	printf)"\nTPERSON-ARRAY: SUCHE nach persnr 5 mit bsearch()....");
	int* found;

	psearch.persnr=5;
	pfound= myBsearch(&psearch, ????????????????????);
	if (pfound){
		printf("%i gefunden\n" , *found);
	}else{
		printf("LEIDER nicht gefunden\n");
	}
#endif

    printf("\n");                	
    return 0;
}

