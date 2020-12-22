#include "item.h"

Item::Item(string name, double weight){
    this->name= name;
    this->weight = weight;
}

string Item::toString() const{
    string ret = "ITEM:\n";
    ret += "  name: " + name + "\n";
    ret += "  weight: " + to_string(weight) + "\n";
    return ret;
}
