#include "Manager.h"

    Manager::Manager(int a, std::string n, double f) : Person(n, a)
    {
        fixum=f;
    }

    double Manager::getFixum()const
    {
        return fixum;
    }


    double Manager::calcSalary() const
    {
        return getFixum();
    }

    std::string Manager::toString() const
    {
        std::string ret = "Manager: \n";
        ret += "Name: " + name + "\n";  //name protected also geht
        ret += "Age: " + std::to_string(getAge()) + "\n"; //weil Age ja private ist in der baseclass
        ret += "Fixum " + std::to_string(getFixum()) + "\n";    //auf wage(fixum können wir direkt zugreifen weil es ja in gleiche klasse ist, machen wir nicht weil eine member var ist die von toString verändert wird
        ret += "Salary: " + std::to_string(calcSalary()) + "\n";


        return ret;

    }
