/**
* Worker der "Pipe" zur Primzahlenbestimmung 
* @author Roland Rössler 
* Änderungen: HofA
*/ 

class Worker extends Thread { 
    /** die Primzahl, für die der Worker zuständig ist */ 
    private int myPrime; 

    /** der nächste Worker in der "Pipe" */ 
    private Worker next=null; 

    /** der Sende-/Empfangs-Puffer. Hier ein einf. Int Wert */ 
    private int buffer=0; 


    /** Erzeugung eines Workers und Zuordnung einer Primzahl 
      * @param prime die Primzahl, für die der Worker zuständig ist 
      */ 
    public Worker(int prime) { 
        myPrime=prime; 
        next=null; /** nullsetzen*/ 
        System.out.println(this+" Prime: "+myPrime); 
    } 

    /** "Arbeitsroutine" des Workers. 
      * Es werden ungerade Zahlen empfangen, wenn diese 
      * Vielfache der "eigenen" Primzahl sind, dann werden 
      * sie "verschluckt", andernfalls an den nächsten 
      * Worker weitergereicht 
      */ 
    public void run() { 
       int i = this.??????();     // Zahl empfangen 
       while (i>0) { 			//arbeite, solange i positiv ist 
         if (i%myPrime != 0) {     // wenn i nicht Vielfaches von myPrime 
						// erzeuge neuen Nachfolger-Thread oder 
						// wenn er bereits existiert sende ihm 
						// die Variable i 
  
            if (next==null)        
                                         
              ?????? 
            else                         
              ??????              
         } 

         i = ??????;                 // nächste Zahl holen 
       } 
       if (next!=null) ??????;   // Abbruchkennung weiterreichen 
    } 

    /** Senden einer Zahl an den Worker. <p>"send" wird von einem 
      * anderem Thread aufgerufen. 
      * @param i zu sendende Zahl 
      */ 
    ?????? send(int i) { 
      try { 
        ?????? (buffer>0) ??????;        // warten bis Puffer frei 
        buffer = i;                     // Zahl in Puffer eintragen 
        ??????;                       // Empfänger benachrichtigen 
      } 
      catch (InterruptedException e) {} 
    } 


    /** Empfangen einer Zahl. 
      * "receive" wird vom aktuellen Worker aufgerufen. 
      * @return empfangene Zahl 
      */ 
    ?????? receive() { 
      int result=0; 
      try { 
        ?????? ((result=buffer)==0)      // warten bis Zahl angekommen 
          ??????; 
        buffer=0;                       // Puffer freigeben 
        ??????;                       // Sender benachrichtigen 
      } 
      catch (InterruptedException e) {} 
      return result; 
    } 
}

public class BS08Eratosthenes{
/** MAIN:Zahlengenerator.
* Startet Worker für die Primzahl 3 u. 
* übergibt ihm alle ungeraden Zahlen ab 5 
*/ 
	public static void main (String args[]) { 
		Worker first = ??????;     // ersten Worker für Primzahl 3 
		??????;                    // starten 

		int i=5;                          // nächste ungerade Zahl 
		while (i<10000) { 
			??????;                  // ungerade Zahl an Worker senden 
			i+=2; 
		} 

		??????(-1);                   // Abschlusskennung senden 
		System.out.println("finished"); 
	} 
}

