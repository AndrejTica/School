/*
@author	N.N.
@file	rek_pow.c
@date	dd.mm.yyyy

Aufgabe: rek_pow.c
----------------------------------------------------------------
pow (x,n) = 1, wenn n==0
			oder sonst
pow (x,n) = x * pow(x,n-1)

*/


#include <stdio.h>


int rek_pow(int x, int n){
	??????????????????????
}


int main(){
	int x=2, n=5;
	int res;
	
	printf("recursive function: fast_pow(x,n)\n");
	printf("x= "); scanf("%i", &x);
	printf("n= "); scanf("%i", &n);

	res= rek_pow(x,n);
	
	printf("\n%i hoch %i = %i\n\n", x,n,res);
	
	return 0;
}

