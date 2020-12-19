public class DemoObserver {
	
	public static void main(String[] args) {
		// OBSERVER
		Polizist[] polizisten = {
				new Polizist("WACHMANN ADAM"), 
				new Polizist("WACHFRAU EVA")
		};
	   
		//OBSERVABLE
		Dieb dieb = new Dieb("Elster Karl");

		for (int i=0; i < polizisten.length; i++) {
			dieb.addObserver(polizisten[i]);
		}
   
		System.out.println(" ---------------------------------- ");
		dieb.aufGehts("Schlossalle 12..tolle Uhren");
		System.out.println(" ---------------------------------- ");
		dieb.aufGehts("Einkaufsstrasse..schwere Glunker");
		System.out.println(" ---------------------------------- ");
		dieb.aufGehts("Gefaengnisstrasse 6..bin erwischt worden");
		System.out.println(" ---------------------------------- ");
		dieb.aufGehts("SCHULE..bin nochmal erwischt worden");
		System.out.println(" ---------------------------------- ");
		
	}
}
