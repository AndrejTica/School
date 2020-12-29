// a.hofmann sept. 2002
// adb2.h
// AdressbuchVerwaltung
//
#include <stdio.h>

// --------------- MAKROS und TYPVereinbarungen ----------------
#define MAXLINE 128                     //Max. Laenge einer Zeile (nickname,email,comment)
#define MAXELEMENTS 1024                //Max. Anzahl v. datensaetzen
#define MAXFILE 128                     // MAx. laenge eiens Dateinamens


/*1. Datensatz definieren
Altstadtkeller
Altstadtkeller Rudolfskai 27 Salzburg >+43 (522) 849-68...
restaurant
47.799636
13.047558
*/
typedef struct	{
	char name[MAXLINE];
	char address[MAXLINE];
	char type[MAXLINE];
	char lat[MAXLINE];
	char lng[MAXLINE];
	} ADB_RECORD;                         // TYP: Record des Datensatzes


// --------------- Funktionen Interface -----------------------------
/**
 * oeffnet die Email-Adressdatenbankdatei
 * und fuegt die datensaetze in den Bin.Suchbaum ein
 * @param filename
 * @return -1 Fehler bzw. 1 OK
 */
int adb_open (const char * filename);

/**
 * gibt eine Liste {nickname :: emailadresse CRLF} auf FILE* aus
 * @param fp 
 * @return void
 */ 
void adb_list (FILE *fp);


/**
 * gibt die entsprechende email-adresse aus
 * @param nickname, email 
 * @return NULL Fehler; email OK
 */
char* adb_get_email (const char* nickname, char* email);


/**
 * oeffnet die xml Datei
 * und schreibt die datensaetze hinein
 * @param filename
 * @return -1 Fehler bzw. 1 OK
 */
int adb_saveas_xml(const char* filename);
