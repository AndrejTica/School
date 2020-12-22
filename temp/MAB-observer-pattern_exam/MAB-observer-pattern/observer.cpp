#include "observer.h"
#include "observable.h"

Observer::Observer(string name) : name(name){}

void Observer::update(Observable* o){
        cout << "Observer: update() wurde aktiviert .........." << endl;
		  cout << "   ...... ich (" << name << ") beobachte: " << o->getName() << endl;
}
