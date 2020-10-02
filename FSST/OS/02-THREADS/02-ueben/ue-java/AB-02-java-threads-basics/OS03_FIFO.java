/*
javac OS03_FIFO.java
java OS03_FIFO
*/

class FIFO //
// ENTER CODE HERE
//

class FullException extends Exception{}
class EmptyException extends Exception{}

// ------------------------------------
class Producer{
	FIFO fifo;
	public Producer(FIFO fifo){
		this.fifo=fifo;
	}
	
	public void produce() throws FullException{
		for (int i=1; i <=5; i++){
			System.out.println("PRODUCER: enqueue " + i);	
			fifo.enqueue(i);
		}
	}
}

// --------------------------------------
class Consumer{
	FIFO fifo;
	public Consumer(FIFO fifo){
		this.fifo=fifo;
	}
	
	public void consume() throws EmptyException {
		for (int i=1; i <=5; i++)
			System.out.println("\t\t\t\tCONSUMER: dequeue " + fifo.dequeue());	
	}
}


public class OS03_FIFO {
	public static void main(String[] args) throws FullException, EmptyException{
		FIFO fifo= new FIFO(5);
		
		Producer producer= new Producer(fifo);
		Consumer consumer= new Consumer(fifo);
		
		producer.produce();
		consumer.consume();
	}
}
