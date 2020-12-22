// worker.cpp

#include "worker.h"

#include <sstream>
using namespace std;

Worker::Worker(int age, string name, int hours, double wage) : Person(age, name) {
    this->hours=hours;
    this->wage=wage;

};

//  double Worker::getWage() const{
//     // return getAge();      auch nicht weil rekursiver aufruf
// //     return age;              return nicht möglich, weil in person base class private
//  }

double Worker::getWage() const{
    return hours * wage;
}

	
string Worker::toString()const
{
    ostringstream out;
    
    out << Person::toString();

    out << "HOURS: ";
    out <<  hours;
    out << "\nWAGE: " ;
    out << wage;
    out << "\n";
    
    return out.str();
}
