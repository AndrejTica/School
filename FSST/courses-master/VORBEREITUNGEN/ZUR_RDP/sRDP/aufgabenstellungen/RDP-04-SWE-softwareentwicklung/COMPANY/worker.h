// a.hofmann, 2013
// inheritance

#include <string>
#include "person.h"


#ifndef CWORKER_H
#define CWORKER_H

class Worker : public Person{
	private:
        int hours_;
        double wage_;

	public:
        // cons
        Worker( int age, string name, 
		        int hours, double wage );
			        
        // public access
	
        string toString()const;
        double getWage() const;
};
#endif
