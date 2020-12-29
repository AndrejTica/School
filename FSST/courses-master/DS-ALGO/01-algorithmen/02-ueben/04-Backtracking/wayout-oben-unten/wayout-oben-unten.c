/*
Aufgabe: "Von oben nach unten"

Gegeben ist die folgende 'Karte', die mit
1 einen Weg und mit 0 keinen Weg markiert.
Schreiben Sie ein Programm, das ermittelt,
ob es einen Weg von oben nach unten gibt.

Hier die Karte:
			oben
Zeile 0:	00100
Zeile 1:	01100
Zeile 2:	01010
Zeile 3:	01001
Zeile 4:	00001
			unten

Aufruf: if (wayout(0))
			printf("Es gibt einen Weg!");
		else
			printf("Es gibt keinen Weg!");


Die Funktion:
bool wayout(int zeile){
	for alle spalten
		if spalte==1
			ist spalte bestandteil des bishergen weges?
			ja:
				if zeile < unten
					return wayout(zeile+1)
				else
					return true // weg gefunden
			nein:
				continue nächste spalte;
		else
			continue nächste spalte;
	end for
	return false;
}

*/

// Hier eine Lösung
// wayout-oben-unten.c
#include <stdio.h>

int lab[5][5]={
	{0,0,1,0,0},
	{0,1,1,0,0},
	{0,1,0,1,0},
	{0,1,0,0,1},
	{0,0,0,0,1}
};


int wayout(int zeile){
	// ????????????????????
}

int main(){

	if (wayout(0))
		printf("Es gibt einen Weg!\n");
	else
		printf("Es gibt keinen Weg!\n");

	return 0;
}

