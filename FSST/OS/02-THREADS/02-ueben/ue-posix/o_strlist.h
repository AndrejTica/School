/**
 * Datei: o_strlist.H    Hofmann Anton
 * Headerdatei f r Typvereinbarungen.
 * Einfach verkettete Listen als ADTs.
 **/

/* -- Einfach gekettete Listen ------------------------- 
 * -----------------------------------------------------*/
/* -- SLIST Knoten */
struct SList {
  char *Data;
  struct SList *Next;
};
typedef struct SList  SLIST;


/* -- Ein Kopf-Knoten, der die Listenl nge enth lt */
struct SList_Header {
  int Len;
  SLIST *First, *Last;
};
typedef struct SList_Header SLIST_HEADER;


extern SLIST_HEADER *createSList(void);
extern SLIST *insertFirst(SLIST_HEADER*,char*);
extern SLIST *insertLast(SLIST_HEADER*,char*);
extern void  deleteFirst(SLIST_HEADER*);
extern void  deleteLast(SLIST_HEADER*);
extern void pr_SList(SLIST_HEADER*,FILE*);
extern void rm_SList(SLIST_HEADER*);
extern char *get_entrySList(SLIST_HEADER*,int);
