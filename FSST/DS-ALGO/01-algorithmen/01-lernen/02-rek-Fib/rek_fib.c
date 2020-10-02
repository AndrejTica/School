/*
## Aufgabe: Fibonacci (v)
* Definition
	fib(0)= 0, wenn n==0
	fib(1)= 1, wenn n==1
	fib(n)= fib(n-2) + fib(n-1), wenn n >1

 * rek_fib.c
*/

#include <stdio.h> 

// F- Prototyp 
int fib(int n); 

// F-Aufrufen 
int main(){ 
	int zahl,i; 

	printf("\nFibonacci-Folge (rekursiv)"); 
	do{ 
		printf("\nBitte eine pos. Zahl: "); 
		scanf("%i", &zahl); 
	}while (zahl < 0); 


	for (i=0; i<= zahl; i++){ 
		printf("%i,", fib(i));	// Aufruf der Funktion fib() 
	} 


	putchar('\n'); 
	return 0; 
} 

// F ausprogrammieren 
int fib(int n){ 
	?????????????
}
