// ahofmann, 2017
// account

#pragma once

#include <string>
#include <iostream>
using namespace std;



class Account {
private:
	int number; 
	string owner; 
	double amount; 
	
	//!!!!!!!!!
	static int nextAccountNumber;
	
	// !!!!!!!!!
	friend class Bank;
	Account(string name, double value);

public:
			
	void setAmount(double value){
		amount = value;
	}
	
	double getAmount(){
		return amount;
	}
	
	void deposit(double value){
		amount += value;
	}
	
	string toString();
	
	~Account(){
		cout << endl;
		cout << "Destr of account called ..." << endl;
	}
}; 
