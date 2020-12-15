// ----------------------------------------------
// BANK: main.cpp
// -----------------------------------------------

#include "bank.h"
#include "account.h"
#include <iostream>
using namespace std;

/*
class Bank with logging

  [X] Every bank transaction has to be logged.
  [X] implement in class Bank:

	Bank(string name);

	void setLogging(bool);
		// if true
		// creates logfile
		// Filename for Logging is BANK_name_DATE.log
		// e.g.: BANK-Hofmann-unlimited-2017-12-24-11-20.log


	~Bank();
		// closes logfile

	void reset();
		// delete all accounts and
		// reset static Account::nextAccountNumber;


	int addAccount(string owner, double value);
		// write to logfile:
		// ADD:owner:value


	void delAccount(string owner);
		// write to logfile:
		// DEL:owner


	Account& getAccount(int nr);

	void charges(double value);
		// write to logfile:
		// FORALL:MINUS:value


	void addInterest(double value);
		// write to logfile:
		// FORALL:PLUS:value

	void deposit(string owner, value);
		// write to file
		// FORONE:owner:PLUS:value

	void withdraw(string owner, value);
		// write to file
		// FORONE:owner:MINUS:value

	double getSumDeposits(); // returns sum of all accounts

	string toString();


  [X] Test with this code:
*/


#define LOGGING
// #define RECOVERY


#ifdef LOGGING

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

	cout << myBank->getSumDeposits() <<endl;

	delete myBank;

	return 0;
}

/*
First: output should be:
1000.00



Second: the logfile: BANK-Hofmann-unlimited-2017-12-24-11-20.log
ADD:Anton Hofmann:100.00
ADD:Beta Hofmann:200.00
ADD:Gamma Hofmann:300.00
DEL:Anton Hofmann
ADD:Omega Hofmann:509.00
FORALL:PLUS:100.00
FORALL:MINUS:100.00
FORONE:Omega Hofmann:PLUS:1.00
FORONE:Omega Hofmann:MINUS:10.00


Hinweis:
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

#endif



#ifdef RECOVERY
/*
class Bank with recovery

  [X] This Log-File can be used for backup/recovery.
  [X] Test with this code:
*/


// main.cpp
// bank logging: recovery with logfile

#include <iostream>
using namespace std;

#include "bank.h"

int main(){
	Bank* myBank;
	myBank = new Bank("Hofmann-unlimited");
	myBank->setLogging(false);


	myBank->recovery("BANK-Hofmann-unlimited-2017-12-24-11-20.log");


	cout << myBank->getSumDeposits() <<endl;

	delete myBank;

	return 0;
}
/*
output should be:
1000.00
*/

#endif


/*
- Hint: precision
	double f = 1234.123456789012345;
	cout.setf(ios::scientific, ios:: floatfield);
	cout.precision(4);
	cout<< f << endl; //1.2341e+03
	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(4);
	cout<< f << endl;  //1234.1234

- Hint: split
	string s="ABC:123:def";
	string split;

	istringstream is(s);
	getline(is, split, ':');
	cout << split;

	getline(is, split, ':');
	cout << split;

	getline(is, split, ':');
	cout << split;


- Hint: Filehandling
	* http://www.cplusplus.com/reference/ios/ios/exceptions/
	* Get/set exceptions mask

	// ios::exceptions
	#include <iostream>     // std::cerr
	#include <fstream>      // std::ifstream

	using namespace std;

	int main () {
		std::ifstream file;
		string sinput;

		// set exception mask
		file.exceptions ( std::ifstream::badbit | std::ifstream::failbit);

		try {
			file.open ("test.txt");


			while (!file.eof()) {
				// zeichenweise mit: file.get();

				// wortweise lesen mit: file >> sinput

				// zeilenweise lesen mit: std::getline
				std::getline(file, sinput, '\n');
				cout << sinput << endl;
			}

			file.close();
		}
		catch (std::ifstream::failure e) {
			std::cerr << "Exception opening/reading/closing file\n";
		}

		return 0;
	}
*/
