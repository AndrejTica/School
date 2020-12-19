import java.util.Observable;
import java.util.Observer;

public class Dieb extends Observable {
	private String name;
	private String wo;
 
	public Dieb(String name) {
		super();
		this.name= name;
	}
 
	
	public void aufGehts(String wo) {
	   this.wo = wo;
	   
	   // Markierung, dass sich was geaendert hat
	   super.setChanged(); 
	   
	   // ruft fuer alle Beobachter die update-Methode auf
	   super.notifyObservers(); 
	}
 
	
	public String toString() {
	   return name + " ... ich bin gerade hier: " + wo + "\n";
	}
}
