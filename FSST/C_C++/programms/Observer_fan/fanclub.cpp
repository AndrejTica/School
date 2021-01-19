#include "fanclub.h"
#include "fussballverein.h"

Fanclub::Fanclub(string n)  : name(n)
{
}

void Fanclub::update(){
    cout << "FANCLUB: [" << name << "] bin aktiviert worden." << endl;
}

void Fanclub::update(Observable* o)
{

    cout << "FANCLUB: [" << name << "] bin aktiviert worden." << endl;

    Fussballverein* v = (Fussballverein*)o; // cast?
    cout << "\tM I T T E I L U N G: <" << v->getPresseMitteilung() << ">" << endl << endl;

}
