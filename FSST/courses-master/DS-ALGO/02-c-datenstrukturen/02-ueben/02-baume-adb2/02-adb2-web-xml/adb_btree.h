// a.hofmann sept. 2007
// adb_btree.h
// AdressbuchVerwaltung mittles Binaerem Suchbaum
//

#include "adb2.h"


// 1. Strukturtypen  definieren
// ---------------------------------------------------------
typedef struct Bnode {
  ADB_RECORD key;			//Datensatz
  struct Bnode *Left;		//Zeiger auf linken Teilbaum
  struct Bnode *Right;		//Zeiger auf rechten Teilbaum
}BNODE;
typedef BNODE* BinSearchTree;



//2. interface (Zugriffsfunktionen/Methoden) definieren
// ---------------------------------------------------------
// Traversieren
void inorder (BinSearchTree root, FILE *stream);
void postorder (BinSearchTree root, FILE *stream);
void preorder (BinSearchTree root, FILE *stream);

// Suchen
BinSearchTree search (ADB_RECORD* key, BinSearchTree root);

//Einfuegen
BinSearchTree insert (ADB_RECORD* key, BinSearchTree *root);

//Loeschen
void delete (ADB_RECORD* key, BinSearchTree *root);
