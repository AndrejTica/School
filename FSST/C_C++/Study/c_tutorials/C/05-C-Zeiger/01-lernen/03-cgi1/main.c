/*
 * N.N.
 * 2019

Aufgabe: cgi1.c 
Gegeben sei ein Text, der das Zeichen = enthält. (zB.: nachname=meier). 
Schreiben Sie die Funktion cgi(), die als 
    • Input (Funktionsparameter) den Text bekommt und 

folgende Informationen zurück gibt:
    • Adresse des Zeichens =
    • Anzahl der Zeichen vor dem = Zeichen
    • Anzahl der Zeichen nach dem = Zeichen


todo:
    • Entwerfen Sie einen Prototyp/Funktionsdeklaration für die Funktion cgi()
    • Programmieren Sie die Funktion cgi()
    • Erstellen Sie ein kleines Testprogramm
 */
 
 #include <stdio.h>
 
 _______ cgi (_____________________________);
 
 int main(){
 	char txt[128+1];
 	char* pgleich;
 	int anz_vor;
 	int anz_nach;
 	
 	printf("Text? (name=wert)? ");
 	gets(txt);
 	
 	pgleich= cgi (txt, __________, ________);
 	
 	printf("Anzahl vor dem Zeichen = ist: %i\n", anz_vor);
 	printf("Anzahl nach dem Zeichen = ist: %i\n", anz_nach);
 	printf("Adresse vom Zeichen = ist: %p\n" , pgleich);
 	printf("Das = Zeichen anzeigen: %c\n\n" , *pgleich); 
 
 	return 0;
 }
 
_______ cgi (_____________________________){
  
  
  
  
  
}

