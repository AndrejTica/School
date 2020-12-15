#include <iostream>
using namespace std;

#include "bank.h"
#include "account.h"

int main(){
	Bank *myBank;
	myBank = new Bank("Hofmann unlimited");

	cout << "\n\n"<<endl;
	cout << "-------------------------------------------------"<<endl;
	cout << " TEST: STATIC members "<<endl;
	cout << "-------------------------------------------------"<<endl;


	myBank->addAccount("Anton Hofmann", 100.0);
	myBank->addAccount("Beta Hofmann", 200.0);
	myBank->addAccount("Gamma Hofmann", 300.0);

	cout << myBank->toString() << endl;


	cout << "\n\n"<<endl;
	cout << ".... delete Account: Anton Hofmann and add Account: Omega Hofmann";
	cout << " Look at the account number!!!"<<endl;

	myBank->delAccount("Anton Hofmann");
	myBank->addAccount("Omega Hofmann", 900.0);

	cout << myBank->toString() << endl;
	cout << endl;


	cout << "\n\n"<<endl;
	cout << "-------------------------------------------------"<<endl;
	cout << " TEST: FRIEND class "<<endl;
	cout << "-------------------------------------------------"<<endl;
	cout << " ONLY class bank can create new Account-objects" <<endl;

//	Account k1("Anton Hofmann", 123.0); 	// error, because cons is private

	int accountNr= myBank->addAccount("Anton Hofmann", 100.0);
	myBank->getAccount(accountNr).deposit(9000.0);

	cout << myBank->toString() << endl;
	cout << endl;


	cout << "-------------------------------------------------"<<endl;
	cout << " TEST: Prepare "<<endl;
	cout << "-------------------------------------------------"<<endl;

	cout << "... 1. double d= myBank->getMaxAccount().getAmount(); "<<endl;
	double d= myBank->getMaxAccount().getAmount();
	cout << "...    Maximal amount = " << d << endl <<endl;

	cout << "... 2. double d= myBank->getMaxAccount().getAmount(); "<<endl;
	d= myBank->getStandardDeviation();
	cout << "...    Standard Deviation = " << d << endl << endl;

	cout << "... 3. myBank->delAccount(myBank->getAverageAmount()); "<<endl;
	cout << "...    delete all Account having less then the average amount"<<endl;
	cout << "...    Average Amount= " << myBank->getAverageAmount() << endl<<endl;
	myBank->delAccount(myBank->getAverageAmount());

	cout << myBank->toString() << endl;
	cout << endl;

	d= myBank->getStandardDeviation();
	cout << "Standard Deviation = " << d << endl << endl;

	delete myBank;

	return 0;
}


/*
- [X] The output should be:

-------------------------------------------------
 TEST: STATIC members
-------------------------------------------------

Bank: Hofmann unlimited
...Account-owner: Anton Hofmann
...Account-number: 1
...Account-amount: 100

...Account-owner: Beta Hofmann
...Account-number: 2
...Account-amount: 200

...Account-owner: Gamma Hofmann
...Account-number: 3
...Account-amount: 300


.... delete Account: Anton Hofmann and add Account: Omega Hofmann Look at the account number!!!
Account destructor ...

Bank: Hofmann unlimited
...Account-owner: Beta Hofmann
...Account-number: 2
...Account-amount: 200

...Account-owner: Gamma Hofmann
...Account-number: 3
...Account-amount: 300

...Account-owner: Omega Hofmann
...Account-number: 4
...Account-amount: 900


-------------------------------------------------
 TEST: FRIEND class
-------------------------------------------------
 ONLY class bank can create new Account-objects

Bank: Hofmann unlimited
...Account-owner: Beta Hofmann
...Account-number: 2
...Account-amount: 200

...Account-owner: Gamma Hofmann
...Account-number: 3
...Account-amount: 300

...Account-owner: Omega Hofmann
...Account-number: 4
...Account-amount: 900

...Account-owner: Anton Hofmann
...Account-number: 5
...Account-amount: 9100


-------------------------------------------------
 TEST: Prepare
-------------------------------------------------
... 1. double d= myBank->getMaxAccount().getAmount();
...    Maximal amount = 9100

... 2. double d= myBank->getMaxAccount().getAmount();
...    Standard Deviation = 3747.92

... 3. myBank->delAccount(myBank->getAverageAmount());
...    delete all Account having less then the average amount
...    Average Amount= 2625

Account destructor ...
Account destructor ...
Account destructor ...

Bank: Hofmann unlimited
...Account-owner: Anton Hofmann
...Account-number: 5
...Account-amount: 9100

Standard Deviation = 0

Account destructor ...



Hint: vector.erase();
	After vector.erase(); decrement iterator

Hint: Standard Deviation
https://en.wikipedia.org/wiki/Standard_deviation

...In statistics, the standard deviation is a measure that is used to
quantify the amount of variation of a set of data values.

A standard deviation close to 0 indicates that the data points tend to be
very close to the mean (also called the expected value) of the set, while

a high standard deviation indicates that the data points are spread out
over a wider range of values.
*/
