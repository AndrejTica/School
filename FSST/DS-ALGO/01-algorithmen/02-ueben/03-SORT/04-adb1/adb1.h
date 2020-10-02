/** Die Funktionsdeklarationen von ADB1
 *		Adressbuchverwaltung: ADB1
 		Indexsequentieller ZUgriff auf die Daten
 		Die Index-Tabelle besteht aus nickname/offset-Elementen,
 		die sortiert sind und beim Zugriff wird durch die
 		binäre Suche (nach nickname) der offset für den
 		seek in der Datei ermittlet.
 *   
 *  @author Anton Hofmann
 *  @date 31.10.2016
 *  @file adb1.h
 * 
 *  @version 1.0
 *
 *  @see Arbeitsblatt: Sortieren und Suchen 
 * 
 *  @todo Fertig programmieren
 * 
 *  @bug static Variablen sollten in die adb.c gegeben werden.
 * 
 *  @warning Diese Übung ist Pflicht
 *
 */


// --------------- MAKROS und TYPVereinbarungen ----------------
#define MAXLINE 128                     //Max. Laenge einer Zeile
										// (nickname,email,comment)
#define MAXELEMENTS 1024                //Max. Anzahl v. datensaetzen
#define MAXFILE 128                     // MAx. laenge eiens Dateinamens

/**
 * @struct ADB_IDX
 *		besteht aus (nicname, offset)
 */
typedef struct	{
	char nickname[MAXLINE];
	long offset;
	} ADB_IDX;                         // TYP: Record der Index-tabelle


// ???????????????????????????????????????????????????????????????????????
// FRAGE-FRAGE-FRAGE-
// IST ES WIRKLICH SINNVOLL DIE FOLGENDEN STATIC-VARIABLEN UND FUNKTIONEN
// IN DIESE HEADER-DATEI ZU GEBEN ?????????????????????????
// ???????????????????????????????????????????????????????????????????????
 
// --------------- Tabellen ----------------------------------------------------
static ADB_IDX adb_idx_tabelle[MAXELEMENTS]; // Indextabelle: nickname u. offset
static int  adb_nrecords;                   //anzahl der gelesenen Datensaetze

// --------------- File: ADressbuch---------------------------------------------
static FILE * adb_fp;               //adb_open() und adb_close() adb_get_email()

// --------------- Funktionen intern -------------------------------------------
static int cmp (ADB_IDX* a, ADB_IDX* b); //Vergleichsfunk. f. qsort(),bsearch()





// =========================================================================
// ---------------public Funktionen Interface ------------------------------
// =========================================================================

/** öffnet die Email-Adressdatenbankdatei
		<br>erstellt eine Index-Tabelle mit folg. Aufbau
		<br>nickname | Beginn des Datensatzes in der Email-Adressdatenbankdatei
		<br>nickname | Beginn des Datensatzes in der Email-Adressdatenbankdatei 
		<br>sortiert die Index-Tabelle nach nickname
*  @param [in] filename der Dateiname
*  @return int  gibt die Anzahl der gelesenen Datenzätze zurück, 
*  @return -1 im Fehlerfall; 1 OK
*/
int adb_open (const char * filename);



/** gibt eine Liste {nickname :: emailadresse CRLF} auf FILE* aus
*  @param [in] fp der Ausgabestrom
*  @return void
*/
void adb_list (FILE *fp);



/** gibt die entsprechende email-adresse aus
*		zuerst wird in der index-tabelle binär nach nickname gesucht
* 		dann wird mittels des entsprechenden offset aus der 
*		Email-Adressdatenbankdatei die email-adresse ermittelt
*  @param [in] nickname
*  @param [out] email, wenn nicht gefunden ist email empty
*  @return void
*/
void adb_get_email (const char* nickname, char* email);


/** schliesst die Datei
*  @param void
*  @return void
*/
void adb_close(void);

