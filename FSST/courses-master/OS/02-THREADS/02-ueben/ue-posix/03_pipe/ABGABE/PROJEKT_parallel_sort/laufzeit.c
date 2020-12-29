// laufzeit.c

#include <stdio.h>
#include <time.h>

int main(){
 long i;
 float zeit;
 
 clock_t start, ende;
 
 /*start bekommt die aktuelle CPU-Zeit*/
 start = clock();

 /*Hier sollte der ausführbare Code stehen für die
   Laufzeitmessung*/

 /*Wir verwenden einfach ein Schleife*/
 for(i=0; i<200000000; i++)
           ;

 /*stop bekommt die aktuelle CPU-Zeit*/
 ende = clock();
 
 /*Ergebnis der Laufzeitmessung in Sekunden*/

 zeit = (float)(ende-start) /  (float)CLOCKS_PER_SEC;

 printf("Die Laufzeitmessung ergab %.2f Sekunden\n",zeit);

 return 0;
}