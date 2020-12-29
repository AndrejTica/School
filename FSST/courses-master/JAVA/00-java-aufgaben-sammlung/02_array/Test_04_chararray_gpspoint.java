package main;

public class Test_04_chararray_gpspoint {

	public static void main(String[] args) {
		/**
		 * Gegeben sei folg. Text
		 * "GPSPoint(12.1234 40.12345)"
		 * 
		 * 1. Extrahieren Sie aus dem String die beiden
		 * double Werte latitude und longitude
		 * 
		 * 2. Addieren Sie diese beiden Werte und
		 * 
		 * 3. Geben Sie diese Summe dann aus.
		 * 
		 * Beachten Sie, dass die im Beispiel gegebenen
		 * Werte beliebige Werte sein können.
		 * D.h. Ihr Programm muss auch richtig arbeiten,
		 * wenn der String z.B. folg. Text enthält:
		 * "GPSPoint(10.88 20.11)"
		 * 
		 * Bsp:
		 * bei "GPSPoint(12.1234 40.12345)" lautet die Ausgabe:
		 * Summe= 52.24685
		 * Bsp:
		 * bei "GPSPoint(10.88 20.11)" lautet die Ausgabe:
		 * Summe= 30.99
		 * 
		 */

		String s= "GPSPoint(12.1234 45.12345)";
		String help="";
		
		int index_start=0;
		int index_end=0;
		double longitude=0.0;
		double latitude=0.0;
		double summe=0.0;
		
		// 1. Suche den Index nach dem Zeichen '('
		//    verwende index_start
		
		// ENTER CODE
		
		// 2. Suche den Index nach dem Zeichen ' '
		//	    verwende index_end
		
		// ENTER CODE

		// 3. Speicher den TeilString zwischen
		//    index_start und index_end
		//    in eine Hilfsvariable help
		
		// ENTER CODE
		
		// 4. Wandle die Hilfsvariable help
		//    in eine Double Variable um.
		//    Tipp: Double.parseDouble()
		
		// usw.

		// ENTER CODE
		
		
		summe= latitude + longitude;
		
		System.out.println("Summe= " + summe);
	}

}
