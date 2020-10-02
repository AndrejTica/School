/*
g++ fifo-threadsafe.cpp -o fifo-threadsafe.exe -lpthread
*/

// https://baptiste-wicht.com/posts/2012/03/cp11-concurrency-tutorial-part-2-protect-shared-data.html
// http://www.cplusplus.com/reference/condition_variable/condition_variable/

/*

Use wait() to block the calling thread, until the other thread has finished execution (or until a specified time has passed).


QMutex is the basic class for enforcing mutual exclusion. A thread locks a mutex in order to gain access to a shared resource. If a second thread tries to lock the mutex while it is already locked, the second thread will be put to sleep until the first thread completes its task and unlocks the mutex.

QWaitCondition synchronizes threads not by enforcing mutual exclusion but by providing a condition variable. While the other primitives make threads wait until a resource is unlocked, QWaitCondition makes threads wait until a particular condition has been met. To allow the waiting threads to proceed, call wakeOne() to wake one randomly selected thread or wakeAll() to wake them all simultaneously. The Wait Conditions Example shows
how to solve the producer-consumer problem using QWaitCondition instead of QSemaphore.



We guard all accesses to the numUsedBytes variable with a mutex. In addition, the QWaitCondition::wait() function accepts a mutex as its argument. This mutex is unlocked before the thread is put to sleep and locked when the thread wakes up. Furthermore, the transition from the locked state to the wait state is atomic, to prevent race conditions from occurring.

*/



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
//		if(this->isFull()){
//			throw overflow_error("enqueue: overflow_error");
//		}

		mutex.lock();
		while(isFull())
			wc_isFull.wait(&mutex);



		queue[begin] = item;
		begin++;
		begin%=size;

		wc_isEmpty.wakeAll();

		mutex.unlock();
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
