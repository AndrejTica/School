#include "watch.h"

Watch::Watch(string name, double weight, double price, string manufacturer)
: Item(name,weight), manufacturer(manufacturer)
{}


double Watch::getValue() const{
    return (manufacturer=="Omega") ? Item::getWeight() * price *1.2 : Item::getWeight()*price;
}

string Watch::toString() const{
    string ret = Item::toString();
    ret += "   manufacturer: " + manufacturer + "\n";
    return ret;
}
