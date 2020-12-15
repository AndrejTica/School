#include "person.h"


// ENTER CODE


void Person::addFriend(Person &aFriend)
{
    friends.push_back(&aFriend);
    aFriend.friends.push_back(this);
}
