# CLIL-CPP: OOP-Project Company

File:AB-CPP-OOP-03-company.md

## Topic:	
	a) Inheritance
	b) Polmorphism


## What you should know
	baseclass
		aka "super class". Shares all its members with its subclasses.
		We call this reuseability.

	subclass
		gets all members of its baseclass(es) and implements additional
		so called "subclass specific members".
		Inhertied members can be overridden by the subclass.


	private, public, protected:
		private members can only be accessed by the class itself.
		proteced members can be accessed by the class and all its subclasses.
		public members can be accessed by every class.


	baseclass pointer
		???????? INSERT YOUR Answer here.????????????
	abstract class
		???????? INSERT YOUR Answer here.????????????
	virtual
		???????? INSERT YOUR Answer here.????????????
	polymorphism,
		???????? INSERT YOUR Answer here.????????????


## Inheritance
### LAB: Person - A base class
* create a baseclass Person that holds name and age of a person.
* create a small test-program

```cpp
	#include <string>
	using namespace std;

	#ifndef PERSON_H
	#define PERSON_H

	class Person{
		private:
		    // Private member. Nobody can access this member
		   int age;

		   // Protected member. 
		   // Only subclasses can access this member
		protected:
		    string name;

		public:
		   // cons
		   Person(int age, string name);

		   // getter/setter
		   int getAge() const;
	
		   string toString() const;
	};
	#endif


```

### LAB: Worker - A first subclass
* create the subclass Worker that inherits all from its baseclass Person.
* create a small test-program

```cpp
	#include <string>
	#include "person.h"

	#ifndef WORKER_H
	#define WORKER_H

	class Worker : public Person {
		private:
		    int hours;
		    double wage;

		public:
		    // cons
		    Worker( int age, string name, 
				    int hours, double wage );
					    
		    // getter/setter
			// Question: is this really necessary?????
		    int getAge() const;
	
		    string toString()const;

		    double getWage() const;
	};
	#endif
```

### LAB: Test - Person, Worker
* test your classes with the following code

```cpp
// Person
//     Worker

#include <iostream>
#include "worker.h"
using namespace std;

int main(int argc, char *argv[]){
	Worker* me;

	me= new Worker(80, "Jack Oldman", 40, 50.0);

	cout<< "\n********************************************" << endl;;
	cout<< me->toString()<< endl;

	cout<< "My age: " << me->getAge()<< endl;;
 	cout<< "My wage: " << me->getWage()<< endl;;

	delete me;


	cout<< "\n********************************************" << endl;;
	Worker you(20, "George Jungman", 20, 25.0);

	cout<< you.toString()<< endl;

	cout<< "Your age: " << you.getAge()<< endl;;
	cout<< "Your wage: " << you.getWage()<< endl;;


	cout << endl<<endl;

	return EXIT_SUCCESS;
}
```

### LAB: Seller, Manager - Add two subclasses
<!-- ----------------------------------------------------------------------- -->
* create class Seller as a subclass of Worker
* create class Manager as a subclass of Person
* test your classes (see above)

Seller: "is a Worker"
	private:
		int numberOfSales;
		double price;

	public:
		constructor
		getWage()	// like a work plus numberOfSales*price
		toString()
		getAge()   // do you really have to implement this method?


Manager: "is a Person" 
	private:
		double fixedSalary;

	public:
		constructor
		getWage()	// return fixedSalary
		toString()
		getAge()   // do you really have to implement this method?


## Polymorphism
### LAB: Company - A container class
* create the class Company which holds all Worker-, Seller-, Manager-Objects
* it uses a vector which contains the so called baseclass-pointers.
* this baseclass-pointer is of type Person* but
* it actually points to the different Worker-, Seller-, Manager-Objects

