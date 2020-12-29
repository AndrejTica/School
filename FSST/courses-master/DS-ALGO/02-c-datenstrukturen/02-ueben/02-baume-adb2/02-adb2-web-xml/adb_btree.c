// a.hofmann sept. 2002
// adb_btree.c
// AdressbuchVerwaltung miitles Binärem Suchbaum
//

#include <stdlib.h>
#include <string.h>

#include "adb_btree.h"

// lokale Hilfsfunktion 
// -------------------------------------------------------------
static BNODE* make_node (ADB_RECORD* key){
	BNODE* ptr;
	
	ptr = (????????????) malloc (????????????????????);
	if (ptr != NULL){
		???????????????????????		
		
		// Blatt, d.h. li,re sind leer
		???????????????????????		
	}
	return ptr;
}


// oeffentliche Funktionen
// -------------------------------------------------------------
void inorder ( BinSearchTree ptr, FILE *stream){
	if (		???????????????????????	){
		???????????????????????		
		
		fprintf (stream, "\n<marker ");
		fprintf (stream, "name=\"%s\" address=\"%s\" type=\"%s\"", 
				ptr->key.name,ptr->key.address,ptr->key.type);

		fprintf (stream, " lat=\"%s\" lng=\"%s\" ", 
				ptr->key.lat,ptr->key.lng);
		fprintf (stream, " />");
		
		???????????????????????		
	}
}

void postorder (BinSearchTree root, FILE *stream){
	// hier nicht gebraucht	
}

void preorder (BinSearchTree root, FILE *stream){
	// hier nicht gebraucht
}


// -------------------------------------------------------------
BinSearchTree search (ADB_RECORD* key, BinSearchTree root){
	if (root == NULL)
		return NULL;
	else if (strcmp (key->name,root->key.name) == 0)
		return root;
	else if (strcmp (key->name,root->key.name) < 0)
		???????????????????????		
	else
		???????????????????????		
}


// -------------------------------------------------------------
BinSearchTree insert (ADB_RECORD* key, BinSearchTree* root) {
	BinSearchTree curr= *root;
	BinSearchTree prev= *root;
	
	// 1. Wenn Baum leer ist
	if (*root == NULL)
	{
		*root = make_node(key);
		return *root;
	}

	//2. Suche Platz zum Einfuegen
	while (curr != NULL){
		prev= curr;
		if (strcmp(key->name,curr->key.name) > 0)
			curr= curr->Right;
		else if ( strcmp(key->name,curr->key.name) < 0)
			curr= curr->Left;
		else //Element bereits vorhanden
			return NULL;
	}
	
	//3. Bei prev einfuegen
	if (strcmp(key->name, prev->key.name) > 0){
		prev->Right= make_node(key);
		return prev->Right;
	}
	else{
		prev->Left= make_node(key);
		return prev->Left;
	}
}


// -------------------------------------------------------------
void delete (ADB_RECORD* key, BinSearchTree *root){
	// wird hier nicht besprochen
}
