/** 
 * @brief A stack and exception
 *
 * @file test-stack-exception.cpp
 * @author Anton Hofmann 
 * @date 12 Feb 2017
 *
 */

#include <cstdio>
#include <cstdlib>		// size_t
#include <iostream>
using namespace std;

#include <new>				// !!!!!!!!!! std::bad_alloc
#include <stdexcept>      	// !!!!!!!!!! std::out_of_range
							// !!!!!!!!!! std::overflow_error
							// !!!!!!!!!! std::underflow_error

#include "stack.h"		//Die eigene Klasse Stack

// ---------------------------------------------------------------------
int  main(){

	Stack stack(5);

	cout << "*** Test 1: top mit leerem stack ..." << endl;
	try{
		double v= stack.top();
	}catch (underflow_error& ex){ cerr << ex.what() << endl;}

	cout << "*** Test 2: Stack Überlauf ..." << endl;
	try{
		stack.push(1);
		stack.push(2);
		stack.push(3);
		stack.push(4);
		stack.push(5);
		stack.push(6);
	}catch (overflow_error& ex){ cerr << ex.what() << endl;}


	return 0;
}
/*Ausgabe
*** Test 1: top mit leerem stack ...
stack.cpp:31:ERROR: underflow_error sp= 0 size= 5

*** Test 2: Stack Überlauf ...
stack.cpp:43:ERROR: overflow_error sp= 5 size= 5 value= 6 cannot be pushed!
*/


