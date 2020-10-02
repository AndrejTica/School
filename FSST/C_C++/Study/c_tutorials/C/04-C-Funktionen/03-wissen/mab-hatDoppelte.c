// hatDoppelte.c   mab: 4 Pkte
// prüft, ob in einem int-Array doppelte (od. mehrere) Elemente vorkommen
// Bsp:
// 1, 2, 3, 4  ... liefert 0
// 1, 2, 1, 4  ... liefert 1

#include <stdio.h>

// prüft, ob in einem int-Array doppelte (od. mehrere) Elemente vorkommen
int hatDoppelte(int a[] , int len);

int main(){
	int feld1[]={1,2,3,4,5};
	int feld2[]={1,2,1,4,5};
	int i, ret;
	
	// ----- FELD1 pruefen
	printf("\nDas Array feld1: \n");
	for(i=0; i< 5; i++)
		printf("%i, ", feld1[i]);
	printf("\n");
	
	ret= hatDoppelte(feld1, 5);
	if(ret==0)
		printf("feld1 hat KEINE doppelten Elemente\n");
	else
		printf("feld1 HAT doppelte Elemente\n");
	
	// ----- FELD2 pruefen
	printf("\nDas Array feld2: \n");
	for(i=0; i< 5; i++)
		printf("%i, ", feld2[i]);
	printf("\n");
	
	ret= hatDoppelte(feld2, 5);
	if(ret==0)
		printf("feld2 hat KEINE doppelten Elemente\n");
	else
		printf("feld2 HAT doppelte Elemente\n");

	printf("\n");
	return 0;
}

//(4)
?????? hatDoppelte(????????????????){
	???????????????????
}
