#include "observable.h"


Observable::Observable(string name ) : name(name){}
string Observable::getName() {return name;}


bool Observable::addObserver( Observer* observer ){
	// already here? so return false
	// ?????????????????????

	// no, so push_back the observer
	//?????????????????????

	return true;
}

/* to shorten this course; not yet to implement
bool Observable::removeObserver(Observer* observer ){
	// if observer found so erase observer from observers and return true
	// ???????????????????????

	// if observer not found ->
	return false ;
}
*/

void Observable::notifyStateChange(){
	 // call for each observer in observers the update(????) method
	 
	 //pattern
	 // ENTER CODE
	 
}

