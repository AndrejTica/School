# Java Streams

- F_cat
- F_cp
- F_tar
- F_homepage
- F_spam1
- F_spam2
- F_wc
- F_reverse
- F_random_int_data.java
- F_sort_int_data.java

---

## F_cat.java

Lies den Namen einer Textdatei ein.
Lies diese Textdatei zeilenweise ein und gib den Text mit führenden Zeilennummern auf die Konsole aus. 

---

## F_cp.java

Lies den Namen von 2 Textdateien ein und kopiere den Inhalt der ersten Datei in die zweite Datei.

---

## F_tar.java

Lies den Namen der Steuerdatei von der Konsole ein (zB.: mytar.txt). In dieser Datei stehen die Namen der Dateien, die alle in eine Datei kopiert/angehängt werden sollen.

zB: Bestehe der Inhalt der Datei mytar.txt aus folgenden Zeilen:

~~~bash
ziel.xml
datei1.txt
datei2.txt
datei3.txt

Es sollen die Dateien 
datei1.txt
datei2.txt
datei3.txt

in die Datei ziel.xml kopiert werden.
~~~

Dabei sollen die Dateien in folgender Weise gespeichert werden:

~~~ bash
ziel.xml:
<?xml version="1.0" ?>
<fileset>
<file name="datei1.txt">
..... Inhalt der datei1.txt
</file>
<file name="datei2.txt">
..... Inhalt der datei2.txt
</file>
....
</fileset>
~~~

---

## F_homepage.java

- Lies von der Konsole folg. Informationen ein: 
  - Name, adresse1, adresse2, email, url 
- Und erstelle eine sog. homepage mit dem Namen: home.htm

~~~bash
Hinweis: Suche bei selfhtml nach einem HTML-Grundgerüst: http://de.selfhtml.org/navigation/html.htm 
~~~

---

## F_spam1.java

- Lies den Namen einer Textdatei von der Konsole ein (zB: mail.txt) und 
- lies den Namen eines Wortes (zB: Bombe) ein.

- Öffne die Datei und lies zeilenweise ein.
- Schreib die Zeilen, in denen das gelesene Wort (z.B.: "Bombe") (gross- oder kleingeschrieben) vorkommt in die Datei mail-spam.txt.
- Alle anderen Zeilen sollen in die Datei mail-notspam.txt geschrieben werden. 

---

## F_spam2.java

- Öffne die Datei blacklist.txt und lies die darin enthaltenen Wörter in ein Array.

- Lies den Namen einer Textdatei von der Konsole ein (zB: mail.txt). 
- Öffne die Datei und lies zeilenweise ein.
- Schreib die Zeilen, in denen ein Wort aus blacklist.txt (gross- oder kleingeschrieben) vorkommt in die Datei mail-spam.txt.
- Alle anderen Zeilen sollen in die Datei mail-notspam.txt geschrieben werden.

Hinweis: (Aufbau der Datei blacklist.txt  Pro Zeile ist ein Wort enthalten)

~~~ bash
blacklist.txt:
...
Bombe
Porno
...
~~~

---

## F_wc.java

- Lies eine Textdatei ein und 
- gib aus wieviele Zeichen, Zeilen und Wörter enthalten sind und
- gib ein Histogramm aller Zeichen aus.

---

## F_reverse.java

- Lies die Namen von 2 Dateien von der Konsole ein. - Lies die erste Datei zeilenweise ein und 
- gib diese Zeilen in umgekehrter Reihenfolge in die zweite Datei aus.

---


## F_random_int_data.java

- Write a program that creates a file containing TotalCount random integers (in character format) in the range 0 to HighValue-1. 
- Write PerLine integers per line. 
- Separate each integer with one space. 
- End each line with the correct line termination for your computer.

- The user is prompted for and enters HighValue, which should be an integer larger than zero.
- Then the user is prompted for and enters PerLine, which is an integer greater than zero, 
- and TotalCount, which also is an integer greater than zero. 
- Finally the user is prompted for and enters the file name.

~~~ bash
Hint:
java.util.Random rnd= new java.util.Random();
int num= rnd.netInt(100); // returns 0..99


C:\Programs>java  F_random_int_data
Enter HighValue-->100
Enter how many per line-->10
Enter how many integers-->100
Enter Filename-->rdata.dat
C:\Programs>type rdata.dat
4 12 54 10 38 97 40 11 80 16
36 41 67 67 93 58 62 12 50 99
18 42 9 28 45 6 68 72 80 28
86 63 22 17 68 18 59 50 6 50
90 8 68 61 9 24 77 34 62 61
63 8 15 17 67 58 34 56 12 50
43 85 39 77 30 68 89 88 65 68
84 29 42 74 48 55 19 82 95 3
39 27 25 96 41 39 18 84 39 88
82 58 84 90 74 35 24 89 85 92
~~~

## F_sort_int_data.java

- Lies aus der Textdatei namens rdata.dat Zahlen ein
- sortiere die Daten aufsteigend
- Schreib nun das sortierten Daten in die Datei namens rdata-sorted.dat

~~~ bash
Hinweis: rdata.dat
4 12 54 10 38 97 40 11 80 16
36 41 67 67 93 58 62 12 50 99
18 42 9 28 45 6 68 72 80 28
86 63 22 17 68 18 59 50 6 50
90 8 68 61 9 24 77 34 62 61
63 8 15 17 67 58 34 56 12 50
43 85 39 77 30 68 89 88 65 68
84 29 42 74 48 55 19 82 95 3
39 27 25 96 41 39 18 84 39 88
82 58 84 90 74 35 24 89 85 92
~~~
