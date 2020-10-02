// u-templateStack.cpp
// name: ahofmann, 2015

// Bringen Sie folg. Programmfragment zum Laufen:

#include <iostream>
using namespace std;

#include "stack.h"

int main(){

	Stack<int> iStack(10);
	Stack<string> sStack(10);

	// sStack -----------------------------------------------------
	for (int i=0; i < 10; i++){
		int value= i*100;
		iStack.push(value);
	}
		 
	cout << iStack << endl;
	
	for (int i=0; i < 10; i++){
		int wert;
		wert= iStack.top();
		iStack.pop();

		cout << wert << ",";
	}

	cout << endl<<endl;
	
	// sStack -----------------------------------------------------
	string s1= "Wer ";
	string s2= "ist ";
	string s3= "da ";
	
	sStack.push(s1);
	sStack.push(s2);
	sStack.push(s3);

	// 
	cout << sStack << endl;

	cout << sStack.top();
	sStack.pop();
	
	cout << sStack.top();
	sStack.pop();
	
	cout << sStack.top();
	sStack.pop();
	
	cout << endl<<endl;

	return 0;
}
