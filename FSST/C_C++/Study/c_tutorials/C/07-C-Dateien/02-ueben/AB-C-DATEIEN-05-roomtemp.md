# ROOM-TEMP

C, Dateien, Strukturen, Zeiger

## AUFGABE: ROOM-TEMP.c
	Zu erstellen ist ein vollständiges C-Programm (room-temp.c).

	Gegeben: room-temp.txt
		3
		Schlafzimmer:20
		Kueche:25
		Keller:15


	1. (2) Definiere geeignete Datenstruktur-Typen (in C) zur Verarbeitung der
		obigen Daten.

	2. (2) Lies die Daten in ein 
	   (2) mit malloc() zu alloziierendes Array.

	3. (2) Für alle Zimmer mit einer Temperatur über 19 Grad soll der Text
		"Fenster öffnen" und der Raumname und die aktuelle Raumtemperatur 
		auf die Konsole ausgegeben werden.

	4. Schreib die Funktion printDurchschnitt(), die von allen Räumen die
		Durchschnittstemperatur berechnet und diese auf die Konsole ausgibt.
		4.1. (2) Wie lautet der Funktions-Prototyp
		4.2. (2) Wie lautet der Funktions-Aufruf.
		4.3. (2) Die Funktion printDurchschnitt() ausprogrammiert.
	 

	Beispiel für die Ausgabe zur obigen room-temp.txt:
		Fester öffnen:Schlafzimmer:20
		Fester öffnen:Kueche:25
		Durschnittstemperatur: 20

### Schlagworte
	stdlib.h, fopen/fclose/fgets, sscanf, malloc/free, 
	struct/typedef, strtok

### Hinweis: char * strtok(char *string, char *delimiters);
	char string[] = "Kurt,Kanns;555678;DE";
	char delimiter[] = ",;";
	char *ptr;

	// initialisieren und ersten Abschnitt erstellen
	ptr = strtok(string, delimiter);

	while(ptr != NULL) {
		printf("Abschnitt gefunden: %s\n", ptr);
		// naechsten Abschnitt erstellen
	 	ptr = strtok(NULL, delimiter);
	}

	Abschnitt gefunden: Kurt
	Abschnitt gefunden: Kanns
	Abschnitt gefunden: 555678
	Abschnitt gefunden: DE

## FRAGEN:
	2.1. (3) Erklärung für:
		a) static global    b) cast operator     c) call-by-reference

	2.2. (8) wahr oder falsch (inkl. Begründung)
		a) char* p1; double* p2;  sizeof(p2) > sizeof(p1)   ....liefert true
		b) int wert; scanf("%i", &wert);
		c) Das letzte Zeichen löschen: str[strlen(str)]= '/0';
		d) int x=5, y=2; float erg; erg= x/y;  printf("%.1f", erg); ... gibt 2.5 aus

	2.3. (1) Definieren Sie ein Array namens a mit 10 Zeigern auf char als Elementen

