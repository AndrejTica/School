package test;

public class Test_01_Mailbox {

	public static void main(String[] args) {
		
		Mail mail1= new Mail("From:Badman", "To:Friendman");
		mail1.addSubject("Ein Bombenangebot");
		String text= "Dies ist ein tolles Angebot\n"
				+ "BG Dein Badman";
		mail1.addText(text);
		
		Mail mail2= new Mail("From:Goodman", "To:Friendman");
		mail1.addSubject("Ein echt cooles Angebot");
		text= "Dies ist ein cooles Angebot\n"
				+ "BG Dein Goodman";
		mail1.addText(text);
		
		// ---
		Mailbox mb= new Mailbox("Friendman");
		mb.addMail(mail1);
		mb.addMail(mail2);
		
		// ---		
		System.out.println(mb.toString());
		
/*	Folgende Ausgabe:
	
=== MAILBOX: Friendman ===
From:Badman
To:Friendman
Subject:Ein Bombenangebot
Dies ist ein tolles Angebot
BG Dein Badman

From:Goodman
To:Friendman
Subject:Ein echt cooles Angebot
Dies ist ein cooles Angebot
BG Dein Goodman			
*/
		
		// ---
		Mailbox spamfreeMail= mb.spamFilter("bombe"); // gross od. kleine, enthält
		System.out.println(spamfreeMail.toString());
		
/*	Folgende Ausgabe:
	
=== MAILBOX: Friendman ===
From:Goodman
To:Friendman
Subject:Ein echt cooles Angebot
Dies ist ein cooles Angebot
BG Dein Goodman			
*/
		
		// ---
		Mail shortestSubjectMail= mb.getShortestSubjectMail();
		
		System.out.println(shortestSubjectMail.toString());

/*	Folgende Ausgabe:
From:Badman
To:Friendman
Subject:Ein Bombenangebot
Dies ist ein tolles Angebot
BG Dein Badman
*/
	}
}


/*
HINT: Vector: Objekte in Containern speichern
Wenn man viele Objekte zu verwalten hat 
(wie z. B.: Die Klasse SchoolClass, ...), weiß man oft nicht wie viele Objekte 
(z.B. Student) tatsächlich zur Laufzeit des Programms gespeichert werden sollen.
Arrays haben den Nachteil, dass man bereits zur Übersetzungszeit (=statisch) 
die maximale Anzahl der Arrayelemente angeben muss. 
Hier hilft uns die Klasse Vector aus java.util. 
Sie kann zur Laufzeit beliebig viele Objekte speichern. 
Und man kann mit Vectoren gleich arbeiten wie mit den bekannten Arrays.

Hier nun ein einfaches Beispiel: (www.javabuch.de)

* DemoVector.java

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
*/