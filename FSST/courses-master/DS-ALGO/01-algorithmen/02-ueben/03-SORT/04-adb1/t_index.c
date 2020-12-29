/* Datei: t_index.c       Hofmann Anton
 * Demonstration: Indizierte Dateien.
 * Ein Programm zum beliebigen Anzeigen von Zeilen
 */

#include <stdio.h>

/* -- Erstelle die Indextabelle ----------------- */
int make_index(FILE* fp, long *index_tab, int max_ind)
/*FILE *fp;          Zu indizierende Datei */
/*long *index_tab;   Indextabelle */
/*int max_ind;       max. Anzahl Indizes */
{
long *next_ptr=index_tab,
  *last_ptr= index_tab + max_ind -1;  /* Zeiger auf Ende der Indextabelle */
int c, lastch;

for (lastch='\n'; c=getc(fp),c!=EOF;lastch=c)
  if (lastch=='\n')   /* -- rette Position der Zeile */
    if(next_ptr <= last_ptr) /* -- solange Platz ist */
      *next_ptr++= ftell(fp)-1;
    else
      break;

return (next_ptr - index_tab);  /* Anzahl der Indizes in Tabelle */

} /* make_index() */


/* -- Drucke eine Zeile ------------------------------------ */
void print_line (FILE* fp, long *index_tab, int lineno)
/*FILE *fp;           Datei, die angesehen wird */
/*long *index_tab;     Indextabelle */
/*int lineno;         Nummer der zu druckenden Zeile */
{
int c;

if (fseek(fp,index_tab[lineno],0) !=0) /* -- Gehe zur Zeile */
  fprintf(stderr, "Kann Zeile %d an %ld nicht lesen\n",
                              lineno,index_tab[lineno]);
else
{
  while(c=getc(fp), c!= EOF && c!= '\n') /* drucke Zeile */
    putchar(c);
  putchar('\n');
}
} /* print_line() */



/* -- MAIN ------------------------------------ */
#define MAXINDEX 2000
long index_tab[MAXINDEX]; /* Indextabelle */

main(int argc, char *argv[])
{
int next;                 /* n chste Nummer */
int lines;                /* Zeilen in Tabelle */
FILE *fp;
void print_line();

if (argc !=2)
  fprintf(stderr, "Verwendung: %s Dateiname\n", argv[0]);

else if (fp= fopen(argv[1], "r"), fp != NULL)
{
  if ((lines = make_index(fp,index_tab, MAXINDEX)) != 0)
     do
     { printf("Zeile (Abbruch: negative Zahl) ? "); scanf("%d",&next);
       if (next > 0 && next <= lines)
          print_line(fp, index_tab, next-1);  /* index_tab[0] .. 1.Zeile*/
     } while (next > 0);
}
system("PAUSE");
} /* main() */
