/*1.6.2.  Beispiel: f_index.c
Schreiben Sie ein Programm, das 
den Dateinamen einer Textdatei erfragt. 
Diese Datei wird  anschliessend eingelesen. Dabei wird in ein Array die Position jedes Zeilenanfanges (siehe ftell() ) gespeichert.
Danach wird vom Benutzer eine Zeilennummer erfragt. Dieser Wert wird als Index im Array verwendet. Dort steht die Position der Zeile in der Datei. 
Nun postionieren Sie sich mittels fseek() an die gewünschte Zeile in der Datei 
und geben diese Zeile aus der Datei am Bildschirm aus.

Programmabbruch, wenn  0 eingegeben wird. 
*/


/* Datei: f_index.c       Hofmann Anton
 * Demonstration: Indizierte Dateien.
 * Ein Programm zum beliebigen Anzeigen von Zeilen
 */

#include <stdio.h>

/** Erstelle die Indextabelle 
 *FILE *fp;          Zu indizierende Datei 
 *long *index_tab;   Indextabelle 
 *int max_ind;       max. Anzahl Indizes 
*/
int make_index(FILE* fp, long *index_tab, int max_ind) {
	??????????????????????
} 


/** Drucke eine Zeile
 * FILE *fp;            Datei, die angesehen wird 
 * long *index_tab;     Indextabelle 
 * int lineno;          Nummer der zu druckenden Zeile */
void print_line (FILE* fp, long *index_tab, int lineno){
	??????????????????????????????????????
} 


/* -- MAIN --------------------------------------------------------- */
#define MAXINDEX 2000

long index_tab[MAXINDEX]; /* Indextabelle */

int main(int argc, char *argv[]){
	int next;                 /* nächste Nummer */
	int lines;                /* Zeilen in Tabelle */
	FILE* fp;
	void print_line();

	if (argc !=2)
		fprintf(stderr, "Verwendung: %s Dateiname\n", argv[0]);

	else if (fp= fopen(argv[1], "r"), fp != NULL){
		if ((lines = make_index(fp,index_tab, MAXINDEX)) != 0)
			do { 
				printf("Zeile (Abbruch: negative Zahl) ? "); 
				scanf("%i",&next);
				if (next > 0 && next <= lines)
					print_line(fp, index_tab, next-1); // index_tab[0] .. 1.Zeile
			} while (next > 0);
	}
	
	return 0;
} 
