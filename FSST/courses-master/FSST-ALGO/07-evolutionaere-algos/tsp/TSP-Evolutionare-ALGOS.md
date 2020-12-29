# Traveling Salesman Problem / Der Handlungsreisende
--------------------------------------------------
file: TSP-Evolutionaere-ALGOS.md

# Aufgabe:
---------
Die Aufgabe besteht darin, 

* eine Reihenfolge für den Besuch mehrerer Orte so zu wählen, dass die gesamte Reisestrecke möglichst kurz und 
* die erste Station gleich der letzten Station ist.

Anwendung:

* in der Tourenplanung, 
* in der Logistik oder 
* im Design von Mikrochips. 


Exakte Lösungen?

Das Problem des Handlungsreisenden kann exakt gelöst werden, indem man die Weglängen aller möglichen Rundreisen berechnet und dann eine mit der kleinsten Weglänge auswählt. 

Bei n Städten, gibt es ( n − 1 ) ! / 2  verschiedene Rundreisen, das sind bei 15 Städten über 43 Milliarden und bei 18 Städten bereits über 177 Billionen. Wie schnell die Rechenzeit mit wachsender Anzahl von Städten wächst, zeigt das folgende Beispiel: Hat man einen Rechner, der die Lösung für 30 Städte in einer Stunde berechnet, dann braucht dieser für zwei zusätzliche Städte annähernd die tausendfache Zeit; das sind mehr als 40 Tage.


# Lösung durch evolutionäre Algorithmen:
---------------------------------------
<https://de.wikipedia.org/wiki/Evolution%C3%A4rer_Algorithmus>


Anlehnung an die Natur:

In der biologischen Evolution sind Organismen natürlichen Mutationen ausgesetzt.
Mutationen können sich positiv, negativ oder gar nicht auf Erben auswirken. 
Da es zwischen erfolgreichen Individuen zur Fortpflanzung (Rekombination) kommt, 
können sich Arten über lange Zeiträume an einen vorliegenden Selektionsdruck anpassen (z. B. Klimaveränderungen). 

Dabei wird die Güte eines Lösungskandidaten explizit mit einer Fitnessfunktion berechnet, sodass verschiedene Kandidaten vergleichbar sind.


Ablauf:

Das grobe Verfahren evolutionärer Algorithmen besteht meist aus einer Initialisierung und einer Schleife, die solange durchlaufen wird, bis ein Abbruchkriterium erfüllt ist:
~~~
    Initialisierung: Die erste Generation von Lösungskandidaten wird (meist zufällig) erzeugt.
    Evaluation: Jedem Lösungskandidaten der Generation wird entsprechend seiner Güte ein Wert der Fitnessfunktion zugewiesen.
    Durchlaufe die folgenden Schritte, bis ein Abbruchkriterium erfüllt ist:
        Selektion: Auswahl von Individuen für die Rekombination (Fortpflanzung)
        Rekombination: Kombination der ausgewählten Individuen
        Mutation: Zufällige Veränderung der Nachfahren
        Evaluation: Jedem Lösungskandidaten der Generation wird entsprechend seiner Güte ein Wert der Fitnessfunktion zugewiesen.
        Selektion: Bestimmung einer neuen Generation
~~~

Beispiel: Ein erstes Konzept: TSP

Die Klasse Ort:
	* speichert Orstpositionen, die zufällig gewählt werden
	* x,y
	* name
	
Die Klasse Tour:
	* speichert bestehende Ort zufällig ins Array (=Tour)
	* Ort[] orte
	* getGesamtStrecke()

Die Klasse TourenContainer:
	* speichert mehrere Touren
	* Tour[] touren
	* Selektion: wähle 80% der besten/kürzesten Touren
	* Rekombination/Fortpflanzung: mutiere .....
	* Evaluation: ....
	
