#include "fussballverein.h"

Fussballverein::Fussballverein(string name)
{
    this->name= name;
}

void Fussballverein::setPresseMitteilung(string msg){ //wenn was mitgeteilt wird, wird notify aufgerufen welcher dem observer mitteilt das es was gibt -> update aufruf für diesen observable
    this->message=msg;  //warum this ???? this braucht man doch wenn man gleichnamige variablen hat


   this->notifyStateChange(); //warum this ???? muesste doch genause so ohne gehen



}

string Fussballverein::getPresseMitteilung() const{
    return message;
}
