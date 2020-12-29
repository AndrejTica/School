// a.hofmann sept. 2002
// test-btree.c
// Testprogramm: bin Search Tree
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "btree.h"


#define CLS system("clear")
#define PAUSE printf("weiter mit enter ...");fgetc(stdin)

//#define CLS system("cls")
//#define PAUSE system("pause");


int main(int argc, char *argv[]){
	int choice;
	int ende;
	int wert;
	
	BinSearchTree tree=NULL; // Dont forget an empty tree;
	
	ende=0;
	while (!ende){
		CLS;
		printf("\n\n\t*** DEMO Bin.Search.Tree (A.Hofmann 2017) ***\n\n");
		
		printf("\t1) insert\n");
		printf("\t2) inorder\n");
		printf("\t3) search\n");
		printf("\t4) maximale Tiefe\n");
		printf("\t5) summe aller Knoten\n");
		printf("\t6) anzahl der Knoten\n");
		
		printf("\t0) ende\n");
		printf("\t");
		
		scanf("%i", &choice);
		fgetc(stdin);
		
		switch(choice){
			case 1:
				printf("\t1) insert\n");

				do{
					printf("int-Werte eingeben (Ende=0)? ");
					scanf("%i", &wert); 
					fgetc(stdin);
					
					insert(wert, &tree);
				}while(wert !=0);

				printf("\n");
				PAUSE;
				break;
			case 2:
				printf("\t2) inorder\n");
				inorder(tree, stdout);
				
				printf("\n");
				PAUSE;
				break;
			case 3:
				printf("\t3) search\n");
				printf("int-Wert? ");
				scanf("%i", &wert); 
				fgetc(stdin);
				
				BNODE* ret= search(wert, tree);
				if (ret==NULL)
					printf("\n%i nicht gefunden\n", wert);
				else
					printf("\n%i gefunden (%i)\n", wert , ret->key);
				
				printf("\n");
				PAUSE;
				break;
			case 4:// mab
				printf("\t4) maximale Tiefe\n");

				wert= maxTiefe(tree,0);
				printf("\nDie maximale Tiefe des Baumes ist %i\n", wert);
								
				printf("\n");
				PAUSE;
				break;
			case 5: // mab
				printf("\t5) summe aller Knoten\n");
				
				wert= summe(tree);
				printf("\nDie Summer aller Knoten ist %i\n", wert);
				
				printf("\n");
				PAUSE;
				break;
			case 6:// mab
				printf("\t6) anzahl der Knoten\n");
				
				wert= anzKnoten(tree);
				printf("\nDie Anzahl aller Knoten ist %i\n", wert);
				
				printf("\n");
				PAUSE;
				break;
			
			case 0:
				ende = 1;
				break;
			
			default:
				ende = 1;
		} //switch
	}//while

	return 0;
}
