/*
g++ 09-test-fifo.cpp -o 09-test-fifo.exe -lpthread
*/

#include <iostream>
#include <cassert>
#include "fifo.h"
using namespace std;



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
