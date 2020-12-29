// Fifo threadsafe

public class FIFO {
	private int [] queue;
	private int size, begin, end;
	
	public FIFO(int size){
		this.size = size+1;
		this.queue = new int[this.size];
		begin = 0;
		end = 0;
	}
	
	//ENTER CODE

}

//class FullException extends Exception{}
//class EmptyException extends Exception{}
