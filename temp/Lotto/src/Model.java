// Das Model wird von Views 'beobachtet'

import java.util.Observable;
import java.util.Random;

public class Model extends Observable {
	private int[] zahlen;
	
	public Model(){
		this.zahlen= new int[6];
	}
	
	public void doZiehung(){
		Random zufall= new Random();

		for(int i=0; i <zahlen.length; i++){
			zahlen[i]= zufall.nextInt(45) +1; //1...45
			
			// gibts die Zahl schon?
			boolean bereitsGezogen=false;
			for (int j = 0; j < i; j++) {
				if (zahlen[i]== zahlen[j]){
					bereitsGezogen=true;
				}
			}
			if(bereitsGezogen==true){
				i--;
			}
		}//for
		
		//fertig, jetzt noch die Views informieren
		this.setChanged();
		this.notifyObservers(this);
		
	}

	public int[] getData(){
		return zahlen;
	}
}
