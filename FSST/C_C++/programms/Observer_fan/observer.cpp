#include "observer.h"
#include "observable.h"

Observer::Observer()
{
}


void Observer::update(){
        cout << "Observer: update() wurde aktiviert .........." << endl; //weil pure virtuelle methoden die werden doch nie aufgerufen weil sie in baseclass sind
}


void Observer::update(Observable* o){
        cout << "Observer: update() wurde aktiviert .........." << endl;
}
