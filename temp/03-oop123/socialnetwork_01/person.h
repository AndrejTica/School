// person.h

#pragma once

#include <string>
using namespace std:

class Person

{
private:
	string forename;
	string surname;
public:
	Person(string v, string n);
	
	string getForename() const;
	string getSurname() const;
	
};

// ENTER CODE
