/* 
 * ahofmann, 2019
 * 
 * meine-noten
 */


/** 

AUFGABE:
- Das Programm liest eine Datei mit folg. Aufbau ein. 
- Datei: noten-MAX-MUSTERMANN.txt 
>=87.5%Note1 
>=75.0%Note2 
>=62.5%Note3 
>=50.0%Note4 
WANN:ERREICHBARE-PUNKTE:ERREICHTE-PUNKTE:BESCHREIBUNG 
2013.02.10:25:10:C-Arrays 
2013.03.10:25:20:C-Funktionen 
2013.04.22:25:4:C-Dateien 
2013.05.01:25:5:C-Strukturen 

- Folgende Ausgabe auf den Bildschirm soll dann erzeugt werden: 
Name:			MAX MUSTERMAN 
Punktestand: 		39 Punkte von 100 
Prozent:     		39% 
Note: 				5 
Schlechtestes Ergebnis: 	2013.05.01:20:4:C-Dateien 
Bestes Ergebnis: 		2013.03.10:20:20:C-Funktionen 
*/


#include <iostream>

using namespace std;

#include "notenmanager.h"


int main()
{

    Notenmanager man("Anton Hofmann");

    man.readFromFile("./noten-anton-hofmann.txt");

    man.printResult();


    return 0;
}
