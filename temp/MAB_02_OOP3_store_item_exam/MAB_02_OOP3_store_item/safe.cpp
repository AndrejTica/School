#include "safe.h"

Safe::Safe(string name, double weight, double content_value)
: Item(name, weight), content_value(content_value)
{}

// ENTER CODE  



string Safe::toString() const {
    string ret = Item::toString();
    ret += "   content_value: " + to_string(content_value) + "\n";
    return ret;

}
