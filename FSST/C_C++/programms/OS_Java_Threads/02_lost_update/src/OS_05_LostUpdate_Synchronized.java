/*
javac OS_05_LostUpdate_Synchronized.java
java  OS_05_LostUpdate_Synchronized
*/

class LostUpdate extends Thread {
    private String s;

    // gemeinsamer Speicher: Hier eine static Variable
    private static int count = 0;

    // Sync-Objekt !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    private static Object syncLock= new Object();



    public LostUpdate(String s) {
        this.s = s;
    }
    

    public void run() {
        for (int i = 1; i <= 5; i++) {
            // begin critical section !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

            synchronized (syncLock){

            	// critical section
            	// READ
                int temp;
                temp = count;
                System.out.println(s + "READ: " + temp);
                try {
                    Thread.sleep(50);
                } catch (InterruptedException e) {
                }

                // INCR
                temp = temp + 1;
                System.out.println(s + "INCR: " + temp);
                try {
                    Thread.sleep(20);
                } catch (InterruptedException e) {
                }

                //WRITE
                count = temp;
                System.out.println(s + "WRITTEN: " + temp);
                try {
                    Thread.sleep(30);
                } catch (InterruptedException e) {
                }
                // END critical section		!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

            }
            
        } // for
    }
}

public class OS_05_LostUpdate_Synchronized {
	public static void main(String[] args) {
		LostUpdate t1= new LostUpdate("THREAD1: ");
		LostUpdate t2= new LostUpdate("\t\t\t\tTHREAD2: ");

		t1.start();
		t2.start();

		try {
			t1.join();
			t2.join();
		} catch (InterruptedException e) {
		}
	}
}

/* output
java OS_05_LostUpdate_Synchronized      
THREAD1: READ: 0
THREAD1: INCR: 1
THREAD1: WRITTEN: 1
THREAD1: READ: 1
THREAD1: INCR: 2
THREAD1: WRITTEN: 2
                                THREAD2: READ: 2
                                THREAD2: INCR: 3
                                THREAD2: WRITTEN: 3
                                THREAD2: READ: 3
                                THREAD2: INCR: 4
                                THREAD2: WRITTEN: 4
                                THREAD2: READ: 4
                                THREAD2: INCR: 5
                                THREAD2: WRITTEN: 5
                                THREAD2: READ: 5
                                THREAD2: INCR: 6
                                THREAD2: WRITTEN: 6
THREAD1: READ: 6
THREAD1: INCR: 7
THREAD1: WRITTEN: 7
THREAD1: READ: 7
THREAD1: INCR: 8
THREAD1: WRITTEN: 8
THREAD1: READ: 8
THREAD1: INCR: 9
THREAD1: WRITTEN: 9
                                THREAD2: READ: 9
                                THREAD2: INCR: 10
                                THREAD2: WRITTEN: 10
*/
