/*
u_heron.c 

Die Newton-Iteration  (sog. HERONsche Formel)
        x n+1 =  ( x n + a / x n ) / 2       
        mit n = 2, 3, ...      
        mit x 1 = 1.0
        mit a ist eine positive reelle Zahl ungleich 0

Hinweis: x n+1 ....bedeutet: das (n+1)-te x
        
konvergiert mit wachsendem  n  (für jedes a  > 0)  gegen sqrt( a) . 

Unter Formulierung einer Genauigkeitbedingung:
   |x n+1 - x n | < eps  

kann diese Iteration mit einer 
Schleife ausgeführt werden.

Erstellen Sie ein vollständiges Programm. 

Eingabe: 
a= ...
eps= ...
Ausgabe:
sqrt(a) = ….

Hinweis: mathematik Lib m hinzufügen
Übersetzen mit:

gcc u_heronc.c -lm -o u_heron.exe
*/

#include <stdio.h>
#include <math.h>

int main ( ){
	double a , alt, neu ;
	int schritte = 0 ;

	printf ("Wurzel aus : " ) ; 
	scanf ("%lf", &a );

	alt=1;
	neu= (1+a)/2.0;
	while (fabs ( neu - alt ) > 0.0001) {// Funktion fabs, nicht abs !!!
		alt = neu ;
		neu = ????????????;
		schritte++ ;
	}

	printf ("%lf", neu) ;
	printf ("\n  in %i Schritten ... ", schritte) ;

	return 0;
 }
 
