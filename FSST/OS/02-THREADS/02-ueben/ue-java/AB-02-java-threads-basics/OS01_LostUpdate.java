/*
javac OS01_LostUpdate.java
java OS01_LostUpdate
*/

class LostUpdate extends 
//
// ENTER CODE HERE
//


public class OS01_LostUpdate {
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
