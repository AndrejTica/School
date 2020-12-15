// NAME
// DATE
// account

#include "account.h"
#include <sstream>

// static members
// ENTER CODE

Account::Account(string name, double value)
{
	// ENTER CODE
}

string Account::toString()const
{
	ostringstream os;

	os << "   ACCOUNT: " << endl;
	os << "      Owner: " << owner_ << endl;
	os << "      Number: " << number_ << endl;
	os << "      Amount: " << amount_ << endl;

	return os.str();
}
