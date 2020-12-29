// ahofmann, 2013
// manager.h

#ifndef MANAGER_H
#define MANAGER_H

#include "person.h"

class Manager : public Person{
	private:
		double fixedSalary_;
	public:
		Manager(int age, string name, double fixedSalaray);
		string toString()const;

		double getWage() const;
};

#endif
