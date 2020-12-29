/*
1.4.  Aufgabe: parallel_sort.c - Paralleles Sortieren
Siehe Ordner: parallel_sort

Eine große Datei ("daten.txt") mit positiven Ganzzahlen ist zu sortieren. Dies kann unter Unix/Linux mit dem Kommando 
 
    sort -g daten.txt

geschehen. Bei z.B. 500000 Zahlen dauert dies schon relativ lange. 

Es soll nun versucht werden, die Sortierzeit durch eine Aufteilung des Sortiervorganges auf 2 parallele Prozesse zu reduzieren. 

Das Grundprinzip lautet wie folgt: 
    1. jeweils eine Hälfte der Zahlen wird zu den beiden Sortierprozessen geschickt
    2. beide Prozesse sortieren parallel 
    3. das Sortierergebnis wird zurückgesendet 
    4. durch "Mischen" der beiden sortierten Zahlenfolgen wird das Gesamtergebnis erzeugt 
       
Daraus resultiert die folgende Implementation (Beispiel): 
    • Ein C-Programm "parallel_sort" kreiert 4 "Pipes" zur bidirektionalen Kommunikation mit den beiden Sortierprozessen. 
    • Es erzeugt danach 2 Kindprozesse mit "fork", die ihrerseits über "execlp" das Programm "sort" starten - und zwar so, dass die unsortierten Zahlen über die Standardeingabe gelesen und die sortierten über die Standardausgabe geschrieben werden. 
    • Der Vaterprozess liest nun die Datei "daten.txt" und sendet die Zahlen im Wechsel zu seinen beiden Kindprozessen. 
    • Danach wartet er auf die Ergebnisdaten. 
    • Dabei liest er jeweils eine Zahl von den beiden "Ergebnis"-Pipes und schreibt die jeweils kleinere auf den Bildschirm (dies wird als "Mischen" bezeichnet). 

Hinweis: Mischen (Merging) 
kann zunächst für 2 Felder demonstriert werden.Eine mögliche Implementation wäre: 
 
// merge(int a[], int b[], int c[], int n, int m) 
// mischt zwei sortierte Felder a[], der Dimension n 
// und b[] der Dimension m in ein Feld c[], der Dimension m+n 
// 
 
void merge(int a[], int b[], int c[], int n, int m){
      int i, j, k;
      i = j = 0;
      for( k=0; k<m+n; k++ ) {
           // kleineres Element a[i] oder b[j] finden 
           if( i<n && j<m ) {
                  if (a[i] < b[j]) 
                      c[k]=  a[i++];
                  else
                      c[k]=  b[j++];
          }
          else if( i<n ) {
                      c[k] = a[i++];
          }
          else if( j<m ) {
                      c[k] = b[j++];
          }
       }
       return;
}
*/

// ENTER CODE
