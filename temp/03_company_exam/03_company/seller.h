// seller.h

#ifndef SELLER_H
#define SELLER_H
#include "worker.h"


class Seller : Worker { // ENTER CODE
private:
    int numberOfSales;
    double price;
public:
    Seller(int age, string name,
           int hours, double wage,
           int numberOfSales, double price);
           
    
    double getWage() const;

    string toString()const;

};

#endif
