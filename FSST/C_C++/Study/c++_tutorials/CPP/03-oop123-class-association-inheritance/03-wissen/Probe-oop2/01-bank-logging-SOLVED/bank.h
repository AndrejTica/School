// bank.h

#pragma once

#include "account.h"

#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Bank {
private:
	string name;
	vector<Account*> accounts;

	bool withLogging;
	ofstream flog;
	
public:
	Bank(string name) {
		this->name= name;
		
		withLogging= false;
	}
	
	
	~Bank(){
		cout << endl;
		cout <<"DESTR of BANK called ...." << endl;
		
		// delete all accounts
		for(auto p : accounts)
			delete p;
		
		
		flog.close();
	}
	
	void setLogging(bool enable);
	
	
	
	void reset(){
		// delete all accounts!!!!!! DONT FORGET
		for(auto p : accounts)
			delete p;
		
		accounts.clear();
		Account::nextAccountNumber=0;
		
	}
	void addAccount(const Account& rother);
	void delAccount(const Account& rother);
	
	
	int addAccount(string owner, double value);
	void delAccount(string owner);
	
	Account& getAccount(int nr);
	
	void charges(double value);
	void addInterest(double value);
	
	void deposit(string owner, double value);
	void withdraw(string owner, double value);
	
	double getSumDeposits();
	
	string toString();
	
	
};


