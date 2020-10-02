// a.hofmann sept. 2002
// adb2.c
// AdressbuchVerwaltung
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "adb_btree.h"

// Der Baum ist NUR (static) hier global
static BinSearchTree theTree;


// --------------- Funktionen Implementierung -----------------------
int adb_open (const char * filename){
	FILE* adb_fp; 
	char* ret;
    char input[MAXLINE];
    ADB_RECORD aRecord;
   
	// --------- 1. File oeffnen (Anm.: ASCII-Datei)
	adb_fp=fopen(filename, "rt");
	if (adb_fp == NULL) 
		return -1;

	// ---------  2. Datensaetze lesen und in Baum einfuegen
	do 
	{
		// name lesen 
		ret= fgets(aRecord.name, sizeof (aRecord.name), adb_fp);
		//'\n' am ende loeschen, da fgets() dies mitliest
		if (ret != NULL) aRecord.name[strlen (aRecord.name) - 1] = '\0';
	
		// address
		if (ret != NULL) 
		{
		ret= fgets(aRecord.address, sizeof (aRecord.address), adb_fp);
		aRecord.address[strlen (aRecord.address) - 1] = '\0';
		}
	
		if (ret != NULL)
		{ 
		ret= fgets(aRecord.type, sizeof (aRecord.type), adb_fp);
		aRecord.type[strlen (aRecord.type) - 1] = '\0';
		}

		if (ret != NULL)
		{ 
		ret= fgets(aRecord.lat, sizeof (aRecord.lat), adb_fp);
		aRecord.lat[strlen (aRecord.lat) - 1] = '\0';
		}
		
		if (ret != NULL)
		{ 
		ret= fgets(aRecord.lng, sizeof (aRecord.lng), adb_fp);
		aRecord.lng[strlen (aRecord.lng) - 1] = '\0';
		}
	
		// in Baum einfuegen
		// ------------------
		if (ret != NULL) 
		???????????????????????		

	} while (ret != NULL);


	// datei wieder schliessen
	// wir halten alles im Baum
	close(adb_fp);

    return(1);
}


//gibt eine Liste {nickname :: emailadresse CRLF} auf FILE* aus
void adb_list (FILE *fp) {
	inorder (theTree, fp);
}


//gibt die entsprechende email-adresse aus
//RETURN: NULL Fehler; email OK
char* adb_get_email (const char* name, char* address) {
 BinSearchTree found;
 ADB_RECORD aRecord;

 strcpy(aRecord.name, name);
 
 //1. suchen
 found = search(&aRecord, theTree);

 if (found == NULL){
  *address ='\0';
  return NULL;
 }
 
 strcpy (address, found->key.address);
 
 return address;
}



/*
<markers>
<marker name="Altstadtkeller" address="Altstadtkeller Rudolfskai 27 Salzburg >+43 (522) 849-68..." lat="47.799636" lng="13.047558" type="restaurant"/>
<marker name="Carolino Augusteum" address="Carolino Augusteum Museum Museumsplatz 6 Salzburg >+43 (662) 841-134..." lat="47.801617" lng="13.039575" type="sehenswuerdigkeit"/>
</markers>
*/

int adb_saveas_xml(const char* filename){
	FILE* fp;
	
	fp= fopen(filename, "w");
	if (NULL==fp)
		return -1;
		
	fprintf(fp,"<markers>\n");
	inorder(theTree,fp);
	fprintf(fp,"\n</markers>\n");
	
	fclose(fp);
	return 1;
}
