# OOP1: Klassen, Objekte, Methoden

## First of all

1. Create project: 04-JAVA-OOP1-complex-fraction-point-datum
2. Create package: oop1 and test
3. Create class: Complex, Fraction, Point, Datum in package oop1
4. Create Test-Programs T_Xxxxx.java (see below) to test your classes in oop1

---

## Beispiel: Eine Klasse planen

Wie man eine eigene Klasse erstellt zeigt das folgende Beispiel. Man geht folgendermaßen vor:

1. Überlege einen aussagekräftigen Namen für die neue Klasse:

~~~ java
public class Complex
~~~

2. Welche Daten verwaltet die neue Klasse?

~~~java
double re; // Realteil
double im; //Imaginärteil
~~~

3. Wer darf diese Daten ändern? zB: nicht alle 

~~~java
private double re; // Realteil
private double im; //Imaginärteil
~~~

4. Wie sollen Objekte erzeugt werden können.

~~~java
Complex z1= new Complex(3.0, 4.0); // Konstruktion mittels Angabe v. re und im
Complex z2= new Complex(5.0, 6.0); // Konstruktion mittels Angabe v. re und im
~~~

5. Welche Methoden soll es geben?

~~~java
Complex z3= z1.add(z2);
String s= z3.toString();
~~~



## Aufgabe: test.T_Fraction.java

~~~java
//Create the class Fraction so that the following code works.
import oop1.Fraction;

public class T_Fraction{
	public static void main(String[] args){

		Fraction a= new Fraction(3.0, 2.0);
		Fraction b= new Fraction(a);
		Fraction c;
	
		c= a.mul(b);
		System.out.println ("c= " + c.toString());
		
	//	The output should be:
	//	c= [9.0 / 4.0]

	}

}	
~~~

---

## Aufgabe: test.T_Point.java

~~~java
//Create the class Point so that the following code works.

package test;
import oop1.Point;

public class T_Point{
	public static void main(String[] args){

		Point a= new Point(0, 200);   // x-coordinate, y-coordinate
		Point b= new Point(a);
		Point c;
	
		c= a.add(b);	// add the coordinate-values	
		System.out.println ( "c= " + c.toString());


	//The output should be:
	//c= [0,400]

	}

}
~~~

---

## Aufgabe: test.T_Datum.java

~~~java
package test;

import oop1.Datum;

public class T_Datum {

	public static void main(String[] args) {
		Datum geburtstag, zeugnistag;
		Datum heute;
		boolean bSchaltJahr;

		// ----------------------------------------------
		geburtstag= new Datum(1,1,2013);

		// ----------------------------------------------
		// Ausgabe des Datums MUSS in eckigen Klammern erfolgen
		// [1.1.2013]
		System.out.println("Geburtstag ist am " + geburtstag.toString());


		// ----------------------------------------------
		heute= new Datum();

		// ----------------------------------------------
		bSchaltJahr= heute.istSchaltjahr();

		if (bSchaltjahr == true)
			System.out.println("Heuer ist ein Schaltjahr");
		else
			System.out.println("Heuer ist kein Schaltjahr");

		// ----------------------------------------------
		zeugnistag= new Datum("7.7.2013");
		System.out.println("Zeugnistag ist am " + zeugnistag.toString());

	}

}

//			Hinweis: Schaltjahr
//				if (jahr%4 == 0 && jahr%100 != 0 || jahr%400 == 0)
//						return 1;	//jahr ist ein schaltjahr
//				else
//						return 0;


// Hinweis: aktuelles Datum ermittlen
//			java.util.Calendar today= java.util.Calendar.getInstance();
//			int tag= today.get(java.util.Calendar.DATE);
//			int monat= today.get(java.util.Calendar.MONTH);
//			int jahr= today.get(java.util.Calendar.YEAR);

// Hinweis: Text zerlegen
//			String[] teile= "ABC:DEF:GHI".split(":");
//			teile[0] ... enthält dann ABC
//			teile[1] ... enthält dann DEF
//			teile[2] ... enthält dann GHI
~~~

---

## Aufgabe:  Die Klasse oop1.Complex.java

Bringen Sie folgendes Programm zum Laufen:

- Projekt: JAVA-OOP1-complex-fraction-point-datum
- Datei: oop1.Complex.java, T_Complex.java

~~~java
package oop1;

