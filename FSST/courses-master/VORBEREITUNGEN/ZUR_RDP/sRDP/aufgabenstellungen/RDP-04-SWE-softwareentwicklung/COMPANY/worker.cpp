// a.hofmann, 2007
// cworker.cpp

#include "worker.h"

#include <string>
#include <sstream>
using namespace std;

Worker::Worker(  int age, string name, 
	                  int hours, double wage )
          // cons of superclass calling
          : Person(age, name)
{
    this->hours_= hours;	
	this->wage_ = wage;
}

	
string Worker::toString()const
{
    ostringstream out;
    
    out << Person::toString();

    out << "HOURS: ";
    out <<  hours_;
    out << "\nWAGE: " ;
    out << wage_;
    out << "\n";
    
    return out.str();
}


double Worker::getWage() const
{
    return hours_ * wage_;	
}
