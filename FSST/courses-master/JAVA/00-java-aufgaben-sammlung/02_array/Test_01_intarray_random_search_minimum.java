package main;

public class Test_01_intarray_random_search_minimum {

	public static void main(String[] args) {
		java.util.Random rand= new java.util.Random();
		java.util.Scanner cin= new java.util.Scanner(System.in);
		
		int[] arr= new int[10];
		int suche;
		int suche_index;
		int min_index;
		
		// ------------------------------------------------------------
		System.out.println();
		System.out.println("=== Zufallszahlen ins Array schreiben ===");
		
		// ENTER CODE
		
		// Ausgabe
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i]+ ",");
		}
		System.out.println();
		
		
		// ------------------------------------------------------------
		System.out.println();
		System.out.println("=== Suche im Array ===");
		System.out.println("Nach welcher Zahl wollen Sie suchen? ");
		suche= cin.nextInt();
		
		suche_index=-1;

		// ENTER CODE
		
		if (suche_index==-1) {
			System.out.println(suche + " nicht gefunden.");
		}else {
			System.out.println(suche + " an der Position " + suche_index + " gefunden.");			
		}
		
		
		// ------------------------------------------------------------
		System.out.println();
		System.out.println("=== MinimumSuche im Array ===");
		min_index=0;

		// ENTER CODE

		
		System.out.println("Der kleinste Wert ist an der Position " + min_index);
		System.out.println("Der kleinste Wert ist " + arr[min_index]);
				
	}
}
