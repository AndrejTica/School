1.4.1.  Aufgabe: Modul stack, Ein Taschenrechner
Ein bekanntes Übungsbeispiel für Funktionen ist ein Taschenrechner, 
der sogenannte postfix-Ausdrücke verarbeiten kann. 
(auch umgekehrte polnische Notation genannt).

Hier ein Beispiel:
	Benutzereingabe:
	12    2   *   4   +   2   /    =

	Ausgabe:
	Ergebnis=14.00

Wir sind zwar eher mit der infix-Notation vertraut. 
Der obige Ausdruck ist infix: 
	(12 * 2 + 4) / 2

Der Computer kann allerdings bei postfix-Ausdrücken enorm effizient arbeiten, 
sodass viele Programme diese Form bevorzugen. 

Es muss also ein Konvertierungsprogramm infix2postfix erstellt werden. 
Wir wollen uns hier zunächst diesem Problem nicht stellen und 
unser Augenmerk auf die Verarbeitung von postfix-Ausdrücken widmen.


Verarbeitung v. Postix-Ausdrücken:
	- wenn ein Operand/Zahl eingelesen wird, leg diesen auf den stack.
	- Wenn ein Operator eingelesen wird, hole die Operanden vom stack und 
		berechne den Ausdruck und gib das Ergbnis auf den stack
 
Hinweis: stack
	ist ein Speicher zum Ablegen (als Stapel) von Daten 
	(also ein stack ist ein sog. Stapelspeicher), 
	der intern als Array realisiert sein kann.

	Die Funktionen zum Arbeiten mit dem stack lauten:
    - void push(double value);
		legt einen Wert auf den stack

    - double top(void);
		holt den zuletzt auf den stack gelegten Wert

    - void pop(void);
		dekrementiert den Stackpointer, d.h. der Stack hat ein Element 
		weniger auf dem Stack.
		
	Daraus folgt, dass der stack eine LIFO-Datenstruktur ist. 
	(Last In First Out)


Wir wollen den stack als Modul implementieren, sodass wir diesen auch 
in anderen Programmen verwenden können.

Aufgabe:
- Download: u_taschenrechner.zip
- Bringen Sie das Programm zum Laufen
