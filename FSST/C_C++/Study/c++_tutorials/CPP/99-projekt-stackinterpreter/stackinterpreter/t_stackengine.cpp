//a.hofmann dez 2004
#include <iostream>
#include <string>
#include "stackengine.h"
using namespace std;

int main(){
	CStackengine s;
	double dblValue;
	string str;
	
	do{
		cin >> str;
		if (str=="push"){
			cin >> dblValue;
			s.push(dblValue);
		}
		else if (str=="add")
			s.add();
		else if (str=="sub")
			s.sub();
		else if (str=="mul")
			s.mul();
		else if (str=="div")
			s.div();
	}while(str != "quit");	
	
	cout << s.top()<<endl;
	cout <<endl;
}
