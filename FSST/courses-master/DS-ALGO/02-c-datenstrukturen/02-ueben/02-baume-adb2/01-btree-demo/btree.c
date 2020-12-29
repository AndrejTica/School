// N.N. 2017
// btree.c
// 
// 
#include <stdlib.h>
#include <string.h>

#include "btree.h"

// lokale Hilfsfunktion 
// -------------------------------------------------------------
static BNODE* make_node (int key){
	BNODE* ptr;
	
	????????????????

	return ptr;
}


// oeffentliche Funktionen
// -------------------------------------------------------------
void inorder ( BinSearchTree ptr, FILE *stream){
	????????????????
}

void postorder (BinSearchTree root, FILE *stream){
	// hier nicht gebraucht	
}

void preorder (BinSearchTree root, FILE *stream){
	// hier nicht gebraucht
}


// -------------------------------------------------------------
BinSearchTree search (int key, BinSearchTree root){
	????????????????
}


// -------------------------------------------------------------
BinSearchTree insert (int key, BinSearchTree* root) {
	????????????????
}


// -------------------------------------------------------------
void delete (int key, BinSearchTree *root){
	// wird hier nicht besprochen
}



// mab
// --------------------------------------------------------

int maxTiefe(BinSearchTree root, int ebene){
	????????????????
}

int summe(BinSearchTree root){
	
	????????????????
}


int anzKnoten(BinSearchTree root){
	????????????????
}

