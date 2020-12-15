// bank.h

#pragma once

#include "account.h"

#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Bank
{
private:
	string name_;
	vector<Account*> accounts_;
	
public:
	Bank(string name);
	
	// ENTER CODE
	
	~Bank();
};
