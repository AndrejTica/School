#include "observer.h"
#include "observable.h"

Observer::Observer()
{
}


void Observer::update(){
        cout << "Observer: update() wurde aktiviert .........." << endl;
}


void Observer::update(Observable* o){
        cout << "Observer: update() wurde aktiviert .........." << endl;
}
