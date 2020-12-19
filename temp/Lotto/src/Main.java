import java.awt.EventQueue;


public class Main {
	public static void main(String[] args) {
		
		// 1. Das Model erzeugen
		Model model= new Model();
		
		// 2. Die View
		EineZiehungView eineZiehungView = new EineZiehungView();
		eineZiehungView.setVisible(true);
		AlleZiehungenView alleZiehungenView = new AlleZiehungenView();
		alleZiehungenView.setVisible(true);

		// 3. Der View das Model mitteilen
		eineZiehungView.setModel(model);
		alleZiehungenView.setModel(model);

		// 4. Die View beim Model als Observer registrieren
		model.addObserver(eineZiehungView);
		model.addObserver(alleZiehungenView);

		// -----------------------------------------------------------------------------------
		// -- AUFGABE: Eine weitere View einfügen
		// -----------------------------------------------------------------------------------
//		AlleZiehungenView alleZiehungenView= new AlleZiehungenView();
		
		// ....
		
		}
}
