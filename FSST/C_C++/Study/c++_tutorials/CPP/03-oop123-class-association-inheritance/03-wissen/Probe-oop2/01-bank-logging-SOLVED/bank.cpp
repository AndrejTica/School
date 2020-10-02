// ahofmann, 2017

// http://www.cplusplus.com/reference/vector/vector/
// http://de.cppreference.com/w/cpp/container/vector
// http://devdocs.io/cpp/


#include "bank.h"
#include <sstream>
#include <iostream>
#include <ctime>       /* time_t, struct tm, time, localtime, strftime */

using namespace std;



void Bank::deposit(string owner, double value){
	// search account
	for(auto p: accounts)
		if (p->owner == owner){
			p->amount += value;
			
			if(withLogging)
				flog << "FORONE:"<<owner<<":PLUS:"<<value<<endl;

			return;
		}
}

void Bank::withdraw(string owner, double value){
	// search account
	for(auto p: accounts)
		if (p->owner == owner){
			p->amount -= value;

			if(withLogging)
				flog << "FORONE:"<<owner<<":MINUS:"<<value<<endl;

			return;
		}
}



double Bank::getSumDeposits(){
	double sum=0.0;
	for(auto p: accounts)
		sum += p->getAmount();
	
	return sum;
}


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

Account& Bank::getAccount(int nr){
	for (auto p : accounts){
		if (p->number==nr)
			return *p;
	}
	// todo: not found -> throw exception;
}

void Bank::addAccount(const Account& rother){
	accounts.push_back((Account*)&rother);
}


	
int Bank::addAccount(string owner, double value){
	
	Account* p= new Account(owner, value);
	//!!!!!!!!DONT forget DELETE
	
	accounts.push_back(p);
	
	if(withLogging)
		flog << "ADD:"<<owner<<":"<<value<<endl;

	
	return p->number;
}



void Bank::delAccount(string owner){
	vector<Account*>::iterator it;
	
	for (it= accounts.begin(); it!= accounts.end(); it++){
		
		if (owner == (*it)->owner){
			accounts.erase(it);

			if(withLogging)
				flog << "DEL:"<<owner<<endl;


			return;
		}
	}
	
}


void Bank::delAccount(const Account& rother){
	vector<Account*>::iterator it;
	
	for (it= accounts.begin(); it!= accounts.end(); it++){
		
		if (&rother == (*it)){
			accounts.erase(it);
			return;
		}
	}
	
}

void Bank::addInterest(double value){
	for (auto p: accounts)
		p->setAmount(p->getAmount()  + value);
	
	if(withLogging)
		flog << "FORALL:PLUS:"<<value<<endl;


}

void Bank::charges(double value){
	
	for(int i=0; i<accounts.size(); i++){
		accounts[i]->setAmount(accounts[i]->getAmount() -value);
	}

	if(withLogging)
		flog << "FORALL:MINUS:"<<value<<endl;
	
}



string Bank::toString(){
	ostringstream os;
	
	os << "BANK: " << name << endl;
	
	// version 1
//	for(int i=0; i<accounts.size(); i++){
//		os << accounts[i]->toString() << endl;
//	}
	
	
	// version 2: iteratoren
//	vector<Account*>::iterator  it;
//	for (it= accounts.begin(); it != accounts.end(); it++){
//		os << (*it)->toString() << endl;
//	}
	
	// version 3: foreach loop c++11
//	for (Account* p : accounts){
		
//		os << p->toString() << endl;
//	}
	
	// version 4: foreach loop c++11
	for (auto p : accounts){
		
		os << p->toString() << endl;
	}
	
	
	
	
	return os.str();
}
