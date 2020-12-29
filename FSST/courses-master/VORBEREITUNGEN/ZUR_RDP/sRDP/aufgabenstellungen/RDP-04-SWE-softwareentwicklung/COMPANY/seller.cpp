// ahofmann, 2013
// seller.cpp

#include "seller.h"

#include <iostream>
#include <sstream>
using namespace std;


Seller::Seller( int age, string name, 
	         int hours, double wage,
	         int  numberOfSales, double commission)
	         
	         : Worker(age, name, hours,wage) {
				 
	this->numberOfSales_= numberOfSales;
	this->commission_= commission;
}
	             
		
double Seller::getWage() const{
	return Worker::getWage() + commission_*numberOfSales_;
}


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
		
