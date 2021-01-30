// project: company
// main.cpp
// NAME: Andrej Tica
// DATE: 1.6.2020

#include <iostream>
#include <iomanip>
using namespace std;

#include "person.h"
#include "worker.h"
#include "Manager.h"
#include "seller.h"

#include "company.h"

int main(int argc, char *argv[]) {

    // 1. create some  Worker-, Seller-, Manager-Objects
    Worker *worker1= new Worker(50, "WorkerMaxi", 20, 100.0); //könnten wir das ganz normal instanzieren und statt pointer objekt übergeben die referenz übergeben? wie bei socialnetwork. Wäre sogar besser weil memory leak gefahr
    Manager *manager1= new Manager(40, "ManagerMaxi", 10.0);
    Seller *seller1= new Seller(40, "SellerMaxi", 40, 100.0, 10, 9.0);


//  Worker* worker1(....); können wir des nicht auch so machen?

    // 2. create the company
    Company* company1= new Company("IT unlimited");

    // 3. add Employees
    company1->addEmployee(worker1);
    company1->addEmployee(manager1);
    company1->addEmployee(seller1);

    cout << "*** The Company *****************************************" << endl;
    cout << company1->toString() << endl;


    cout << "*** The payroll *****************************************" << endl;
    double payroll= company1->computePayroll();

    cout << "The Payroll is " ; //gesamt gehalt aller worker
    cout << payroll << endl<<endl;


    delete worker1;
    delete seller1;
    delete manager1;
    delete company1;

    return 0;
}
