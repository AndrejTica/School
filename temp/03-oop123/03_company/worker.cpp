// worker.cpp

#include "worker.h"

#include <string>
#include <sstream>
using namespace std;

// ENTER CODE

	
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
