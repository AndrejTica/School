// a.hofmann jan 2005
// t_stackinterpreterv1.cc
// g++ t_stackinterpreterv1.cc stackinterpreterv1.cc stackengine.cpp -DDEBUG
#include "stackinterpreterv1.h"
#include <iostream>
using namespace std;

int main(){
	CStackinterpreter myInterpreter("prog1.stk");
	
	myInterpreter.run();
	
	cout << endl;
	//cout<< myInterpreter;

	cout << endl;
	cout <<"Ergebnis: " <<myInterpreter.top() << endl;
	
}
