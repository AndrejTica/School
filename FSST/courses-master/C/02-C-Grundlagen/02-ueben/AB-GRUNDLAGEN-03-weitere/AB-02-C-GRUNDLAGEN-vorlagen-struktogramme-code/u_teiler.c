/* 
* u_teiler.c
* Teiler einer natürlichen Zahl 

* Im Bereich der natürlichen Zahlen n gibt es Teilbarkeitseigenschaften: 
* Die Operatoren  / und % kann man dazu benutzen, 
* alle Teiler d mit 1 < d < n  einer Zahl n zu ermitteln. 
*
* Denken Sie sich einen einfachen Algorithmus aus, der nach Eingabe von n 
* alle Teiler d | n bestimmt und ausgibt. 

* Formulieren Sie den Algorithmus zuerst in einem Struktogramm! 

* Zusatz:
* Wenn das Programm läuft, können Sie es dahingehend erweitern, 
* dass alle Teiler d der Zahlen von 1 bis n 
* systematisch (d.h. in einer Tabelle) ausgegeben werden. 

* Wenn eine Zahl n nur Eins und sich selbst als Teiler hat, so ist sie 
* prim. - Markieren Sie in der Ausgabe Primzahlen!
*/

# include <stdio.h>

int main ( ){
	int n, i, d ;
	int zahl ;

	for (n = 2 ; n < 25 ; n ++){
		printf ("%3d : ", n ) ;

		zahl = 0 ;
		for (d = 1 ; ?????? ; d ++){
			if (n % d == 0){
				printf ("%d ", d ); 
				zahl++ ;
			}
		}

		if (zahl == 2){
			printf ("\t\t\t  prim") ;
		}
	
		printf ("\n") ;

	}

	return 0;
}

