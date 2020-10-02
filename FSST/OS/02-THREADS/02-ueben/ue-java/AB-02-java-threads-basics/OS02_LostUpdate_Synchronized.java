/*
javac OS02_LostUpdate_Synchronized.java
java  OS02_LostUpdate_Synchronized
*/
class LostUpdate extends //
// ENTER CODE HERE
//

public class OS02_LostUpdate_Synchronized {
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
