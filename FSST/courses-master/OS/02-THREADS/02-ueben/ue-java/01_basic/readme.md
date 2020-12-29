# Thread

- A multithreaded program contains two or more parts that can run **concurrently**. 
- Each part is called **thread**, and **each thread defines a separate path of execution.**

We will learn how to:

- use **class Thread**
- use **Interface Runnable**

---

## class Thread

- `public static void main()` ... starts the so-called **Main-Thread**.

- `extends Thread` ... a subclass of class Thread overrides `public void run()`

~~~ java
// OS_01_thread.java

class DemoThread extends Thread{

    @Override
    public void run(){

        for (int i=0; i<100; i++)
            System.out.println("\t\t\t\tDemoThread: ... running");
    }
}

public class OS_01_thread {

  public static void main(String[] args) throws InterruptedException {

    DemoThread thread = new DemoThread();

    System.out.println("MAIN-Thread: starts DemoThread");

    thread.start();
    
    System.out.println("MAIN-Thread: waiting for DemoThread (join)");
    
    thread.join();

    System.out.println("MAIN-Thread: finished");
  }
}
~~~

---

## Interface Runnable

- used, when your class should inherit from a class other than class Thread (example: ... extends JFrame)

~~~ java
// OS_02_runnable.java

class DemoRunnable implements Runnable{

    @Override
    public void run(){

        for (int i=0; i<100; i++)
            System.out.println("\t\t\t\tDemoRunnable: ... running");
    }
}

public class OS_02_runnable {

  public static void main(String[] args) throws InterruptedException {

    DemoRunnable runnable = new DemoRunnable();
    Thread thread= new Thread(runnable);

    System.out.println("MAIN-Thread: starts DemoRunnable");

    thread.start();
    
    System.out.println("MAIN-Thread: waiting for DemoRunnable (join)");
    
    thread.join();

    System.out.println("MAIN-Thread: finished");
  }
}
~~~

---

## Scheduler works

- Im folg. Beispiel sieht man, dass im Hintergrund der Scheduler des Betriebssystems den threads CPU-Zeiten zuteilt.

- Die threads befinden sich in der sogenannten **READY-queue** und warten darauf, dass sie vom Scheduler eine sogenannte **Zeit-Scheibe** zugeordnet bekommen. (time-sharing-scheduling)


~~~java
/**
 * Punkte und Striche werden abwechselnd gezeigt.
 * Der Scheduler ist für das Wechseln zuständig.
 */ 

/*
javac OS_03_PunktStrich.java
java OS_03_PunktStrich
*/

class PunktStrich 
//
// ENTER CODE HERE
// thread gibt in einer Schleife seinen String aus
// Verwende: while(!isInterrupted()) ...


public class OS_03_PunktStrich {
	public static void main(String[] args) throws InterruptedException{
	
		PunktStrich punkt= new PunktStrich("..");
		PunktStrich strich= new PunktStrich("||");
		
		punkt.start();   //!!!!!!!!!!!!!!!
		strich.start();  //!!!!!!!!!!!!!!!
		

    Thread.sleep(5000);
    punkt.interrupt();


    Thread.sleep(5000);
    strich.interrupt();        
	}
}

~~~
