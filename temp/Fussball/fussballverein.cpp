#include "fussballverein.h"

Fussballverein::Fussballverein(string name)
{
    this->name= name;
}

void Fussballverein::setPresseMitteilung(string msg){
    this->message=msg;

// v1
    this->notifyStateChange();

// v2

}

string Fussballverein::getPresseMitteilung() const{
    return message;
}
