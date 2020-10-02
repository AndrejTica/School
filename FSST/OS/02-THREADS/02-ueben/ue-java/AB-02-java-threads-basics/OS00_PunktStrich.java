/**
 * Punkte und Striche werden abwechselnd gezeigt.
 * Der Scheduler ist für das Wechseln zuständig.
 */ 

/*
javac OS00_PunktStrich.java
java OS00_PunktStrich
*/

class PunktStrich
//
// ENTER CODE HERE
//


public class OS00_PunktStrich {
	public static void main(String[] args) {
	
		PunktStrich punkt= new PunktStrich(".");
		PunktStrich strich= new PunktStrich("-");
		
		punkt.start();   //!!!!!!!!!!!!!!!
		strich.start();  //!!!!!!!!!!!!!!!
		
		// läuft bis der User Ctrl-C eingibt
	}
}

