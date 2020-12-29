# JAVA PROJEKT: Spiele programmieren
---

Sie sollten folgende Punkte beachten:

1. Aufgabenstellung/Spielanleitung
2. Entwurf
3. Programmieren/Testen
4. Dokumentation
5. Abgabe/Präsentation


## 1. Aufgabenstellung (WAS?)
	* Beschreibung WAS zu tun ist.
	* Teilsysteme benennen.
	* Spielanleitung (für den Spieler)

## 2. Entwurf (WIE?)
	* Klassendiagramm der wichtigsten Komponenten

	* Die wichtigsten Klassen
		* Klassenname:
		* private Member:
		* public Methoden: 
		...
	* Animation
		
	* User-Interface

## 3. Programmieren/Testen
	* Prototypen bauen und testen (selbst und andere)


## 4. Dokumentation
	* siehe java-project-name1-name2.html

## 5. Beurteilung
	1. Programm starten und das Spiel spielen
	2. Programmsource erklären können
	2.1. Programmstart
	2.2. Userinteraktion
	2.3. Animation
	2.4. Das Zeichnen
	3. Verwendung v. einfachen GUI Elementen beherrschen
		(JLabel erzeugen und verwenden)

## 6. Abgabe/Präsentation
	* beim Tag der offenen Tür präsentieren
	* im FSST-Unterricht abgeben



## 7. Beispiel: SNAKE

### 1. Aufgabenstellung
	Die Schlange befindet sich in einem Spielfeld. 
	Das Spielfeld ist begrenzt durch Mauersteine.
	Es gibt nur einen Ausgang.
	Im Spielfeld befinden sich Äpfel und Mauersteine.
	
	
### 2. Spielanleitung: 	
	Ziel des Spieles ist es, Äpfel zu sammeln.
	Die Schlange muss die Äpfel auf dem Spielfeld fressen. 
	Mit jedem gefressenem Apfel wächst die Schlange.
	
	Die Schlange darf sich nicht selber berühren und 
	auch nicht gegen die Wand laufen oder gegen einen 
	Mauerstein im Spielfeld. Denn dann ist das Spiel beendet.	
	
	Spielsteuerung:
	Starten mit Klick auf den Start-Button.
	Die Schlange wird mit den Pfeiltasten gesteuert.


### 2. Entwurf / Klassen
	Klassenname: Snake
	private member: spielfeld, laenge, farbe, ...
	public methoden: Kontruktor, getter/Setter, paint, move
	
	Klassenname: Apple
	private member: ....
	public methoden: ....
	
	...
	
### 3. Entwurf/Animation (s. SpielFirstGame)
	Timer (Delay)
		actionGame()
		repaint()
		
	paint()
		zeichnet das Spielfeld
		Snake.repaint()

	actionGame()
		snake.move()
		...


### 4. Entwurf / User-Interface
	KeyPressed()
		if up
			snake.setDirection(up)
		...

# Viel Erfolg! 
========================

