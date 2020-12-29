# PROG-functions.md

1. Create project: 03_FUNCTION_01_algo
2. Create package myalgo;
3. Create class MyAlgo in package myalgo
4. Create Test-Programs TXX_Xxxxx.java (see below) to test your functions in MyAlgo.java

~~~ java
package myalgo;

public class MyAlgo{

// ## T01_Array.java
public static void merge(int[] a) {}
public static void display(int[] a) {}
public static int getMax_idx(int[] a) {return 0;}
public static int search_idx(int key, int[] a) {return 0;}
public static void mysort(int[] a) {}
public static boolean hasNeighbour(int[] a) {return false;}
public static boolean hasDoubleValue(int[] a) {return false;}
public static double getStdDeviation(int[] a) {return 0.0;}
public static double getAvg(int[] a) {return 0.0;}

// ## T02_NumberSystem.java
public static int hex2int(String digits) {return 0;}
public static int dec2int(String digits) {return 0;}
public static int dual2int(String digits) {return 0;}

/* -- convert an int-variable into a hex/dual-String --- */
public static String int2hex(int number) {return "todo";}
public static String int2dec(int number) {return "todo";}
public static String int2dual(int number) {return "todo";}

// ## T03_Prime.java
public static void displayPrime(int[] a) {}
public static boolean isPrime(int n) {return false;}

// ## T04_Cipher.java
// see: 02-PROG-cipher
public static String caesar(String txt, int key) {return "todo";} // only characters
public static String skytale(String, int keyRow, int keyCol) {return "todo";}

// ## T05_Strings.java
public static String removeVovel(String s) {return "todo";}
public static String shuffle(String s) {return "todo";}

// ## T06_Morse.java
public static String getMorse(String sText) {return "todo";}
public static void playMorse(String sMorse) {return "todo";}

// ## T06_Utils.java
public static boolean isLeapYear(int year) {return false;}
public static String getDayName(int d, int m, int y) {return "todo";}
}
~~~

## Hints

~~~ java
public static int dec2int(String digits) {
	int number=0;
	for (int i = 0; i < digits.length(); i++) {
		number= number*10 + digits.charAt(i)-'0';
	}
	return number;
}


public static String int2dual(int number) {
/*
11:2= 5		remainder= 1
5:2= 2		remainder= 1
2:2= 1		remainder= 0
1:2= 0		remainder= 1
	
--> 11 (dec) -> 1011 (dual)
*/
	String ret="";
	int remainder;
	
	do{
		remainder= number%2;
		ret+= String.valueOf(remainder);
		number= number/2;
	}while (number !=0);

	// reverse
	StringBuffer b= new StringBuffer(ret);
	b.reverse();
	return String.valueOf(b);
}


/** Generates a tone.
@param hz Base frequency (neglecting harmonic) of the tone in cycles per second
@param msecs The number of milliseconds to play the tone.
@param volume Volume, form 0 (mute) to 100 (max).
@param addHarmonic Whether to add an harmonic, one octave up. 
@see http://www.schulphysik.de/java/physlet/applets/sinus1.html
*/
public static void generateTone(int hz,int msecs, int volume,
		boolean addHarmonic)
				throws javax.sound.sampled.LineUnavailableException {

	float frequency = 44100;
	byte[] buf;

	javax.sound.sampled.AudioFormat af;
	if (addHarmonic) {
		buf = new byte[2];
		af = new javax.sound.sampled.AudioFormat(frequency,8,2,true,false);
	} else {
		buf = new byte[1];
		af = new javax.sound.sampled.AudioFormat(frequency,8,1,true,false);
	}

	javax.sound.sampled.SourceDataLine sdl;
	sdl= javax.sound.sampled.AudioSystem.getSourceDataLine(af);
	//sdl = AudioSystem.getSourceDataLine(af);
	sdl.open(af);
	sdl.start();
	for(int i=0; i<msecs*frequency/1000; i++){
		double angle = i/(frequency/hz)*2.0*Math.PI;
		buf[0]=(byte)(Math.sin(angle)*volume);

		if(addHarmonic) {
			double angle2 = (i)/(frequency/hz)*2.0*Math.PI;
			buf[1]=(byte)(Math.sin(2*angle2)*volume*0.6);
			sdl.write(buf,0,2);
		} else {
			sdl.write(buf,0,1);
		}
	}
	sdl.drain();
	sdl.stop();
	sdl.close();
}

/*    public static void main(String[] args) throws LineUnavailableException {
	//				   ton(A)  Dauer(1sec)  lautstaerke		harmonisch
	MyAlgos.generateTone(440,    800,		100,			true);
	MyAlgos.generateTone(440,    400,		100,			true);
	MyAlgos.generateTone(440,    400,		100,			true);
}
	*/
~~~
