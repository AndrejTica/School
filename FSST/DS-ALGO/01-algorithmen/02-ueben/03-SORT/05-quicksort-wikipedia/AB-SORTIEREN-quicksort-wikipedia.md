# AUFGABE: Quicksort-Wikipedia
---
(AB-SORTIEREN-quicksort-wikipedia.md)


## Aufgabe: Quicksort - Wikipedia
Gegeben sei der Pseudocode von quicksort (siehe ANLAGE_quicksort)
1. Erklären/Beschreiben Sie den Algorithmus Quicksort in eigenen Worten.
2. Vergleichen Sie den Aufwand des Algorithmus im Vergleich zum Bubblesort und
verwenden Sie dabei die sogenannte BIG-O Notation.
3. Programmieren Sie ein Test-Programm test-quicksort-wikipedia.c

**Hint: Big O Notation**
* <http://programmierblog.blogspot.co.at/2013/02/einfuhrung-in-die-o-notation-big-o.html>

**Hint: quicksort**
* <https://de.wikipedia.org/wiki/Quicksort>


** test-quicksort-wikipedia.c **

```c

// test-quicksort-wikipedia.c
// --------------------------------------------
#include <stdio.h>
int main(){
	int a[]={20,3,58,26,2,62};
	int i;

	printf("\nUNSORTIERT ...\n")
	for(i=0; i < 6; i++)
	   printf("%3i,", a[i]);
	printf("\n");

	quicksort( a, 0, 5);

	printf("\nSORTIERT ...\n")
	for(i=0; i < 6; i++)
	   printf("%3i,", a[i]);

	printf("\n");
	return 0;
}
```

# ANLAGE_quicksort
---
```c
funktion quicksort(links, rechts)
     falls links < rechts dann
         teiler:= teile(links, rechts)
         quicksort(links, teiler-1)
         quicksort(teiler+1, rechts)
     ende
 ende



funktion teile(links, rechts)
   i:= links
   // Starte mit j links vom Pivotelement
   j:= rechts - 1
   pivot:= daten[rechts]

   wiederhole

       // Suche von links ein Element, welches größer als das Pivotelement ist
       wiederhole solange daten[i] ≤ pivot und i < rechts
           i:= i + 1
       ende

       // Suche von rechts ein Element, welches kleiner als das Pivotelement ist
       wiederhole solange daten[j] ≥ pivot und j > links
            j:= j - 1
       ende

       falls i < j dann
           tausche daten[i] mit daten[j]
       ende

   solange i < j // solange i an j nicht vorbeigelaufen ist

   // Tausche Pivotelement (daten[rechts]) mit neuer endgültiger Position (daten[i])

   falls daten[i] > pivot dann
           tausche daten[i] mit daten[rechts]
   ende

   // gib die Position des Pivotelements zurück

   antworte i
ende
```
