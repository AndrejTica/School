/*
g++ test-fifo.cpp -o test-fifo.exe -lpthread
*/

#include <stdexcept>
#include <iostream>
#include <cassert>

using namespace  std;


// ----------------------------------------
class FIFO {
private:
	int* queue;
	int size, write, read;

public:
	FIFO(int size){
		this->size = size+1;
		this->queue = new int[size+1];  // !!!!!!!
		write = 0;
		read = 0;
	}
	~FIFO() { delete[] queue;}

	int dequeue()  {
		if (isEmpty())
			throw underflow_error("dequeue: underflow_error");

		int value = queue[read];
		read++;
		read %= size;
		return value;
	}

	bool isEmpty(){
		if(write == read){
			return true;
		}
		return false;
	}

	bool isFull(){
		if(read == (write+1)%size){
			return true;
		}
		return false;
	}

	void enqueue(int item)  {
		if(this->isFull()){
			throw overflow_error("enqueue: overflow_error");
		}
		else{
			queue[write] = item;
			write++;
			write%=size;
		}
	}
};





// ====================================================
// TESTS f. class FIFO
// ====================================================
int main(){
// ----------------------------------------------------
	{
	FIFO fifo(5); // 5 Elemente haben Platz
	assert(fifo.isEmpty() && "Test: isEmpty()");
	}
// ----------------------------------------------------
	{
		FIFO fifo(5); // 5 Elemente haben Platz
		fifo.enqueue(1);
		fifo.enqueue(2);
		fifo.enqueue(3);
		fifo.enqueue(4);
		fifo.enqueue(5);
		assert(fifo.isFull() && "Test: isFull()");
	}
// ----------------------------------------------------
	{
		FIFO fifo(5); // 5 Elemente haben Platz
		fifo.enqueue(1);
		int val= fifo.dequeue();
		assert(val==1 && "Test: enqueue and dequeue");
		assert(fifo.isEmpty() && "Test: isEmpty()");
	}
// ----------------------------------------------------
	{
		try{
			FIFO fifo(5); // 5 Elemente haben Platz
			int val= fifo.dequeue();

			assert(false && "fail: underflow_exception ");

		} catch(underflow_error& e){
			// should come here
		}
	}
// ----------------------------------------------------
	{
		try{
			FIFO fifo(5); // 5 Elemente haben Platz
			fifo.enqueue(1);
			fifo.enqueue(2);
			fifo.enqueue(3);
			fifo.enqueue(4);
			fifo.enqueue(5);

			fifo.enqueue(6);

			assert(false && "fail: overflow_exception ");

		} catch(overflow_error& e){
			// should come here
		}
	}
// ----------------------------------------------------



	cout << "All tests passed ok ..." << endl;

	return 0;
}
