// a.hofmann sept. 2017
// btree.h
// Binaerer Suchbaum
//

#include <stdio.h>


// 1. Strukturtypen  definieren
// ---------------------------------------------------------
typedef struct Bnode {
	int key;				//Datensatz
	struct Bnode *Left;		//Zeiger auf linken Teilbaum
	struct Bnode *Right;	//Zeiger auf rechten Teilbaum
}BNODE;
typedef BNODE* BinSearchTree;



//2. interface (Zugriffsfunktionen/Methoden) definieren
// ---------------------------------------------------------
// Traversieren
void inorder (BinSearchTree root, FILE *stream);
void postorder (BinSearchTree root, FILE *stream);
void preorder (BinSearchTree root, FILE *stream);

// Suchen
BinSearchTree search (int key, BinSearchTree root);

//Einfuegen
BinSearchTree insert (int key, BinSearchTree *root);

//Loeschen
void delete (int key, BinSearchTree *root);

// mab
int maxTiefe(BinSearchTree root, int ebene);
int summe(BinSearchTree root);
int anzKnoten(BinSearchTree root);
