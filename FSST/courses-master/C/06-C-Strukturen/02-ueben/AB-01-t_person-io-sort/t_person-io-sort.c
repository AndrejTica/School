/*
 * @name N.N.
 * @date
 *
 * @description
 * --------------------------------------------------------------------------------
 *  Schreibe ein Programm, das
 *  1. Den Strukturtyp TPERSON (Komponenten: char name[128], int persnr) 
 *     enthält. 
 *     Verwenden Sie typedef um den namen TPERSON verwenden zu können.
 *
 *  2.Definiere das Array mit dem Namen wir (mit 5 Elementen 
 *    vom Typ TPERSON).
 *
 *  3.Lies von der Tastatur 5 Datensätze in wir ein
 *
 *  4.sortiere das Array nach der Komponente
 *      a) persnr
 *      b) name
 *
 *    Verwende dabei folgende Funktionen
 *    void sort_by_name(TPERSON *p, int anzahl);
 *    void sort_by_persnr(TPERSON *p, int anzahl);
 *
 *
 *  5.Gib jeweils nach dem Sortieren das Array wir unter 
 *    Verwendung folgender Funktion aus:
 *
 *   void ausgabe(TPERSON *p, int anzahl);
 *  */

#include <stdio.h>

// F-decl
void sort_by_name(TPERSON *p, int anzahl);
void sort_by_persnr(TPERSON *p, int anzahl);
void ausgabe(TPERSON *p, int anzahl);

int main(int argc, char* argv[]){


    return 0;
}

