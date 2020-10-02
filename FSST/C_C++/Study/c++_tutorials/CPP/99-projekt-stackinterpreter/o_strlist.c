/**
 * Datei: o_strlist.c    Hofmann Anton
 * Einfach verkettete Listen als ADTs.
 * Deklarationen: O_ADT.H
 **/

#include <stdio.h>
#include <stdlib.h>
#include "o_strlist.h"



/**
 * Lokale OPERATIONEN, die privat gehalten werden.
 *------------------------------------------------*/

static SLIST *makeSListNode (char* userData, SLIST* aPtr)
{ 
SLIST *newPtr;    /* Zeiger auf zugewiesenen Speicher */

if ((newPtr=(SLIST *) malloc(sizeof(SLIST))) != NULL)
{
  newPtr->Data= (char *) malloc(strlen(userData)+1);
  if (newPtr->Data == (char *) NULL)
  {
     free (newPtr);
     return((SLIST *)NULL);
  }
  else
  {
     strcpy(newPtr->Data, userData);
     newPtr->Next= aPtr;
  }
}
return (newPtr);
}



/**
* Von aussen sichtbare ZUGRIFFS-OPERATIONEN
extern SLIST_HEADER *createSList(void);
extern SLIST *insertFirst(SLIST_HEADER*,char*);
extern SLIST *insertLast(SLIST_HEADER*,char*);
extern void  deleteFirst(SLIST_HEADER*);
extern void  deleteLast(SLIST_HEADER*);
extern void pr_SList(SLIST_HEADER*,FILE*);
extern void rm_SList(SLIST_HEADER*);
extern char *get_entrySList(SLIST_HEADER*,int);
* ----------------------------------------*/

/* -- Eine neue Liste aufbauen */
SLIST_HEADER * createSList ()
{
SLIST_HEADER * aList;
if ((aList= (?????????????) malloc(sizeof(????????????))) != NULL)
{
  aList->Len= 0;
  ??????????????????????????
}
return (aList);
}


/* -- Am Beginn der Liste eintragen */
SLIST *insertFirst(SLIST_HEADER* aList, char* userData)
{
SLIST *newPtr;
if ((newPtr= makeSListNode(userData, aList->First))!= NULL)
{
  aList->First= ???????;
  if (aList->Len == 0)  /* -- erster Eintrag ? */
    aList->Last= ????????;

  aList->Len++;
}
return (????????);
}



/* -- Am Ende der Liste eintragen */
SLIST *insertLast(SLIST_HEADER* aList, char* userData)
{
SLIST *newPtr;
if ((newPtr= makeSListNode(userData, (SLIST*) NULL))!= NULL)
{
  if (aList->Len != 0)  /* -- Liste nicht leer ? */
    ...........................
  else
    ...............   /* Liste leer aList->First muss auch auf diesen 1. Knoten zeigen */

  aList->Last= ?????????;
  aList->Len++;
}

return (???????);
}


/* -- Loeschen des ersten Listeneintrages
 * -- aList->Len mu  vorher  berpr ft werden
 */
void  deleteFirst(SLIST_HEADER* aList)
{
SLIST *temp;
char *userData;

if (aList->Len > 0)   /* Liste nicht leer */
     {
     temp= aList->First;
     userData= temp->Data;

     aList->First= ..................;
     aList->Len--;

     if (aList->Len == 0) /* Wenn die Liste leer ist, Last-Zeiger auf NULL */
       .................;

     free( (void *) temp->Data);   /* String freigeben */
     free( (void *) temp);         /* Knoten freigeben */
     }
}


/* -- Loeschen des letzten Listeneintrages
 * -- aList->Len mu  vorher  berpr ft werden
 */
void  deleteLast(SLIST_HEADER* aList)
{
SLIST *temp, *help;
char *userData;
int i;

if (aList->Len > 0)   /* Liste nicht leer */
     {
     temp= aList->Last;
     userData= temp->Data;

     help= aList->First;
     aList->Last= help;
     for (i=0; i<aList->Len-1; i++){
      aList->Last= help;
      help= help->Next;
     }
     aList->Len--;

     if (aList->Len == 0) /* Wenn die Liste leer ist, Last-Zeiger auf NULL*/
     {
       aList->Last= (SLIST *) NULL;
       aList->First= (SLIST *) NULL;
     }
     free( (void *) temp->Data);   /* String freigeben */
     free( (void *) temp);         /* Knoten freigeben */
     }
}



void pr_SList(SLIST_HEADER* aList, FILE* device)
{
int i;
SLIST *node;

node= aList->First;
for (i=1; i<=aList->Len;i++){
   fprintf(device,"%6d\t%s\n",i,node->Data);
   node= node->Next;
   }
}


void rm_SList(SLIST_HEADER* aList)
{
while (aList->Len)
  deleteLast(aList);

free (aList); /* alle Knoten geloescht, Header noch freigeben */
}

 


char *get_entrySList(SLIST_HEADER* aList, int number)
{
if (number>=1 && number<=aList->Len)
{
   int i;
   SLIST *node;

   node= aList->First;
   for(i=1;i<number;i++)
     node= node->Next;
   return(node->Data);
}
else
   return((char *) NULL);
}

