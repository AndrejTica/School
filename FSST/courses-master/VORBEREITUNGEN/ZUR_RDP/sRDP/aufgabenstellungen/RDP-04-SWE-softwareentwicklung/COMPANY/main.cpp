// main.cpp
// ahofmann, 2015

#include <iostream>
#include <iomanip>
using namespace std;

#include "person.h"
#include "worker.h"
#include "manager.h"
#include "seller.h"

// ADD: PROGRAMMIERER
#include "programmierer.h"


#include "company.h"

int main(int argc, char *argv[]) {

    // 1. create some  Worker-, Seller-, Manager-Objects
    Worker *worker1= new Worker(50, "WorkerMaxi", 20, 100.0);
    Manager *manager1= new Manager(40, "ManagerMaxi", 10.0);
    Seller *seller1= new Seller(40, "SellerMaxi", 40, 100.0, 10, 9.0);

// ADD: PROGRAMMIERER
Programmierer* programmierer1= new Programmierer(40, "ProgrammiererMaxi", 40, 100.0, 1000);  
    // Lines OF Code


    // 2. create the company
    Company* company1= new Company("IT unlimited");

    // 3. add Employees
    company1->addEmployee(worker1);
    company1->addEmployee(manager1);
    company1->addEmployee(seller1);

// ADD: PROGRAMMIERER
company1->addEmployee(programmierer1);

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
    
// ADD: PROGRAMMIERER
    delete programmierer1;

    return 0;
}

