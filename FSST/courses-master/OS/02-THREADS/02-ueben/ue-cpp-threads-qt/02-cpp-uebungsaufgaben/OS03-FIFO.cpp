#include <QThread>
#include <stdexcept>
#include <iostream>

using namespace  std;

// ----------------------------------------
class FIFO {
private:
	int* queue;
	int size, begin, end;

public:
	FIFO(int size){
		this->size = size+1;
		this->queue = new int[size+1];  // !!!!!!!
		begin = 0;
		end = 0;
	}
	~FIFO() { delete[] queue;}

	int dequeue()  {
		if (isEmpty())
			throw underflow_error("dequeue: underflow_error");

		// ***** ENTER CODE HERE *****

		return value;
	}

	bool isEmpty(){
		// ***** ENTER CODE HERE *****
	}

	bool isFull(){
		// ***** ENTER CODE HERE *****
	}

	void enqueue(int item)  {
		if(this->isFull()){
			throw overflow_error("enqueue: overflow_error");
		}
		else{
		// ***** ENTER CODE HERE *****
		}
	}
};


// ------------------------------------
class Producer : public QThread{
private:
	FIFO* fifo;
public:
	Producer(FIFO* fifo){
		this->fifo=fifo;
	}

 void produce(){
		for (int i=1; i<=5; i++){
			cout << "PRODUCER: enqueue " << i <<endl;
			fifo->enqueue(i);
		}
	}

 void run() override {
	 produce();
 }
};


// --------------------------------------
class Consumer : public QThread {
private:
	FIFO* fifo;

public:
	Consumer(FIFO* fifo){
		this->fifo=fifo;
	}

	void consume() {
		for (int i=1; i <=5; i++)
			cout << "\t\t\t\tCONSUMER: dequeue " << fifo->dequeue()<<endl;
	}
	void run() override {
		consume();
	}
};


int main(int argc, char *argv[]){

	FIFO* fifo= new FIFO(5);

	Producer* producer= new Producer(fifo);
	Consumer* consumer= new Consumer(fifo);

	producer->start();
	consumer->start();

	producer->wait();
	consumer->wait();

	return 0;
}
