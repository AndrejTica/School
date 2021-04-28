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
	
	public boolean isEmpty()
	{
		return begin==end;
		
	}
	
	public boolean isFull()
	{
		return ((begin+1)%size)==end;
		
	}
	
	synchronized public void enqueue(int item){
		while(this.isFull()) // !!!!!!!!!!!!!!!
			try {wait();}catch(InterruptedException _ex){};
		
		queue[begin] = item;
		begin++;
		begin%=size;
		
		notify();
	}
	
	synchronized public int dequeue() 
	{
		while(this.isEmpty())
			try {wait();}catch(InterruptedException _ex){};
		
		int a = queue[end];
		end++;
		end%=size;
		notify();
		
		return a;
					
	}

}

//class FullException extends Exception{}
//class EmptyException extends Exception{}
