# TORE

## AUFGABE: Tore

	* Gegeben ist die Datei tore.txt:
		tore.txt
			groedig:salzburg:0:0
			frankfurt:stuttgart:4:5
			gladbach:bayer:0:0
			real:barca:3:1

	* Lesen Sie die Datei ein und 
	* geben Sie die Anzahl der Tore aus, die bei der Partie mit den meisten Toren
		gefallen sind.

		Beispiel:
			9 Tore beim Spiel: frankfurt:stuttgart:4:5



## Hinweis: Maximum finden
	Erstes Element sei das Maximum
	über alle Elemente
		Wenn ein Element > als das Maximum
			Merke dieses Element als Maximum


## Hinweise: Java
	BufferedReader, readline, split,

## Hinweise: C
	stdlib.h, fopen/fclose/fgets, sscanf, malloc/free, 
	struct/typedef, strtok

## Hinweis: char * strtok(char *string, char *delimiters);
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
