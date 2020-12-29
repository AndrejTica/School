
#include "manager.h"

#include <iostream>
#include <sstream>
using namespace std;


Manager::Manager(int age, string name, double fixedSalaray) 
: Person(age,name){
	fixedSalary_= fixedSalaray;
}
string Manager::toString()const{
	ostringstream out;
    
    out << Person::toString();

    out << "fixedSalary: ";
    out <<  fixedSalary_ << endl;
    
    return out.str();
}

double Manager::getWage() const{
	return fixedSalary_;
}

