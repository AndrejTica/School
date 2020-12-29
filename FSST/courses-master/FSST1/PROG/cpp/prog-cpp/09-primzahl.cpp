/* 9. Beispiel: Primzahl
	Lies eine integer Zahl (n) ein. 
	Das Programm soll nur eine positive Zahl größer gleich 2 zulassen. 
	Gib aus, ob es sich um eine Primzahl handelt.

	Gegeben ist folgender Programmablaufplan für einen Primzahltest:
	Wir testen zunächst, ob die Testzahl gerade ist und 
	prüfen dann alle ungeraden Zahlen (>2) bis zur Testzahl (n) als mögliche Teiler (t). 
	Damit ließe sich der Primzahltest nun wie folgt beschreiben: 

	* Einlesen der Testzahl n. 
	* Wenn n den Wert 2 oder 3 Ausgabe: „Primzahl“
	* Sonst Weise der Variablen teiler den Wert 3 zu. 
	* Wiederhole bis teiler kleiner der Testzahl n ist: 
	* Ist n durch teiler teilbar? Wenn ja,Ausgabe: "keine Primzahl". Programmende
	* Erhöhe den Wert von teiler um 2. 
	* Ausgabe: n "ist eine Primzahl". 
*/
