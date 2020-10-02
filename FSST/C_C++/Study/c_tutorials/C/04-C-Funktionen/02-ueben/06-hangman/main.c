/*
1.2.  Aufgabe: Hangman
Realisieren Sie das bekannte Wortratespiel auf dem Computer. Zeigen Sie zunächst von einem zu ratenden Wort für die einzelnen Zeichen jeweils nur Striche an. 
Anschließend fragen Sie nach Buchstaben. Sollten die Buchstaben im zu ratenden Wort vorkommen, so werden die entsprechenden Positionen aufgedeckt, d.h. an dieser Stelle
werden die tatsächlichen Zeichen angezeigt. Durch Eingabe eines Zeichens (z.B. '#' – welches dann in keinem Wort vorkommen darf) kann das Raten abgebrochen werden und die Eingabe des vollständigen Worts ist nun möglich. Stimmt das eingegebene Wort mit dem verdeckten Wort überein, ist das Spiel zu Ende, ansonsten wird wieder in den obigen Buchstabenratemodus zurückgekehrt.

Beispiel: Zu ratendes Wort: "Hangman" (verdeckt)
- - - - - - - 	Eingabe (a)
- a - - - a - 	Eingabe (g)
- a - g - a - 	Eingabe (e)
- a - g - a - 	Eingabe (n)
- a n g - a n 	Eingabe (#) ~ Ende Buchstabenraten

Eingabe: Hangman →  richtig geraten / bzw. Zurückkehren zum Buchstabenraten

Hinweis: 
Sie können das Spiel abwechslungsreicher gestalten, wenn Sie sich eine Tabelle von zu ratenden Wörtern im Programm anlegen und aus dieser Tabelle zufällig einen Eintrag auswählen, anstatt diesen vorher einzugeben.

=========
1. ANALYSE (WAS)
2. ENTWURF (WIE)
	2.1. Grobentwurf (Module, Datenstrukturen; Aufteilung auf Personen)
	2.2. Feinentwurf (*.h)
3. IMPLEMENTIERUNG
	3.1. Grobgerüst ('leere' Funktionen)
	3.2. Feinimplementierung ('fertige' Funktionen)
4. TESTS
5. ABNAHME
==========
*/

#include <stdio.h>

#include "hangman.h"

int main(){
	char word2show[80+1];
	char word2guess[80+1];
	char inputChar;
	char inputWord[80+1];


	// INIT game variables that are hidden in module hangman
	newGame();
	
	do {

		// GET game variables
		getWord2show(word2show);
		getWord2guess(word2guess);
		
//#define DEBUG
#ifdef DEBUG
		printf("\n                         wort= <%s>" , word2guess);
#endif
		
		
		// PROMPT 
		printf("\n%s" , word2show);
		printf(" your choice (#wrong: %i/%i)? ",
                                getBadTries(),getMaxTries());

		// GET USER input
		inputChar= fgetc(stdin);
		fgetc(stdin);

		// TRY user input
		if (inputChar=='#'){
			printf("=> enter your word? ");
			gets(inputWord);
			tryWord(inputWord);
		}else{
			tryChar(inputChar);
		}

		
	}while (!gameOver());


	if (success()){
		printf("\n<%s> YOU MADE IT !!!\n", word2guess);
	}else{
		printf("\nBETTER YOU TRY AGAIN\n");
	}

	return 0;

}