```cpp
#ifndef COMPANY_H
#define COMPANY_H

#include <vector>
using namespace std;
#include "person.h"

class Company {

private:
    vector<Person*>  employee;
    string name;

public:
    Company (string name);

    void addEmployee(Person* p);
    void removeEmployee(int age);

    double getPayroll() const;

    string toString() const;
};
#endif

```

### LAB: test-company.cpp - Test getPayroll()
* add to baseclass Person
```cpp
double getWage()const { return 0.0;}
```
* test your classes with the following code

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

#include "person.h"
#include "worker.h"
#include "manager.h"
#include "seller.h"

#include "company.h"

int main(int argc, char *argv[]) {

	// 1. create some  Worker-, Seller-, Manager-Objects
	Worker *worker1= new Worker(50, "WorkerMaxi", 20, 100.0);
	Manager *manager1= new Manager(40, "ManagerMaxi", 10.0);
	Seller *seller1= new Seller(40, "SellerMaxi", 40, 100.0, 10, 9.0);

	// 2. create the company
	Company* company1= new Company("IT unlimited");

	// 3. add Employees
	company1->addEmployee(worker1);
	company1->addEmployee(manager1);
	company1->addEmployee(seller1);

	cout << "*** The Company *****************************************" << endl;
	cout << company1->toString() << endl;


	cout << "*** The payroll *****************************************" << endl;
	double payroll= company1->getPayroll();

	cout << "The Payroll is " ;
	cout << fixed << setw(6) << setprecision(2)<< payroll << endl<<endl;


	delete worker1;
	delete seller1;
	delete manager1;
	delete company1;

	return 0;
}
```


* Question: What is the calculated payroll?



### LAB: Person - A baseclass becomes an abstract class
<!-- ----------------------------------------------------------------------- -->
* to fix the problem of calculating the wrong payroll you have to
* define getWage() as a pure virtual method. So the baseclass Person
	becomes an abstract class.

	```cpp
	virtual double getWage() const =0; 
	```
* note:
	* you cannot create objects from an abstract class. 
	* abstract classes are used to define a common interface for all subclasses.
	* the so called baseclass-pointer of an abstract baseclass is very often 
		used in container classes to hold many objects from different classes.
		But keep in mind, these objects have to share the same abstract base 
		class.


### LAB: test-company.cpp - SOLVED
* test your classes with the following code
* person.h, person.cpp
* worker.h, worker.cpp
* seller.h, seller.cpp
* manager.h, manager.cpp
* company.h, company.cpp
* test-company.cpp

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

#include "person.h"
#include "worker.h"
#include "cmanager.h"
#include "seller.h"

#include "company.h"

int main(int argc, char *argv[]) {

	// 1. create some  Worker-, Seller-, Manager-Objects
	Worker *worker1= new Worker(50, "WorkerMaxi", 20, 100.0);
	Manager *manager1= new Manager(40, "ManagerMaxi", 10.0);
	Seller *seller1= new Seller(40, "SellerMaxi", 40, 100.0, 10, 9.0);

	// 2. create the company
	Company* company1= new Company("IT unlimited");

	// 3. add Employees
	company1->addEmployee(worker1);
	company1->addEmployee(manager1);
	company1->addEmployee(seller1);

	cout << "*** The Company *****************************************" << endl;
	cout << company1->toString() << endl;


	cout << "*** The payroll *****************************************" << endl;
	double payroll= company1->getPayroll();

	cout << "The Payroll is " ;
	cout << fixed << setw(6) << setprecision(2)<< payroll << endl<<endl;


	delete worker1;
	delete seller1;
	delete manager1;
	delete company1;

	return 0;
}

/*
Additional Labs:
	void removeEmployee(string name);

	create class Coder as a subclass of Person.
	add an object of Coder to company1
	

Operator Overloading:
	*company1 << worker1 << seller1 << manager1;
	cout << *company1 << endl;
 */
```

### LAB: Company - UML Diagram
* create an UML Diagram of this project using umbrello

![Figure 1: uml-company](images/uml-company.png "UML Diagram Project Company")
