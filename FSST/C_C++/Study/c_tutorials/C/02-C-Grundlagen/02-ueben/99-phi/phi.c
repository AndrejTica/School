/**
 *@brief Eulerschi phi-Funktion

 @file	phi.c
 @author N.N.
 @description
 Die Funktion liefert die Anzahl der zu n (=Eingabe) teilerfremden
 Zahlen im Bereich [1,n].
 */

#include <stdio.h>
#include <stdlib.h>

// Die Funktion: ggt() liefert 
// den größten gemeinsamen Teiler von a und b
int ggt (int a, int b){
	if (b==0) return a;
	else return ggt(b, a%b);
}


int main(){
	int i, n, phi=0;

	printf("*** Eulersche PHI-Funktion ***\n");
	printf("n eingeben? ");
	scanf("%i" , &n);

	???????????????????????????

	printf("\nphi(%i)= %i\n", n, phi);

	return 0;
}


