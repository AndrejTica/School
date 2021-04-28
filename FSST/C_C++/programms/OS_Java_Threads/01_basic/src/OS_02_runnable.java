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
    Thread thread = new Thread(runnable);

    System.out.println("MAIN-Thread: starts DemoRunnable");

    thread.start();
    
    System.out.println("MAIN-Thread: waiting for DemoRunnable (join)");
    
    thread.join();

    System.out.println("MAIN-Thread: finished");
  }
}
