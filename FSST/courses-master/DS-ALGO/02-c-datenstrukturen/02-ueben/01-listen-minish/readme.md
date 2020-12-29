# Dynamische Datensturukturen in C
--------------------------------------------------------------------------------
* File: readme.md

## Aufgabe 1: T_MINISH
--------------------------------------------------------------------------------
* Bringen Sie das Programm **t_minish** zum Laufen.
* Vorlage: _t_minish.zip_, Skriptum in _../01-lernen_


## Aufgabe 2: T_MINISH und SORT
--------------------------------------------------------------------------------
Erweitern Sie das MINISHELL-Programm mit folgendem Befehl:  
	`!sort  ............. sorts the list (MAB)\n \`

**Beschreibung:**  
Wenn der User `!sort` eingibt, soll die Liste der Befehle 
sortiert werden. Der User kann dies dann durch Eingabe des Befehles 
`hi` kontrollieren.

**Hinweis:**  
Auszug der Header-Datei für den Listen-Modul: _o_strlist.h_

```
// -----------------------------------------------------
//MAB: sortList
// -----------------------------------------------------
extern void sortList(SLIST_HEADER*);
```

**Hinweis:**  
Beim Sortieren der Liste genügt es, wenn bei zwei zu vergleichenden 
Listenknoten die Data-Komponenten (sind ja char*) ausgetauscht werden.

Der Sortieralgorithmus wird lesbarer, wenn Sie für den Zugriff auf 
z.B. 2 benachbarte Listenknoten eine  **lokale** Hilfsfunktion schreiben.


```
static SLIST* get_NodeSList(SLIST_HEADER* aList, int number){
      ????????????
}
```


## Aufgabe 3: LIST2ARRAY
--------------------------------------------------------------------------------
LISTENDATEN in ein Array schreiben. Erstelle die Funktion:

```	char* list2array(SLIST_HEADER* aList);```

1. ermittelt die Länge aller Strings, die in der Liste gespeichert sind
2. alloziiert einen Speicher, sodass die Strings inkl. den
	Begrenzungszeichen < und > Platz haben. (s. Punkt 3)
3. speichert alle Strings in den neuen Speicher in der folgenden
	Form: ```<string1><string2><string3>......<string9>```
4. gibt die Adresse des Speichers zurück.

5. Teste das Programm mit dem folg. Code.

~~~
// test-list2array.c
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

	array= list2array(cmdSList);
	printf("Alle Strings in der Liste: %s\n" , array);

	free(array);
	rm_SList(cmdSList);

	return 0;
}
~~~
	

## Aufgabe 4: +STACK/QUEUE
--------------------------------------------------------------------------------
Gruppe 1:   

- Erstellen Sie **stack.h/stack.c** unter Verwendung

  der einfach geketteten Liste. Der Stack soll

  int-Werte speichern.  

  Funktionen:  

  _createstack(), push(), pop(), deleteStack()_

- Erstellen Sie ein kleines Testprogramm zum Testen Ihrer Funktionen.

Gruppe 2:  

- Erstellen Sie **queue.h/queue.c** unter Verwendung

  der einfach geketteten Liste. Die Queue soll

  int-Werte speichern.  

  Funktionen:   

  _createqueue(), enqueue(), dequeue(), deleteQueue()_

- Erstellen Sie ein kleines Testprogramm zum Testen Ihrer Funktionen.


## Aufgabe 5: +CGI_LIST
--------------------------------------------------------------------------------
Erstellen sie einen Modul in C mit dem Namen **CGIList (CGIList.h, CGIList.c)** mit folgenden Funktionen:

```
/**
* erzeugt eine einfach gekettet Liste
* @param [in] der QueryString entspr. dem CGI Standard
* @return NULL im Fehlerfall
* @return Zeiger auf den Listenheader, der in den
*         anderen Funktionen verwendet werden muss,
*         um die jeweilige Liste zu verwenden.
*/
CGIList* createCGIList(const char* queryString);

/**
* liefert den Wert, der beim feld gepeichert ist.
* siehe CGI-Standard (QUERY_STRING)
* @param [in] der Feldname
* @return NULL im Fehlerfall
* @return Zeiger auf den Wertnamen.
*/
char* getValue(CGIList* aList, const char* field);

/**
* gibt den Inhalt der Liste auf FILE aus.
* @param [in] die Liste (ein Zeiger auf den Listenheader)
* @return void
*/
void printCGIList(CGIList* aList, FILE*);

/**
* löscht die Liste total (auch den Listenheader)
* @param [in] die Liste (ein Zeiger auf den Listenheader)
* @return void
*/
void removeCGIList(CGIList* aList);
```

Hier ein kleines Testprogramm(Auszug):

```
   #include "CGIList.h"

   int main(){
     char* queryString="feld1=wert2&feld2=wert2&feld3=wert3";
     char* p;
     CGIList* cgiList;

     cgiList= createCGIList(queryString);
     if (NULL== cgiList){
          fprintf(stderr, ".........
          exit(1);
     }

     p= getValue("feld2");
     if (NULL== p){
          fprintf(stderr, ".........
          exit(1);
     }
     puts(p);

     // .........
     printCGIList(cgilist, stdout);

     //..........
     removeCGIList(cgilist);
     // .........
   }
```

Ein Listenknoten (CGINODE) soll folg. Komponenten haben:

```
char* feldname;
char* wert;
CGINODE* next;
```
