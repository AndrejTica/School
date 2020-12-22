// seller.cpp

#include "seller.h"

#include <iostream>
#include <sstream>
using namespace std;

Seller::Seller(int age, string name,
               int hours, double wage,
               int numberOfSales, double price) : Worker(age, name, hours, wage){
this->numberOfSales=numberOfSales;
this->price=price;

};

double Seller::getWage()const{
    return Worker::getWage + price*numberOfSales;

}



string Seller::toString() const {
	ostringstream out;
    
    out << Worker::toString();

    out << "numberOfSales: ";
    out <<  numberOfSales;
    out << "\nprice: " ;
    out << price;
    out << "\n";
    
    return out.str();
}
		
