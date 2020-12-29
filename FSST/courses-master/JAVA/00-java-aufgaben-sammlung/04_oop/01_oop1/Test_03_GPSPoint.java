package test;


/** Tipp:
 * 
 * String s="hallo welt";
 * int position= s.indexOf(" "); // liefert 5
 * 
 * String t= s.substring(0, position); // liefert hallo
 * 
 */

public class Test_03_GPSPoint {

	public static void main(String[] args) {
		GPSPoint a= new GPSPoint("Point(13.12345 48.07)");
		GPSPoint b= new GPSPoint(a);
		
		String lat= b.getLat();
		
		b.addLat(2.0);
		
		System.out.println ( "b= " + b.toString());

	// The output should be:
	// b= Point(13.077777 50.07)

	}
}
