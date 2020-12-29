/*
 * fifo.h
 */

#include <stdexcept>
#include <cassert>
using namespace  std;


// ----------------------------------------
class FIFO {
private:
	int* queue;
	int size, write, read;

public:
	FIFO(int size){
		===ENTER CODE===
	}
	~FIFO() { ===ENTER CODE=== }

	int dequeue()  {
		===ENTER CODE=== (isEmpty())
			throw underflow_error("dequeue: underflow_error");

		int value = queue[read];
		===ENTER CODE===
		return value;
	}

	bool isEmpty(){
		if(===ENTER CODE===){
			return true;
		}
		return false;
	}

	bool isFull(){
		if(===ENTER CODE===){
			return true;
		}
		return false;
	}

	void enqueue(int item)  {
		===ENTER CODE=== {
			throw overflow_error("enqueue: overflow_error");
		}
		else{
			queue[write] = item;
			===ENTER CODE===
		}
	}
};


