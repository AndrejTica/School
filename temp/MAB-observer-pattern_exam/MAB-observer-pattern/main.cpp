#include "observer.h"
#include "observable.h"

int main(){

	 Observer observer1("Thief the looker");
	 Observer observer2("police man");
	 Observer observer3("Thief the taker");
	 
	 Observable observable("Jewelry Store");
	 
	 observable.addObserver(&observer1);
	 observable.addObserver(&observer2);
	 observable.addObserver(&observer3);
	 
	 observable.notifyStateChange();

	 return 0;
}

/*
 * output
Observer: update() wurde aktiviert ..........
   ...... ich (Thief the looker) beobachte: Jewelry Store
Observer: update() wurde aktiviert ..........
   ...... ich (police man) beobachte: Jewelry Store
Observer: update() wurde aktiviert ..........
*/
