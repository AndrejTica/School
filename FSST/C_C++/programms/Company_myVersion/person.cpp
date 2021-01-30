#include "person.h"


    Person::Person(std::string n, int a) //: name(n), age(a) is also a possible, but ill stick to the convention to only set constructors with the init list
    {
        name = n;
        age = a;
    }

    int Person::getAge() const
    {
        return age;
    }




