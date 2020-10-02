#include <QThread>
#include <stdexcept>
#include <iostream>
#include <QMutex>
#include <QWaitCondition>
using namespace  std;

// ----------------------------------------
class FIFO {
private:
	int* queue;
	int size, begin, end;

	// Sperrsync
	static QMutex mutex;

	// Ereignissync:
	static QWaitCondition wc_isFull;
	static QWaitCondition wc_isEmpty;

public:
	FIFO(int size){
		this->size = size+1;
		this->queue = new int[size+1];  // !!!!!!!
		begin = 0;
		end = 0;
	}
	~FIFO() { delete[] queue;}

	int dequeue()  {
		//		if (isEmpty())
		//			throw underflow_error("dequeue: underflow_error");

		mutex.lock(); // !!!!!!!!!!!!!!
		while(isEmpty())
			wc_isEmpty.wait(&mutex); // !!!!!!!!!!!!!!!

		int value = queue[end];
		end++;
		end %= size;

		wc_isFull.wakeAll();
		mutex.unlock(); // !!!!!!!!!!!!

		return value;
	}

	bool isEmpty(){
		if(begin == end){
			return true;
		}
		return false;
	}

	bool isFull(){
		if(end == (begin+1)%size){
			return true;
		}
		return false;
	}

	void enqueue(int item)  {

		// ***** ENTER CODE HERE *****
		
	}
};
// Sperrsync
QMutex FIFO::mutex;

// Ereignissync:
QWaitCondition FIFO::wc_isFull;
QWaitCondition FIFO::wc_isEmpty;


// ------------------------------------
class Producer : public QThread{
private:
	FIFO* fifo;
public:
	Producer(FIFO* fifo){
		this->fifo=fifo;
	}

	void produce(){
		for (int i=1; i<=5000; i++){
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
		for (int i=1; i <=5000; i++)
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
