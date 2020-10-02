#include <iostream>
using namespace std;

#include "ringschlange.h"

#include <new>				// !!!!!!!!!! std::bad_alloc
#include <stdexcept>      	// !!!!!!!!!! std::out_of_range
							// !!!!!!!!!! std::overflow_error
							// !!!!!!!!!! std::underflow_error

int main(){

    Ringschlange rs(5); // 5 Stück müssen Platz haben
  	
	cout << "*** Test 1: dequeue mit leerer Ringschlange ..." << endl;
	try{
		int v= rs.dequeue();
	}catch (underflow_error& ex){ cerr << ex.what() << endl;}

	cout << "*** Test 2: Ringschlange Überlauf ..." << endl;
	try{
		rs.enqueue(1);
		rs.enqueue(2);
		rs.enqueue(3);
		rs.enqueue(4);
		rs.enqueue(5);
		rs.enqueue(6);
	}catch (overflow_error& ex){ cerr << ex.what() << endl;}


	cout << endl<< endl;

	
    return 0;
}
/* Ausgabe:

*/
