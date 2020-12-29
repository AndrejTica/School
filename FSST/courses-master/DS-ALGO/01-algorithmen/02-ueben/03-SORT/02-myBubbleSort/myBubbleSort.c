/**
 * myBubbleSort.c

1.2.  Aufgabe: myBubbleSort 
Schreiben Sie eine Sortierfunktion, die beliebige Arrays sortieren kann.
void myBubbleSort(void* a, int nelements, int nsize, int (*comp)(const void*, const void*));

Hinweis: siehe: memcpy(), malloc(), free()
Testen Sie ihre Funktion mit dem folgenden Test-Programm
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct pers{
	int persnr;
	char name[80+1];
} TPERSON;


// sort function
void myBubbleSort(void* a, int nelements, int nsize, int (*comp)(const void*, const void*));

// compare function



#define ANZ 5
int main(int argc, char *argv[]){
    int a[ANZ];

    int i;    

    TPERSON wir[5]= {{23, "Geher"}, {3, "Singer"}, {23, "Bierer"}, 
		{-23, "Maurer"},{93, "Ziegler"}};
  

    srand(time(NULL));
    for (i=0; i < ANZ; i++)
        a[i]= rand()%100;
        

    myBubbleSort(a, ANZ, sizeof(a[0]), (int (*)(const void*, const void*)) vergleiche);
    
    printf("\nINT Array sortiert ************************************\n");
    for (i=0; i < ANZ; i++)
        printf("%d ", a[i]);
    printf("\n");



    myBubbleSort(wir, ANZ, sizeof(wir[0]), 
				(int (*)(void*,void*)) vergleiche_persnr);
    
    printf("\nPERSON nach persnr sortieren  *************************\n");
    for (i=0; i < ANZ; i++)
        printf("%3d %s\n", wir[i].persnr, wir[i].name);

    printf("\n");                	

    return 0;
}

void myBubbleSort(void* a, int nelements, int nsize, int (*comp)(const void*, const void*)){
	// todo
	return 0;
}

