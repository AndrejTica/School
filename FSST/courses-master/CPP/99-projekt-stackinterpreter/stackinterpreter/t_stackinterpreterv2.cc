// a.hofmann jan 2005
// t_stackinterpreterv2.cc
// g++ t_stackinterpreterv2.cc stackinterpreterv2.cc stackengine.cpp -DDEBUG
#include "stackinterpreterv2.h"
#include <iostream>
using namespace std;

int main(){
	CStackinterpreter myInterpreter("stackiv2.stk");
	
	myInterpreter.run();
	
	cout << endl;
	cout<< myInterpreter;

	cout << endl;
	cout <<"Ergebnis: " <<myInterpreter.top() << endl;
	
}
