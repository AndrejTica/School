// a.hofmann jan 2005
// t_stackinterpreterv3.cc
// g++ t_stackinterpreterv3.cc stackinterpreterv3.cc stackengine.cpp -DDEBUG
#include "stackinterpreterv3.h"
#include <iostream>
using namespace std;

int main(){
	CStackinterpreter myInterpreter("stackiv2.stk");
	string input;
	
	cout << "\n\n.............................. Stackinterpreter-Test: ................................" <<endl;
	
	cout << "\nProg.name: (quit=ende):> ";
	cin >>input;
	while (input != "quit"){
		myInterpreter.reset();
		myInterpreter.open(input.c_str());
		myInterpreter.run();
	
		//cout << endl;
		//cout<< myInterpreter;

		cout << endl;
		cout <<"Ergebnis: " <<myInterpreter.top() << endl;
	
		cout << "\nProg.name: (quit=ende):> ";
		cin >>input;
	}
}

