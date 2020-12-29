package test;

import java.io.IOException;
import java.util.*;

public class Test_02_shs {

	public static void main(String[] args) throws InterruptedException, IOException {
		Scanner cin= new Scanner(System.in);
		String sinput;
		int input;

		SchuelerListe schuelerList= new Schuelerliste("Schüler helfen Schülern");
		// sl.add("maxi", "2ahel");
		// sl.at("maxi").addSucheFach("mathematik");
		// sl.at("maxi").addSucheFach("get");
		// sl.at("maxi").addBieteFach("englisch");
		// sl.at("maxi").addBieteFach("fsst");
		// s1.listSucheFach("mathematik"); //name,klasse
		// s1.listBieteFach("mathematik"); //name,klasse
		// sl.at("maxi").toString()
		
		

		boolean ende= false;

		while (ende==false) {
			for (int i = 0; i < 50; ++i) System.out.println();
			
			System.out.println();
			System.out.println("=====================================");
			System.out.println("=== SHS - Schüler helfen Schülern ===");
			System.out.println("=====================================");
			System.out.println();
			
			System.out.println("1. erfassen Schüler (testdaten)");
			System.out.println("2. erfassen Schüler (einzeln)");
			System.out.println("3. erfassen Schüler bietet ein Fach an");
			System.out.println("4. erfassen Schüler sucht Hilfe für ein Fach");
			System.out.println("5. alle Schüler listen, die ein bestimmtes Fach suchen");
			System.out.println("6. alle Schüler listen, die ein bestimmtes Fach anbieten");
			System.out.println("7. Liste alles");
			System.out.println("-- -----------");

			System.out.println("9. ende");
			System.out.println();
			
			input= cin.nextInt();

			switch(input){

			case 1:
				System.out.println("1. erfassen Schüler (testdaten)");
				System.out.println();
				
				schuelerList.add("maxi", "2ahel");
				schuelerList.add("fabian", "2bhel");
				schuelerList.add("florian", "2chel");
				schuelerList.add("maria", "2ahel");
				schuelerList.add("julia", "2bhel");
				schuelerList.add("anna", "2chel");
				
				break;
			case 2:
				System.out.println("2. erfassen Schüler (einzeln)");
				System.out.println();
				
				System.out.println("name: ");
				String name= cin.nextLine();
				String klasse= cin.nextLine();
				
				schuelerList.add(name,klasse);
				break;
			case 3:
				System.out.println("3. erfassen Schüler bietet ein Fach an");
				System.out.println();
				
				System.out.println("name: ");
				name= cin.nextLine();
				System.out.println("fach (mat,d,e,fsst,dic,get,...): ");
				String fach= cin.nextLine();
				
				schuelerList.at(name).addBieteFach(fach);
				
				break;
			case 4:
				System.out.println("4. erfassen Schüler sucht Hilfe für ein Fach");
				System.out.println();
				
				System.out.println("name: ");
				name= cin.nextLine();
				System.out.println("fach (mat,d,e,fsst,dic,get,...): ");
				fach= cin.nextLine();
				
				schuelerList.at(name).addHilfeFach(fach);
				
				break;
			case 5:
				System.out.println("5. alle Schüler listen, die ein bestimmtes Fach suchen");
				System.out.println();
				
				System.out.println("fach (mat,d,e,fsst,dic,get,...): ");
				fach= cin.nextLine();
				
				schuelerList.listSucheFach(fach);
				
				break;
			case 6:
				System.out.println("6. alle Schüler listen, die ein bestimmtes Fach anbieten");
				System.out.println();
				
				System.out.println("fach (mat,d,e,fsst,dic,get,...): ");
				fach= cin.nextLine();
				
				schuelerList.listBieteFach(fach);
				
				break;
			case 7:
				System.out.println("7. Liste alles");
				
				schuelerList.toString();
				
				break;
				

			case 9:
				ende= true;
				System.out.println(" === bye ===");
			}
		}
	}
}
