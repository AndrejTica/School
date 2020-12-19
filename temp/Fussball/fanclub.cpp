#include "fanclub.h"
#include "fussballverein.h"

Fanclub::Fanclub(string name):name(name)
{
}

void Fanclub::update()
{
	cout << "FANCLUB: [" << name << "] bin aktiviert worden." << endl;
}

void Fanclub::update(Observable* o)
{
	cout << "FANCLUB: [" << name << "] bin aktiviert worden." << endl;

	Fussballverein* v = (Fussballverein*)o;
	cout << "\tA U F G E P A S S T  K A M E R A D E N: <" << v->getPresseMitteilung() << ">" << endl << endl;
}
