// ahofmann, 2017
// main.cpp
// bank logging: write logfile

#include <iostream>
using namespace std;

#include "bank.h"
 
int main(){
	Bank* myBank;
	myBank = new Bank("Hofmann-unlimited");
	myBank->setLogging(true);
	myBank->reset();

	myBank->addAccount("Anton Hofmann", 100.0);
	myBank->addAccount("Beta Hofmann", 200.0);
	myBank->addAccount("Gamma Hofmann",300.0);

	myBank->delAccount("Anton Hofmann");
	myBank->addAccount("Omega Hofmann", 509.0);

	myBank->addInterest(100.0);
	myBank->charges(100.0);

	myBank->deposit("Omega Hofmann", 1.0);
	myBank->withdraw("Omega Hofmann", 10.0);

	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(2);
	cout << myBank->getSumDeposits() <<endl;

	delete myBank;

	return 0;
}

/*
First, output should be:
1000.00
*/