/**
 * http://de.wikipedia.org/wiki/Komplexe_Zahl
 * 
 * @file Complex.java
 * @date 2020
 * @author N.N.
 *
 ***********************************************************************
 *  Übersetzen:	javac Complex.java
 *  Ausführung:	java Complex
 *
 *  Datentypen für komplexe Zahlen.
 *
 *  Sobald eine komplexe Zahl erzeugt wurde,
 *  können ihr Realteil und Imaginärteil nicht verändert werden.
 *  In Java verwendet man dafür das Schlüsselwort "final".
 *
 *  Beispiel der Ausgabe: java Complex
 *  a            = 5.0 + 6.0i
 *  b            = -3.0 + 4.0i
 *  Re(a)        = 5.0
 *  Im(a)        = 6.0
 *  b + a        = 2.0 + 10.0i
 *  a - b        = 8.0 + 2.0i
 *  a * b        = -39.0 + 2.0i
 *  b * a        = -39.0 + 2.0i
 *  a / b        = 0.36 - 1.52i
 *  (a / b) * b  = 5.0 + 6.0i
 *  conj(a)      = 5.0 - 6.0i
 *  |a|          = 7.810249675906654
 *
 **********************************************************************/

public class Complex {
	private final double re;   // Realteil
	private final double im;   // Imaginärteil

	// KONSTRUKTOR: zum Erzeugen einer kompl. Zahl
	public Complex(double real, double imag) {
		???????????????????????
	}

	// return die komplexe Zahl als String
	// in der Form (Bsp): 2.0 + 10.0i
	public String toString() {
		if (im == 0) return re + "";
		if (re == 0) return im + "i";
		if (im <  0) return re + " - " + (-im) + "i";
		return re + " + " + im + "i";
	}

	// return abs
	public double abs()   { 
		return Math.sqrt(????????????????);
	}

	// Addition: Addiere zu diesem Objekt (this) den Parameter b hinzu
	// und gib das Ergebnis zurück.
	// Es wird also ein neues Objekt erstellt, das (this + b) ist.
	public Complex plus(Complex b) {
		double real = this.re + b.re;
		double imag = this.im + b.im;
		return new Complex(real, imag);
	}

	// Subtraktion:
	public Complex minus(Complex b) {
		????????????????
	}

	// Mul
	public Complex times(Complex b) {
		double real = this.re * b.re - this.im * b.im;
		double imag = this.re * b.im + this.im * b.re;
		return new Complex(real, imag);
	}

	// skalar mul
	// (this * alpha)
	public Complex times(double alpha) {
		return new Complex(alpha * this.re, alpha * this.im);
	}

	// konjugiert Komplex
	public Complex conjugate() {  
		return new Complex(?????????????); 
	}

	// gib Realteil bzw. Imaginärteil zurück
	public double re() { 
		return re; 
	}
	public double im() { 
		return im; 
	}

	// return a / other
	// erweitern mit konj.kompl
	public Complex divides(Complex other) {
		???????????
	}
}
~~~

## Aufgabe: test.T_Complex.java

~~~java
package test;

import oop1.Complex;

public class T_Complex{
	public static void main(String[] args) {
		
		Complex a = new Complex(5.0, 6.0);
		Complex b = new Complex(-3.0, 4.0);

		System.out.println("a            = " + a);
		System.out.println("b            = " + b);
		System.out.println("Re(a)        = " + a.re());
		System.out.println("Im(a)        = " + a.im());
		System.out.println("b + a        = " + b.plus(a));
		System.out.println("a - b        = " + a.minus(b));
		System.out.println("a * b        = " + a.times(b));
		System.out.println("b * a        = " + b.times(a));
		System.out.println("a / b        = " + a.divides(b));
		System.out.println("(a / b) * b  = " + a.divides(b).times(b));
		System.out.println("conj(a)      = " + a.conjugate());
		System.out.println("|a|          = " + a.abs());
	}

}

//Quelle: 
//http://introcs.cs.princeton.edu/java/97data/Complex.java.html
/*
output:
a            = 5.0 + 6.0i
b            = -3.0 + 4.0i
Re(a)        = 5.0
Im(a)        = 6.0
b + a        = 2.0 + 10.0i
a - b        = 8.0 + 2.0i
a * b        = -39.0 + 2.0i
b * a        = -39.0 + 2.0i
a / b        = 0.36 - 1.52i
(a / b) * b  = 5.0 + 6.0i
conj(a)      = 5.0 - 6.0i
|a|          = 7.810249675906654

*/
~~~
