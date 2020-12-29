# Wissen: OOP

## Frage 1

~~~
1. (3) ____________________________________________________________________
* Klasse: Datum
Member:
	tag, monat,jahr
Methoden:
	Allg. konstruktor
	istSchaltJahr()    // siehe Hinweis:
	toString()

Hinweis:
	if (jahr%4 == 0 && jahr%100 != 0 || jahr%400 == 0)
			return 1;	//jahr ist ein schaltjahr
	else
			return 0;

2. (3) ____________________________________________________________________
(w)ahr oder (f)alsch
a. (  ) Ein Objekt ist die Erweiterung einer Klasse und erbt deren 
		Eigenschaften.
b. (  ) Bank und Konto stehen zueinander in einer is-A-Beziehung
c. (  ) Eine Klasse kann Daten (Member), Methoden und Konstruktoren 
		enthalten.
d. (  ) Beim Erzeugen eines Objektes wird der Konstruktor aufgerufen.
e. (  ) Der Default-Konstruktor hat mindestens einen Parameter.
f. (  ) Die Erweiterung einer Klasse erbt die Member und Methoden der 
		Oberklasse. 
		Es können jedoch weitere Daten und Methoden hinzugefügt werden.
g. (w)  Java ist eine objekt-orientierte Programmiersprache.
	
	
Antworten:
1.) public class .............
~~~


## Frage 2

~~~
Erstelle die Klassen Auto und Garage mit den notwendigen Member
-Variablen und Methoden, sodass folgendes Beispiel funktioniert:

    Auto maserati = new Auto("Maserati", 700.0);
    Auto vw = new Auto("VW Golf", 900.0);
    …
    System.out.println("Gewicht von  maserati= " + maserati.getGewicht());
    …
    Garage post = new Garage("Post");
    post.add(maserati);
    post.add(vw);
    …
    double gesamtgewicht = post.getGesamtgewicht();
    System.out.println("Das Gesamtgewicht ist " + gesamtgewicht);

Vergiss die entsprechenden Methoden
bei Auto
    (Konstruktor, double getGewicht()) bzw.
bei Garage
    (Konstruktor, void add(Auto pAuto), double getGesamtgewicht()) nicht.

~~~

## Frage 3 

~~~
mab-java-oop1-point-line.txt (7)
===========================================================================

Given: Point.java
	public class Point {
	   private int x;    // x co-ordinate
	   private int y;    // y co-ordinate
	   
Q(1):	   public Point (int x, int y) {
		___________________________________________________________________

		___________________________________________________________________

		}

Given: Line.java
	public class Line {
		// A line composes of two points (as instance variables)
		private Point begin;    // beginning point
		private Point end;      // ending point

		// Constructors
Q(1):		public Line (Point begin, Point end) {

		___________________________________________________________________

		___________________________________________________________________

		}

Q(2):		public Line (int beginX, int beginY, int endX, int endY) {

		___________________________________________________________________

		___________________________________________________________________


		}

Given: TestLine.java
	public class TestLine {
	   public static void main(String[] args) {
		  Line line1 = new Line(0, 0, 3, 4);
	   
		  Point p1 = new Point("x:10,y:10");
		  Point p2 = new Point(20,20);  // x-coordinate and y-coordinate
		  Line line2 = new Line(p1, p2);

		  double len= line2.getLength();  // Math.sqrt(xDiff*xDiff + yDiff*yDiff)
	   }
	}

Q(2): Write the constructor for: Point p1 = new Point("x=10,y=10");
		public Point(__________________________________){

		___________________________________________________________________

		___________________________________________________________________

		___________________________________________________________________

		___________________________________________________________________

		___________________________________________________________________

		___________________________________________________________________
		}


Q(1): Write member function for:  int len= line2.getLength();  
			// Math.sqrt(xDiff*xDiff + yDiff*yDiff)

		public ______________ getLengthPoint(_______________________){

		___________________________________________________________________

		___________________________________________________________________

		___________________________________________________________________

		___________________________________________________________________

		___________________________________________________________________

		___________________________________________________________________
		}

Hint:
// Hinweis: Text zerlegen
//	String[] teile= "ABC:DEF:GHI".split(":");
//	teile[0] ... enthält dann ABC
//	teile[1] ... enthält dann DEF
//	teile[2] ... enthält dann GHI

~~~