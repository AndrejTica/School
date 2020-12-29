# Wissen: Array/String/Function

~~~ java
/*
myalgo.MyAlgo.java
*/
package myalgo;

public class MyAlgo {


	public static _____________ getMin_idx(_________________) {
		// Gibt den index (auch position genannt) des kleinsten
        // Arrayelementes mit return zurück.
		
        _______________________________________
		return _______________;
	}

	public static _________ suche(int key, ______________) {
        // gibt den index (auch position genannt) des
        // gesuchten Wertes zurück.
        // Wenn key im array nicht enthalten ist, wird
        // -1 zurückgegeben.
		
        _______________________________________
	}

	public static _________ sortiere(______________) {
        // sortiert die Werte im Array aufsteigend.
		
        _______________________________________
	}

// --------------------------------------------------------
// TEIL 2: spezielle Übungen Arrays/Strings
// --------------------------------------------------------
	
	public static ______________ isPrime(int number) {
        // prüft ob number eine Primzahl ist.
		// gibt true oder false zurück.
        _______________________________________
	}
	
	public static void printPrimes(int[] arr) {
        // gibt nur die Zahlen im Array aus,
        // die eine Primzahl sind.
        // verwendet die Funktion isPrime()

        _______________________________________
	}

	public static String dez_toDualString (int zahl) {
        // gibt einen String zurück, der den Paramter zahl als
        // DualString  (besteht nur aus 0 und 1).
        // Bsp: 
        // Paramter zahl hat den Wert 11
        // Die Funktion gibt dann "1011" zurück.
        // oder
        // Paramter zahl hat den Wert 13
        // Die Funktion gibt dann "1101" zurück.

        /* 
        Um eine Dezimalzahl in eine Dualzahl umzuwandeln, 
        kann man folgendermaßen vorgehen:

            13	:	2	= 	6	REST: 1	Stelle: 0
            6	:	2	=	3	REST: 0	Stelle: 1
            3	:	2	=	1	REST: 1	Stelle: 2
            1	:	2	=	0	REST: 1	Stelle: 3

        Die Dualzahl lautet also: 1101

            Kontrolle: 	1*23 + 1*22 + 0*21 + 1*20=
                    1*8 + 1*4 + 0*2 + 1*1 = 
                    8 + 4 + 1=
                    13
        */    

        _______________________________________
    
    }

	public static boolean isLeapYear(int year) {
		/*
		https://www.timeanddate.de/kalender/schaltjahr

		Welche Jahre sind Schaltjahre?
		Der heute gebräuchliche gregorianische Kalender 
        beinhaltet eine Formel mit drei Kriterien,
		nach denen die Jahre in Gemein- und Schaltjahre 
        unterteilt werden:

		1. Schaltjahre müssen durch 4 teilbar sein.
		2. Ist das Jahr auch durch 100 teilbar, ist es 
            kein Schaltjahr, es sei denn...
		3. ...das Jahr ist ebenfalls durch 400 teilbar – dann ist es ein Schaltjahr.

		Beispiele: 
		Die Jahre 2000 und 2400 sind Schaltjahre 
        (infolge Regel 3); 
		Jahre 1800, 1900, 2100, 2200, 2300 und 2500 sind keine Schaltjahre
        (infolge Regel 2 – Regel 3 greift nicht).

		*/

        _______________________________________
	}

}
~~~
