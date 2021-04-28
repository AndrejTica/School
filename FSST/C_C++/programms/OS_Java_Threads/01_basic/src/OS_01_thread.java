// OS_01_thread.java

class DemoThread extends Thread{

    @Override
    public void run(){

        for (int i=0; i<100; i++)
            System.out.println("\t\t\t\tDemoThread: ... running");
    }
}

public class OS_01_thread {

  public static void main(String[] args) throws InterruptedException{

    DemoThread thread = new DemoThread();

    System.out.println("MAIN-Thread: starts DemoThread");

    thread.start();
    
    System.out.println("MAIN-Thread: waiting for DemoThread (join)");
    
    thread.join();

    System.out.println("MAIN-Thread: finished");
  }
}
