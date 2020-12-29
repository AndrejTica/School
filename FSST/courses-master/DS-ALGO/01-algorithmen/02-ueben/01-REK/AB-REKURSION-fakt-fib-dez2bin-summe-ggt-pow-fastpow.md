# Rekursion
-------
* File: /DS-ALGO/01-algorithmen/02-ueben/01-REK/AB-REKURSION-fakt-fib-dez2bin-summe-ggt-pow-fastpow.md
* Inhalt: fakt-fib-dez2bin-summe-ggt-pow-fastpow

## 1. Fakultät (v)
---
* Definition

	n! = 1 * 2 * ... * (n-1) * n

* Implementierung
	
	```
	result=1;
	for (i=1; i<=n; i++)
		result= result*i;
	```	
		
* Rekursive Definition

	```
		1			wenn n==0
	n!	
		n*(n-1)!	sonst
	```

* Implementierung

	```
	...
	int fakt(int n){
		if (n==0)
			return 1;
		else
			return n * fakt(n-1);
	}
	```


## Aufgabe: Fibonacci (v)
---

* Definition

	```
	fib(0)= 0, wenn n==0
	fib(1)= 1, wenn n==1
	fib(n)= fib(n-2) + fib(n-1), wenn n >1
	```

* AUFGABE: Implementierung

	```
	/*
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
	```
	

## AUFGABE: dez2bin (v)
---

Um eine Dezimalzahl in eine Dualzahl umzuwandeln, kann man folgendermaßen vorgehen:

	13	:	2	= 	6	REST: 1	Stelle: 0
	6	:	2	=	3	REST: 0	Stelle: 1
	3	:	2	=	1	REST: 1	Stelle: 2
	1	:	2	=	0	REST: 1	Stelle: 3

Die Dualzahl lautet also: 1101

	Kontrolle: 	1*23 + 1*22 + 0*21 + 1*20=
			1*8 + 1*4 + 0*2 + 1*1 = 
			8 + 4 + 1=
			13

Schreiben Sie die rekursive Funktion 

`void dez2bin(int n)` 

die als Parameter eine Dezimalzahl erhält und diese auf die Konsole als Dualzahl ausgibt.




## AUFGABE: Summe (v,m)
---
* Erstelle eine rekursive Definition zur Berechnung der Summe der Zahlen von
1 bis n

* Erstelle das entsprechende C-Programm.


﻿
## Aufgabe: rek_ggt.c (u)
---
	ggT (a,b) = a, wenn b==0
				oder 
	ggT (a,b) = ggT (b, a%b)




## Aufgabe: rek_pow.c (u)
---
	pow (x,n) = 1, wenn n==0
				oder sonst
	pow (x,n) = x * pow(x,n-1)



## Aufgabe: rek_pow_fast.c (u)
---
	pow (x,n) = wenn n gerade:
				ret= pow (x,n/2)
				ret*= ret
				oder sonst
	pow (x,n) = wenn n ungerade
				ret= pow (x,n/2)
				ret*= ret
				ret*= x
				
