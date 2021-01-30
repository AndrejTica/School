#include "seller.h"

    Seller::Seller(int a, std::string n, int h, double w, int numSales, double p) :  Worker(a, n, h, w)
    {
        numberOfSales = numSales;
        price = p;
    }

    double Seller::getNumberOfSales()const
    {
        return numberOfSales;
    }

    double Seller::getPrice() const
    {
        return price;
    }


    double Seller::calcSalary() const
    {
        return getWage() * getHours() + getPrice()* getNumberOfSales();   //dieses getWage kommt aus Worker, wir haben wage gesetzt mit konstruktor von worker, dort befindet sich auch der wage vom seller dem wir getten
    }

    std::string Seller::toString() const
    {

        std::string ret = "Seller: \n";
        ret += "Name: " + name + "\n";  //name protected also geht
        ret += "Age: " + std::to_string(getAge()) + "\n"; //weil Age ja private ist in der baseclass
        ret += "Hours " + std::to_string(getHours()) + "\n";  //auf wage können wir direkt zugreifen weil es ja in gleiche klasse ist, machen wir nicht weil eine member var ist die von toString verändert wird, wir erstellen eine kopie also mit get methoden
        ret += "Wage " + std::to_string(getWage()) + "\n";    //auf wage können wir direkt zugreifen weil es ja in gleiche klasse ist, machen wir nicht weil eine member var ist die von toString verändert wird
        ret += "Num of sales: " + std::to_string(getNumberOfSales()) + "\n";
        ret += "Price" + std::to_string(getPrice()) + "\n";
        ret += "Salary: " + std::to_string(calcSalary()) + "\n";  //hours auf double casten und sales


        return ret;

    }
