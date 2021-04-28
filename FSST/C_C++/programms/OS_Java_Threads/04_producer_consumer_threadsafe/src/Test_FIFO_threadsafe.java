/*
javac Test_FIFO_threadsafe.java
java  Test_FIFO_threadsafe
*/

// -------------------------------------
class Producer extends Thread{
	FIFO fifo;

	public Producer(FIFO fifo){
		this.fifo=fifo;
	}
	
	@Override
	public void run(){
		produce();
	}
	
	public void produce() {
		for (int i=1; i <=500; i++){
			System.out.println("PRODUCER: enqueue " + i);	
			fifo.enqueue(i);
		}
	}
}

// -------------------------------------
class Consumer extends Thread{
	FIFO fifo;
	
	public Consumer(FIFO fifo){
		this.fifo=fifo;
	}
	
	@Override
	public void run(){
		consume();
	}
	
	public void consume()  {
		for (int i=1; i <=500; i++)
			System.out.println("\t\t\t\tCONSUMER: dequeue " + fifo.dequeue());	
	}
}

// -------------------------------------
public class Test_FIFO_threadsafe {
	public static void main(String[] args){
	
		FIFO fifo= new FIFO(5);
		
		Thread producer= new Producer(fifo); // erstellt 500 Elemente
		
		Thread consumer= new Consumer(fifo); // nimmt 500 Elemente
		
		producer.start();
		consumer.start();
		
        try {
    
		    producer.join();
		    consumer.join();
        } catch(Exception e) {
        }
	}
}
