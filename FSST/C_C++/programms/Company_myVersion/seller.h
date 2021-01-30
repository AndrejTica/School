#ifndef SELLER_H_INCLUDED
#define SELLER_H_INCLUDED
#include "worker.h"

class Seller : public Worker
{
private:
    int numberOfSales;
    double price;
public:
    Seller(int a, std::string n, int h, double w, int numSales, double p);

    double getNumberOfSales()const;
    double getPrice() const;
    double calcSalary() const;
    std::string toString() const;

};



#endif // SELLER_H_INCLUDED
