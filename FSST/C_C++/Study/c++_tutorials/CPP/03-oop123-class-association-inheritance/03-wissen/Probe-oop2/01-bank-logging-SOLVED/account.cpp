// ahofmann, 2017
// account

#include "account.h"
#include <sstream>

// static members
int Account::nextAccountNumber=0;

 
Account::Account(string name, double value){
	
	nextAccountNumber++;
	
	number= nextAccountNumber;
	owner= name; 
	amount= value; 
	 
}


string Account::toString(){
	ostringstream os;

	os << "   ACCOUNT: " << endl;
	os << "      Owner: " 	<< owner 	<< endl;
	os << "      Number: " 	<< number 	<< endl;
	os << "      Amount: " 	<< amount 	<< endl;
	
	return os.str();
}
