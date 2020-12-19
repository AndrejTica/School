#include "presseagentur.h"
#include "fussballverein.h"

Presseagentur::Presseagentur(string name): Observer()
{
    this->name= name;
}


void Presseagentur::update(){
    cout << "PRESSE: [" << name << "] bin aktiviert worden." << endl;
}


void Presseagentur::update(Observable* o){
    cout << "PRESSE: [" << name << "] bin aktiviert worden." << endl;

    Fussballverein* v= (Fussballverein*) o;
    cout << "\tP R E S S E M I T T E I L U N G: <" << v->getPresseMitteilung() << ">" << endl <<endl;


}
