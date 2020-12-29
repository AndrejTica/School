// ahofmann, 2013
// seller.h

#ifndef SELLER_H
#define SELLER_H
#include "worker.h"


class Seller : public Worker{
	private:
		int numberOfSales_;
		double commission_;
		
	public:
		Seller( int age, string name, 
	             int hours, double wage,
	             int numberOfsales, double commission);
	             
		string toString()const;

		double getWage() const;
};
#endif
