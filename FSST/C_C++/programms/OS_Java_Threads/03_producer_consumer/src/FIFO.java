public class FIFO {

	private int [] queue;
	private int size, begin, end;   // begin of queue and end of queue
	
	FIFO(int size) // to store size elements
	{
			this.size = size+1;
			this.queue = new int[this.size];
			begin = 0;
			end = 0;
	}
	
	public int dequeue() throws EmptyException
	{
		if(this.isEmpty()) {
			throw new EmptyException();
		}
		else {
			int a = queue[end];
			end++;
			end%=size;
			return a;
		}
			
	}
	
	public boolean isEmpty()
	{
		return begin==end;
		
	}
	
	public boolean isFull()
	{
		return ((begin+1)%size)==end;
		
	}
	
	public void enqueue(int item) throws FullException {
		if(this.isFull()){
			throw new FullException();
		}
		else{
			queue[begin] = item;
			begin++;
			begin%=size;
		}
	}
}
