# Streams

- F_show
- F_tore
- F_roomtemp
- F_traffic
- F_point
- F_access
- F_klassen_summe
- F_tennis
- F_kochen
- F_noten_prozent
- F_bookmark_counter

---

## F_show

- öffne die Datei show.txt
- und gib alle Zeilen auf die Konsole aus, die mit dem Text <SHOW> beginnen.

Datei: show.txt

~~~ bash
<SHOW>Java Buch: www.javabuch.de
Echt super
<SHOW>C Buch: www.pronix.de
Aber das ist eine Pflicht-Site
<SHOW>Java Source: http://java-source.net/
~~~

Ausgabe:

~~~ bash
Java Buch: www.javabuch.de
C Buch: www.pronix.de
Java Source: http://java-source.net/
~~~

Hinweise:

- BufferedReader, while, readline, != null, indexOf, contains, 
FileNotFoundException, IOException, close

---

## F_tore

Gegeben ist die Datei tore.txt:

~~~bash
tore.txt
groedig:salzburg:0:0
frankfurt:stuttgart:4:5
gladbach:bayer:0:0
real:barca:3:1
~~~

- Lesen Sie die Datei ein und 
- geben Sie die Anzahl der Tore aus, die bei der Partie mit den meisten Toren gefallen sind.

~~~ bash
Beispiel:
9 Tore beim Spiel: frankfurt:stuttgart:4:5
~~~

---

## F-roomtemp

~~~bash
Gegeben: room-temp.txt
3
Schlafzimmer:20
Kueche:25
Keller:15
~~~

- Lies die Daten ein 
- Für alle Zimmer mit einer Temperatur über 19 Grad soll der Text "Fenster öffnen" und der Raumname und die aktuelle Raumtemperatur auf die Konsole ausgegeben werden.
- Schreib die Funktion printDurchschnitt(), die von allen Räumen die Durchschnittstemperatur berechnet und diese auf die Konsole ausgibt.

Beispiel für die Ausgabe zur obigen room-temp.txt:

~~~ bash
Fester öffnen:Schlafzimmer:20
Fester öffnen:Kueche:25
Durschnittstemperatur: 20
~~~

---

## F_traffic

- gegeben ist input.txt
  
~~~ bash
- input.txt
3
Maserati,1000 kg,2 Persons
VM,800 kg,4 Persons
Bus,2500 kg,8 Persons
~~~

- Geben Sie folgendes aus.

~~~bash
With 3 vehicles we transport 14 persons using 4300 kg.
So for 1 person we have to move about 307,14 kg 'vehicle weight'.
~~~

---

## F_access

- Lies die Daten aus access.txt und
- gib die Stringlänge des längsten Dateinamens aus.

Die Datei (mit Beispielsdaten) access.txt
~~~bash
GET /Makefile HTTP/1.1
GET /icon.png HTTP/1.1
GET /welcome.html HTTP/1.1
GET /index.html HTTP/1.1
~~~

Beim Beispiel oben würde 12 ausgegeben werden. (welcome.html)

---

## F_point

- Lies die Daten aus point.txt und
- gib die größte Y-Koordinate aus.

Die Datei (mit Beispielsdaten) points.txt
~~~bash
POINT:x,y
POINT:3,4
POINT:100,99
POINT:10,55
...
~~~

> Beachten Sie, dass die erste Zeile keine Daten sondern eine Art Überschrift darstellt.

Beim Beispiel oben würde 99 ausgegeben werden.

---

  ## F_klassen_summe

- Gegeben ist die Datei: input.txt
- Das Programm gibt auf die Konsole 50 aus.
- d.h. Es werden Werte der Zeilen, die mit 3A= beginnen aufsummiert.

~~~bash
input.txt
5
3A=10 Punkte
4B=3 Punkte
4A=30 Punkte
3A=40 Punkte
1A=4 Punkte
~~~

Hinweise(Java):

~~~ bash
BufferedReader, FileReader,
String input, Integer.parseInt(), 
close, split, readline(), while, != null,
int summe=0
~~~

---

## F_tennis

- Gegeben ist die Datei input.txt (siehe unten)
- Gib pro Zeile (=Spiel) aus, wer wieviele Sätze gewonnen hat.
- Die Ausgabe muss in die Datei output.txt geschrieben werden.

~~~ bash
- input.txt
Diem;Nadal;6:0;6:0;6:0;0:6
Becker;Federer;6:3;6:2;0:6;0:6
Steiner;Muster;6:1;1:6;3:6;3:6

- output.txt 
Diem:3;Nadal:1
Becker:2;Federer:2
Steiner:1;Muster:3
~~~

---

## F_kochen

- Gegeben ist die Datei input.txt

~~~ bash
- input.txt
3 Zutaten
Zucker:100 gramm:100 kcal
Mehl:100 gramm:200 kcal
Nuesse:100 gramm:300 kcal
2 Rezepte
100 gramm Zucker;200 gramm Mehl;300 gramm Nuesse
200 gramm Zucker;100 gramm Mehl;300 gramm Nuesse
~~~

- Gib folgendes in die Datei output.txt aus

~~~ bash
- output.txt
100 gramm Zucker;200 gramm Mehl;300 gramm Nuesse;100+400+900=1400 kcal
200 gramm Zucker;100 gramm Mehl;300 gramm Nuesse;200+200+900=1300 kcal
~~~


Annahme:

- Es kommen immer nur die Zutaten Zucker,Mehl und Nuesse vor.
- pro Rezept wird immer zuerst Zucker dann Mehl und danach Nuesse angegeben.
- pro Zutat werden die kcal immer pro 100 gramm angegeben.

---

## F_noten_prozent

- Gegeben ist die Datei input.txt

~~~bash
- input.txt
Java-Strings:70 Prozent
Java-Streams:30 Prozent
Java-Klassen:20 Prozent
~~~

- Gegeben ist auch folg. Notenschlüssel, den Sie fix in Ihr Programm übernehmen.

~~~bash
- noten-schluessel.txt
00-39 Note 5
40-59 Note 4
60-79 Note 3
80-89 Note 2
90-100 Note 1
~~~

- Folgende Ausgabe soll auf die Konsole gegeben werden:

~~~bash
Du hast im Durchschnitt 40 Prozent erreicht. Dies ergibt die Note 4
~~~

---

## F_bookmark_counter

- Gegeben ist die Datei input.txt

~~~bash
- input.txt
www.htl-salzburg.ac.at:steiner,ziegler,mustermann
www.uni-salzburg.ac.at:volker,wiese,meister,ziegler
www.duckduckgo.com:wald,klein,gross
~~~

- Folgende Ausgabe soll auf die Konsole gegeben werden:

~~~bash
www.htl-salzburg.ac.at:3 Personen
www.uni-salzburg.ac.at:4 Personen
www.duckduckgo.com:3 Personen
~~~

---

## Hinweise

~~~bash
Hinweis: Maximum finden
	Erstes Element sei das Maximum
	über alle Elemente
		Wenn ein Element > als das Maximum
			Merke dieses Element als Maximum


Hinweise: Java
	BufferedReader, readline, split,

Hinweise: C
	stdlib.h, fopen/fclose/fgets, sscanf, malloc/free, 
	struct/typedef, strtok

Hinweis: char * strtok(char *string, char *delimiters);
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
~~~
