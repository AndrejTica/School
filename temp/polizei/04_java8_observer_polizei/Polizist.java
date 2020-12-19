import java.util.Observable;
import java.util.Observer;

public class Polizist implements Observer {
	private String name;
	
	public Polizist(String name) {
	   this.name= name;
	}
 	
	public void update(Observable o, Object arg) {
		 Dieb dieb= (Dieb) o;
		 
		 System.out.println("POLIZIST: " + name);
		 System.out.print("... meldet folg. Beobachtung: " );
		 System.out.println(dieb.toString());
	}
}
