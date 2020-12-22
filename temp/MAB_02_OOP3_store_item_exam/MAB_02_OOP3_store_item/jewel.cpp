#include "jewel.h"

Jewel::Jewel(string name, double weight, double raw_material_value)
: Item(name,weight), raw_material_value(raw_material_value)
{}


// ENTER CODE


string Jewel::toString() const{
    string ret = Item::toString();
    ret += "   raw_material_value: " + to_string(raw_material_value) + "\n";
    return ret;
}
