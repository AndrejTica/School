/**
 *@brief Fibonacci-Folge (iterativ)

 @file	fib.c
 @author N.N.
 @description

2.3.  Aufgabe: fib.c
Das Programm soll unter Verwendung von Schleifen folgende Folge ausgeben:
1 1 2 3 5 8 13 21 34 55 …
Es sollen die ersten 30 Zahlen ausgegeben werden.
*/

#include <stdio.h>

int main(){
	unsigned int eins=1;
	unsigned int zwei=1;
	unsigned int next= eins+zwei;
	int i;
	
	printf("%i, \n", eins);
	printf("%i, \n", zwei);
	
	for (i=1; i<=28; i++){
		printf("%i, \n", next);
		
		????????????????????????
	}
	
	printf("\n");
	return 0;
}
