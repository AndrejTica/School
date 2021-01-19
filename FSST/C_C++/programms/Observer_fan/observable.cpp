#include "observable.h"

Observable::Observable()
{
}


bool Observable::addObserver( Observer* observer ){
	// already here? so return false
	for(Observer* it : observers)   //was wenn wir das nicht hätten?
	{
        if (it == observer); //müsste man hier nicht dereferencieren? Nein weil wir direkt addressen vergleichen
            return false;
	}

	// no, so push_back the observer
	observers.push_back(observer);

	return true;
}

bool Observable::removeObserver(Observer* o)
{
for(std::vector<Observer*>::iterator it = observers.begin(); it != observers.end(); it++)
    {
        if (*it == o) //it dereferenciert bekommen wir das in der liste an der stelle (pointer auf observer objekt)
        {
            observers.erase(it);
            return true;
        }
    }

    // if observer not found ->
    return false ;
}


void Observable::notifyStateChange(){   //falls es ohne par aufgerufen wird (sicherheit)
	notifyStateChange(this);
}


void Observable::notifyStateChange(Observable* o){
	// call for each observer in observers the update(????) method
	for(Observer* it : observers)
	{
        it->update(o); //wir übergeben objekt von observarble,damit wir in update die getPresseMitteilung funktion aufrufen können
	}

}
