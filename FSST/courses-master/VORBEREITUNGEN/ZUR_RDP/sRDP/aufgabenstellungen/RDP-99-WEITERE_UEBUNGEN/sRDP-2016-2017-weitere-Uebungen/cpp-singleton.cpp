//ANLAGE: DESIGN-PATTERN: SINGLETON
//============================================================================
// Name        : uMuster-Singleton.cpp
// Author      : Max Mustermann
// Version     :
// Copyright   : open source
// Description : Design-pattern: Singleton
//============================================================================

#include <ctime>
#include <iostream>
using namespace std;

class Singleton {
?????????:
	// you cannot create an object
	Singleton() {}   
	
	// you cannot make a copy of an object
	Singleton(const ????????????) {}   
	
	// you cannot make a copy by assign-operator
	Singleton& operator=(const ????????????) { return *this; } 
	 
	~Singleton() {}

???????????:
	static Singleton& getInstance(){ 
		????????????? Singleton instance;
		return ????????????;
	}

	// other useful methods  
	void log(int level, string msg){
		time_t second;
		struct tm *atime;
		char sTime[80];
		
		time(&second);
		atime= localtime(&second);
		strftime(sTime, 80, "%c", atime);
		
		cout << sTime << ":" <<level << ":" << msg<<endl;
	}
};


int main() {
	// create the one and only one singleton object.
	// its created within getInstance(), that returns
	// reference to the singleton object
	
	Singleton logger= Singleton::getInstance();


	// Addresses are all the same, because of there is 
	// only one and only one singleton object

	cout << "\ndemonstration of singleton pattern: " << endl;
	cout << "   3 addresses should have the same value:" <<endl;
	cout << "   "<< hex << &logger << endl;
	cout << "   "<< hex << &Singleton::getInstance() << endl;
	cout << "   "<< hex << &Singleton::getInstance() << endl;

	// you can use/reference the singleton object 
	Singleton::getInstance().log(0, "this is my first log entry");

	logger.log(1, "here is my second log entry");

	return 0;
}
