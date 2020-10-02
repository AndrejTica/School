/*
javac OS04_FIFO_Synchronized.java
java OS04_FIFO_Synchronized
*/

class FIFO //
// ENTER CODE HERE
//

class Producer//
// ENTER CODE HERE
//

class Consumer//
// ENTER CODE HERE
//

public class OS04_FIFO_Synchronized {
	public static void main(String[] args){
		FIFO fifo= new FIFO(5);
		
		Producer producer= new Producer(fifo);
		Consumer consumer= new Consumer(fifo);
		
		producer.produce();
		consumer.consume();
	}
}
