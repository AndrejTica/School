## OOP2: Assoziation/Aggregation von Klassen

- has A Beziehungen zwischen Klassen

---

## Schoolclass has Students

1. Create project: 04-JAVA-OOP2-schoolclass
2. Create package: oop2 and test
3. Create class: Schoolclasss, Student in package oop2
4. Create Test-Programs T_SchoolClass.java (see below) to test your classes in oop2

---

## Aufgabe: T_SchoolClass.java

~~~java
package test;

import oop1.*;

public class T_SchoolClass{
	public static void main(String[] args) {
		
		Student maxi= new Student("Max Mustermann", 70.0);
		Student moritz= new Student("Moritz Mustermann", 60.0);
		
		SchoolClass the2B= new SchoolClass("2B");
		the2B.add(maxi);
		the2B.add(moritz);
		
		System.out.println(the2B.toString());
		
		Student veryHeavy= the2B.getHeaviest();
		System.out.println("The heaviest student is " + veryHeavy.toString());
	}
}
/*
The output should be:
SCHOOLCLASS: 2B
 ... [Max Mustermann,70.0]
 ... [Moritz Mustermann,60.0]

The most heavily student is [Max Mustermann,70.0]
*/
~~~

---

## HINT: Vector: Objekte in Containern speichern

Wenn man viele Objekte zu verwalten hat 
(wie z. B.: Die Klasse SchoolClass, ...), weiß man oft nicht wie viele Objekte 
(z.B. Student) tatsächlich zur Laufzeit des Programms gespeichert werden sollen.
Arrays haben den Nachteil, dass man bereits zur Übersetzungszeit (=statisch) 
die maximale Anzahl der Arrayelemente angeben muss. 
Hier hilft uns die Klasse Vector aus java.util. 
Sie kann zur Laufzeit beliebig viele Objekte speichern. 
Und man kann mit Vectoren gleich arbeiten wie mit den bekannten Arrays.

Hier nun ein einfaches Beispiel: (www.javabuch.de)

~~~ java
import java.util.*;

public class DemoVector
{
  public static void main(String[] args)
  {
    Vector<String> v = new Vector<String>();

    v.addElement("eins");
    v.addElement("drei");
    v.insertElementAt("zwei",1);

 
    v.remove("eins");
    v.insertElementAt("1",0);

   // Eine bekannte Form der for-Schleife für Collection-Klassen
   for (int i=0; i < v.size(); i++){
      System.out.println(v.elementAt(i));
   }

   // Eine neue Art der for-Schleife für Collection-Klassen
   for (String s : v){
      System.out.println(s);
   }
   
}
~~~
