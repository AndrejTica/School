//UMLAUFPUFFER///////////////////////////////////////////////////////// 
class Umlaufpuffer {          // gemeinsames Objekt ("Monitor") 
  int puffer[];               // der eigentliche Puffer 
  int fuellstand=0;           // Anzahl der belegten Plätze 
  int ein = 0;                // Schreibindex 
  int aus = 0;                // Leseindex 

  Umlaufpuffer(int laenge) {  // Konstruktor 
    puffer = new int[laenge]; // Puffer anlegen 
  } 

  //--eintragen----------------- Methode zum Ablegen einer Nachricht 
????????????????
  void eintragen(int wert[]) throws Exception {        
 
    while (fuellstand + wert.length > puffer.length) 
                ???????????????  // 
    for (int i=0; i<wert.length; i++) { 
      puffer[ein] = wert[i];  // Nachricht kopieren 
      ein = (ein+1) % puffer.length; 
      fuellstand++; 
    } 
    ???????????????           // 
  } 

  //--entnehmen----------------- Methode zum Auslesen einer Nachricht 
  ?????????????????????
  void entnehmen(int wert[]) throws Exception { 
    while (fuellstand < wert.length) 
                 ????????????????????? // 
    for (int i=0; i<wert.length; i++) { 
      wert[i] = puffer[aus];// Nachricht kopieren 
      aus = (aus+1) % puffer.length; 
      fuellstand--; 
    } 
     ????????????????????????? // 
  } 
} 


// ERZEUGER /////////////////////////////////////////////////////// 
class Erzeuger { // der "Erzeuger"-Thread 
  Umlaufpuffer puffer;        // gemeinsamer Puffer 
  Erzeuger(Umlaufpuffer p) {  // Konstruktor 
    puffer = p; 
  } 
    public void run() {         // eigentlicher Erzeuger 
    int i=0; 
    while (!isInterrupted()) { 
      //...  Nachricht erzeugen (hier: 3 Zahlen) 
      int nachricht[] = {i,i+1,i+2}; 
      try { 
        puffer.eintragen(nachricht); 
        System.out.println 
          ("produced: "+ 
           nachricht[0]+' '+ 
           nachricht[1]+' '+ 
           nachricht[2]); 
        i += 3; 
        //... 
      } 
      catch(Exception e) { 
    	  interrupt();
        System.out.println(e); 
      } 
    } 
  } 
} 

//VERBRAUCHER///////////////////////////////////////////////////// 
class Verbraucher { // der "Verbraucher"-Thread 
  Umlaufpuffer puffer;        // gemeinsamer Puffer 
  Verbraucher(Umlaufpuffer p) { 
    puffer = p; 
  } 
  public void run() {         // eigentlicher Verbraucher 
    while (!isInterrupted()) { 
      //... 
      int nachricht[] = new int[5]; 
      try { 
        puffer.entnehmen(nachricht); 
        System.out.println 
          ("\t\t\tconsumed: "+ 
           nachricht[0]+' '+ 
           nachricht[1]+' '+ 
           nachricht[2]+' '+ 
           nachricht[3]+' '+ 
           nachricht[4]); 
        //... nachricht verarbeiten 
      } 
      catch(Exception e) { 
    	  interrupt();
    	  System.out.println(e); 
      } 
    } 
  } 
} 

//BS05PRODUCERCONSUMER////////////////////////////////// 
public class BS05ProducerConsumer{ 
  public static void main(String args[]) { 
    Umlaufpuffer p= new Umlaufpuffer(10);
    Erzeuger     e= new Erzeuger(p);
    Verbraucher  v= new Verbraucher(p);
 
    e.start(); 
    v.start();
    
    try {
		Thread.sleep(50);
	    e.interrupt();
	    v.interrupt();
    } catch (InterruptedException e1) {
		e1.printStackTrace();
	}
  } 
}
