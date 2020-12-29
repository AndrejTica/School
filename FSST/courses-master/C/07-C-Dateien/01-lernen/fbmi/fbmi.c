/*
fbmi.c
=====================================================================
Das Programm soll:
+ geeignete Datenstruktur/Datentypen/Klasse definieren
	siehe: C-Strukturen
	
+ die Datei input.txt in ein dynamisches Array laden
	siehe: C-Zeiger, C-Dateien
	
+ die fehlenden Werte für den BMI (gewicht_kg/(groesse_m*groesse_)
	berechnen.
	Erstellen Sie:
	double getBMI(double gewicht_kg, double groesse_m);
	
+ die Datei output.txt beschreiben

Hinweis Aufbau: input.txt
klasse,vorname,nachname,gewicht,groesse

Beispiel: input.txt
3
4cheli,anton,hofmann,70,170
4cheli,beta,hofmann,80,180
4cheli,gamma,hofmann,90,190

Inhalt der Datei output.txt:
klasse,vname,nname,gewicht,groesse,maxbmi


Hinweis: Zum Einlesen verwenden Sie
fgets(), strtok(), 
http://www.c-howto.de/tutorial-strings-zeichenketten-stringfunktionen-zerteilen-strtok.html

Hinweis: Zur Typumwandlung verwenden Sie
sscanf()

*/


