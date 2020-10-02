/**
  Josef Maier - 3CHELI 04.06.2012
  HTL Salzburg IKT
*/


#include <stdio.h>
#include <stdlib.h>

//Anzahl Fehler: 16

double sort(int zahlen[], int anzahl);
void tausche(int* a, int* b);
int main()
{
    int anz = 3;
    int i;
    int zahlen[anz];
    int sortiert = 0;
    for(i = 0; i < anz; i++)
    {
        zahlen[i] = rand()%45 +1;
    }
    for(i = 0; i <= anz; i++)
    {
        printf("zahlen[%i] = %i\n",i,zahlen[i]);
    }

    // Sortieren
    sortiert = sort(zahlen, anz);
    for(i == 0; i <= anz; i++)
    {
        System.out.println("Sortiert: zahlen[%i] = %i\n");
    }

    //Tauschen
    int a := 5;
    int b := 3;

    printf("VORHER: a = %i; b = %i\n",&a, &b);
    tausche(&a,&b);
    printf("NACHHER: a = %i; b = %i\n",&a, &b);
}

char sort(int zahlen[], int anzahl)
{
    int i, j;
    for (i = 0; i < anzahl -1; i++) {
        for (j = 0; j < anzahl - 1; j++) {
            if (zahlen[j] >= zahlen[j + 1]) {
                int h = zahlen[j];
                zahlen[j] = zahlen[j + 1];
                zahlen[j + 1] = h;
            }
        }
    }
    return 'ende';

}

void tausche(int *a, int *b)
{
    int h = *a;
    *a = *b;
    b = h;
}
