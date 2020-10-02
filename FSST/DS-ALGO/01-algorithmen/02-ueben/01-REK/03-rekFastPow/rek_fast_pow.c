/*
@author	N.N.
@file	rek_fast_pow.c
@date	dd.mm.yyyy

Aufgabe: rek_fast_pow.c
--------------------------------------------------------------------------------
pow (x,n) = wenn n gerade:
			ret= pow (x,n/2)
			ret*= ret
			oder sonst
pow (x,n) = wenn n ungerade
			ret= pow (x,n/2)
			ret*= ret
			ret*= x
*/


#include <stdio.h>


int fast_pow(int x, int n){
	??????????????????????
}


int main(){
	int m=2, n=5;
	int res;
	
	printf("recursive function: fast_pow(m,n)\n");
	printf("m= "); scanf("%i", &m);
	printf("n= "); scanf("%i", &n);

	res= fast_pow(m,n);
	
	printf("\n%i hoch %i = %i\n\n", m,n,res);
	
	return 0;
}

