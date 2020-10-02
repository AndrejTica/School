/*
@author	N.N.
@file	rek_ggt.c
@date	dd.mm.yyyy

Aufgabe: rek_ggt.c
----------------------------------------------------------------
ggT (a,b) = a, wenn b==0
			oder 
ggT (a,b) = ggT (b, a%b)

*/

#include <stdio.h>


int ggt(int a, int b){
	??????????????????????
}


int main(){
	int a=2, b=5;
	int res;
	
	printf("recursive function: ggt(a,b)\n");
	printf("a= "); scanf("%i", &a);
	printf("b= "); scanf("%i", &b);

	res= ggt(a,b);
	
	printf("\nggt(%i,%i) = %i\n\n", a,b,res);
	
	return 0;
}

