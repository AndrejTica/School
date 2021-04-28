/*
javac OS_04_LostUpdate.java
java OS_04_LostUpdate
*/

//class LostUpdate extends 
//
// ENTER CODE HERE
//
/*
class LostUpdate extends Thread{
	private String s;
	
	// gemeinsamer Speicher: Hier eine static Variable
	private static int count=0;
	
	public LostUpdate(String s){
		this.s=s;
	}

	public void run(){	
		for (int i = 1; i <=5; i++) {
				// READ
				int temp;
				temp= count;
				System.out.println(s + "READ: " + temp);
				try {Thread.sleep(50);} catch (InterruptedException e) {}
				
				// INCR
				temp= temp + 1;
				System.out.println(s + "INCR: " + temp);
				try {Thread.sleep(20);} catch (InterruptedException e) {}
				
				//WRITE
				count= temp;
				System.out.println(s + "WRITTEN: " + temp);
				try {Thread.sleep(30);} catch (InterruptedException e) {}
		}
	}
}

public class OS_04_LostUpdate {
    public static void main(String[] args) {
        System.out.println("DEMO: Lost Update .......");
        System.out.println(
                "2 Threads inkrementieren die Variable count jeweils 5 mal, d.h. count sollte den Wert 10 haben.\n");

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
/*
output:
DEMO: Lost Update .......
2 Threads inkrementieren die Variable count jeweils 5 mal, d.h. count sollte den Wert 10 haben.
                                THREAD2: READ: 1
THREAD1: READ: 1
                                THREAD2: INCR: 2
THREAD1: INCR: 2
                                THREAD2: WRITTEN: 2
THREAD1: WRITTEN: 2
                                THREAD2: READ: 2
THREAD1: READ: 2
                                THREAD2: INCR: 3
THREAD1: INCR: 3
THREAD1: WRITTEN: 3
                                THREAD2: WRITTEN: 3
                                THREAD2: READ: 3
THREAD1: READ: 3
                                THREAD2: INCR: 4
THREAD1: INCR: 4
THREAD1: WRITTEN: 4
                                THREAD2: WRITTEN: 4
THREAD1: READ: 4
                                THREAD2: READ: 4
THREAD1: INCR: 5
                                THREAD2: INCR: 5
THREAD1: WRITTEN: 5
                                THREAD2: WRITTEN: 5
THREAD1: READ: 5
                                THREAD2: READ: 5
                                THREAD2: INCR: 6
THREAD1: INCR: 6
THREAD1: WRITTEN: 6
                                THREAD2: WRITTEN: 6
*/
