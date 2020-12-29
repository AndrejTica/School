// ahofmann, 2016
// test-intarray.cpp

#include <iostream>
#include <cstdlib>


#include <new>				// !!!!!!!!!! std::bad_alloc
#include <stdexcept>      	// !!!!!!!!!! std::out_of_range

using namespace std;

#include "intarray.h"

int main(){

	try{

		Intarray a2(5,9);

		a2.setAt(-99,4711);

	}catch(std::out_of_range& ex) {
		cerr << ex.what() << endl;	
	}

	cout << endl<<endl;
	return 0;
}
/* Ausgabe:
intarray.cpp:89: Error: out_of_range size= 5 index= -99
9,9,9,9,9,
*/
