/**
 * Datei: o_strlist.h    Hofmann Anton
 * Headerdatei fuer Typvereinbarungen.
 * Einfach verkettete Listen als ADTs.
 **/

// -----------------------------------------------------
// TYP vereinbarungen
// -----------------------------------------------------
/* -- SLIST Knoten */
struct SList {
  char *Data;
  struct SList *Next;
};
typedef struct SList  SLIST;


/* -- Ein Kopf-Knoten, der die Listenlaenge enthaelt */
struct SList_Header {
  int Len;
  SLIST *First, *Last;
};
typedef struct SList_Header SLIST_HEADER;


// -----------------------------------------------------
// Aufrufbare FUNKTIONEN
// -----------------------------------------------------
extern SLIST_HEADER *createSList(void);

extern SLIST *insertFirst(SLIST_HEADER*,char*);
extern SLIST *insertLast(SLIST_HEADER*,char*);

extern void deleteFirst(SLIST_HEADER*);
extern void deleteLast(SLIST_HEADER*);

extern void pr_SList(SLIST_HEADER*,FILE*);

extern void rm_SList(SLIST_HEADER*);

extern char *get_entrySList(SLIST_HEADER*,int);

// -----------------------------------------------------
//MAB: sort
// -----------------------------------------------------
extern void sortList(SLIST_HEADER*);

// -----------------------------------------------------
//MAB: list2array
// -----------------------------------------------------
extern char* list2array(SLIST_HEADER* aList);


