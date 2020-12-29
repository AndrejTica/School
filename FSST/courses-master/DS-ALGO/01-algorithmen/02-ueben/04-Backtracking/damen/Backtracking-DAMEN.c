/*
 ============================================================================
 Name        : BackTracking-DAMEN.c
 Author      : N.N
 Version     : 
 Copyright   : open source
 Description : s.u.
 ============================================================================
 */

/*
AUFGABE: 8 DAMEN PROBLEM
Gesucht ist eine Konfiguration von 8 Damen auf einem 8x8 Schachbrett,
sodass keine Dame eine andere bedroht.


PAP:
void BT(int i)	// 1...8 : i-te Dame
	int k;
	
	for(k=1..8)
		if (feld[i][k] nicht bedroht)
			Setze feld[i][k] besetzt

			if(Brett ist voll)
				Gib Lösung aus; exit
			else
				BT(i+1)
				
			Nimm dame vom feld[i][k]

*/


#include <stdio.h>
#include <stdlib.h>

void BT(int i);
void display();

#define DIM 8
int feld[DIM][DIM];

int main(void) {

	puts("8 Damen: Backtracking");

	// .....
	
	return EXIT_SUCCESS;
}


