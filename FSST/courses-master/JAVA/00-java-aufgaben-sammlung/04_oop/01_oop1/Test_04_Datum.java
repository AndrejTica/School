package test;

public class Test_04_Datum {

	public static void main(String[] args) {
		Datum geburtstag, zeugnistag;
		Datum heute;
		boolean bSchaltJahr;

// ----------------------------------------------
		geburtstag= new Datum(1,1,2013);

// ----------------------------------------------
		// Ausgabe des Datums MUSS in eckigen Klammern erfolgen
		// [1.1.2013]
		System.out.println("Geburtstag ist am " + geburtstag.toString());

		
// ----------------------------------------------
		heute= new Datum();

// ----------------------------------------------
		bSchaltJahr= heute.istSchaltjahr();
		
		if (bSchaltjahr == true)
			System.out.println("Heuer ist ein Schaltjahr");
		else
			System.out.println("Heuer ist kein Schaltjahr");

// ----------------------------------------------
		zeugnistag= new Datum("7:7:2013");
		System.out.println("Zeugnistag ist am " + zeugnistag.toString());
	
	}
}

//	Hinweis: Schaltjahr
//		if (jahr%4 == 0 && jahr%100 != 0 || jahr%400 == 0)
//				return 1;	//jahr ist ein schaltjahr
//		else
//				return 0;


// Hinweis: aktuelles Datum ermittlen
//	java.util.Calendar today= java.util.Calendar.getInstance();
//	int tag= today.get(java.util.Calendar.DATE);
//	int monat= today.get(java.util.Calendar.MONTH);
//	int jahr= today.get(java.util.Calendar.YEAR);

// Hinweis: Text zerlegen
//	String[] teile= "ABC:DEF:GHI".split(":");
//	teile[0] ... enthält dann ABC
//	teile[1] ... enthält dann DEF
//	teile[2] ... enthält dann GHI




