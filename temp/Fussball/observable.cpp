#include "observable.h"

Observable::Observable()
{
}


bool Observable::addObserver( Observer* observer ){
	// already here? so return false
	for each (Observer* o in observers)
	{
		if (o == observer)
			return false;
	}

	// no, so push_back the observer
	observers.push_back(observer);
	return true;
}


bool Observable::removeObserver(Observer* observer ){
	// if observer found so erase observer from observers and return true

	for(auto o = observers.begin(); o != observers.end(); o++)
	{
		if (*o == observer) {
			observers.erase(o);
			return true;
		}
	}

	// if observer not found ->
	return false ;
}


void Observable::notifyStateChange(){
	notifyStateChange(this);
}


void Observable::notifyStateChange(Observable* o){
	for each (Observer* obs in o->observers)
	{
		obs->update(o);
	}
}

