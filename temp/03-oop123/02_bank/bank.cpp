// ahofmann

// http://www.cplusplus.com/reference/vector/vector/
// http://de.cppreference.com/w/cpp/container/vector
// http://devdocs.io/cpp/


#include "bank.h"
#include <sstream>
#include <iostream>
#include <ctime>       /* time_t, struct tm, time, localtime, strftime */

using namespace std;




/*
void Bank::setLogging(bool enable)
{
	withLogging= true;
	// BANK_Hofmann_unlimited_2017-12-24_11-20.log
	string filename= "BANK_";
	
	filename += name;
	filename += "_";
	
	time_t rawtime;
	struct tm * timeinfo;
	char buffer [80];

	time (&rawtime);
	timeinfo = localtime (&rawtime);

	strftime (buffer,80,"%F_%H-%M.log",timeinfo);
	filename += buffer;
	
	//cout << filename << endl;
	flog.open(filename);
	
}
*/




string Bank::toString() const{
	ostringstream os;
	
	os << "BANK: " << name_ << endl;
	
	// version 1
//	for(int i=0; i<accounts_.size(); i++){
//		os << accounts_[i]->toString() << endl;
//	}
	
	
	// version 2: iteratoren
//	vector<Account*>::iterator  it;
//	for (it= accounts_.begin(); it != accounts_.end(); it++){
//		os << (*it)->toString() << endl;
//	}
	
	// version 3: foreach loop c++11
//	for (Account* p : accounts_){
		
//		os << p->toString() << endl;
//	}
	
	// version 4: foreach loop c++11
	for (auto p : accounts_){
		
		os << p->toString() << endl;
	}
	
	return os.str();
}
