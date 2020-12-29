# OOP1: Hangman

~~~
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

...
	String word2show;
	String word2guess;
	String inputChar;
	String inputWord;

	boolean debug= true;
	
	// INIT game variables that are hidden in module hangman
	Hangman game= new Hangman();

	
	do {

		// GET game variables
		word2show= game.getWord2show();
		word2guess= game.getWord2guess();
		
		if (debug)
			System.out.println("\n                          wort= " + word2guess);
		
		
		// PROMPT 
		System.out.println(word2show);
		System.out.println(" your choice (#wrong: " + game.getBadTries() +"/"+ game.getMaxTries()+ ")?");

		// GET USER input
		inputChar= ..................;

		// TRY user input
		if (inputChar.equals("#") ){
			System.out.print("=> enter your word? ");
			inputWord=...........................;
			game.tryWord(inputWord);
		}else{
			game.tryChar(inputChar);
		}

		
	}while ( ! game.gameOver());


	if (game.success()){
		System.out.println("\nYOU MADE IT !!! " + word2guess);
	}else{
		System.out.println("\nBETTER YOU TRY AGAIN\n");
	}
...
~~~
