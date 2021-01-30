#include "worker.h"

    Worker::Worker(int a, std::string n, int h, double w) : Person(n, a)
    {
        hours = h;
        wage = w;
    }


    double Worker::getWage() const  //bei den getters wird immer eine kopie returned
    {
        return wage;
    }

    int Worker::getHours() const
    {
        return hours;
    }

    double Worker::calcSalary() const  //bei den getters wird immer eine kopie returned
    {
        return getWage() * getHours();
    }

    std::string Worker::toString() const
    {
        std::string ret = "WORKER: \n";
        ret += "Name: " + name + "\n";  //name protected also geht ohne getter
        ret += "Age: " + std::to_string(getAge()) + "\n"; //weil Age ja private ist in der baseclass
        ret += "Hours " + std::to_string(getHours()) + "\n";  //auf wage können wir direkt zugreifen weil es ja in gleiche klasse ist,
        ret += "Wage " + std::to_string(getWage()) + "\n";    //auf wage können wir direkt zugreifen weil es ja in gleiche klasse ist,
        ret += "Salary: " + std::to_string(calcSalary()) + "\n";



        return ret;

    }
