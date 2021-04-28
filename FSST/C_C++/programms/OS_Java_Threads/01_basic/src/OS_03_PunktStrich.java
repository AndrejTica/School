/**
 * Punkte und Striche werden abwechselnd gezeigt.
 * Der Scheduler ist für das Wechseln zuständig.
 */ 

/*
javac OS_03_PunktStrich.java
java OS_03_PunktStrich
*/

class PunktStrich extends Thread {
	private String s;
	
	public PunktStrich (String s) {
		this.s = s;
	}
	
	public void run() {
		while(true)
			System.out.print(s);
	}
}

// thread gibt in einer Schleife seinen String aus
// Verwende: while(!isInterrupted()) ...


public class OS_03_PunktStrich {
	public static void main(String[] args) throws InterruptedException{
	
		PunktStrich punkt = new PunktStrich("..");
		PunktStrich strich = new PunktStrich("||");
		
		punkt.start();   //!!!!!!!!!!!!!!!
		strich.start();  //!!!!!!!!!!!!!!!
		

        Thread.sleep(5000);
        punkt.interrupt();


        Thread.sleep(5000);
        strich.interrupt();
        
	}
}

