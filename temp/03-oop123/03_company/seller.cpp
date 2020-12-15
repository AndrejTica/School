// seller.cpp

#include "seller.h"

#include <iostream>
#include <sstream>
using namespace std;

// ENTER CODE



string Seller::toString() const {
	ostringstream out;
    
    out << Worker::toString();

    out << "numberOfSales: ";
    out <<  numberOfSales_;
    out << "\ncommission: " ;
    out << commission_;
    out << "\n";
    
    return out.str();
}
		
