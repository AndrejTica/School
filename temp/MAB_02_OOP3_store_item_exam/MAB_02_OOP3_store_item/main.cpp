/*
DEMO: 
OOP with cpp (Polymorphism using base-class-pointer and pure virtual functions)

class Store ... has many different Items (acts as a container)

List of Items:
- class Item ... base-class holds: double weight; string name; 
  - class Jewel ... value= raw_material_value*weight
  - class Watch ... value= weight* price*manufacturer_factor)  
                        (Omega=1.2, else 1.0)
  - class Safe ... value= content_value - weight
*/

#include <vector>
#include <iostream>
#include <string>
using namespace std;

#include "store.h"

#include "jewel.h"
#include "watch.h"
#include "safe.h"

int main()
{
  // Items

  //10 gram, 20.0 euro
  Item *ear_ring = new Jewel("Ear Ring", 10.0, 20.0);

  //150 gram, 2000.0 euro, Omega
  Item *watch = new Watch("Seamaster", 150.0, 2000.0, "Omega");

  // 5000 gram, 20000 euro
  Item *safe = new Safe("Big Safe", 5000.0, 20000.0);

  // store
  Store *store = new Store("Jewelry Store unlimited");

  // add items
  store->addItem(ear_ring);
  store->addItem(watch);
  store->addItem(safe);

  // print
  cout << "store: total value: " << store->getTotalValue() << endl;
  cout << "store: total weight: " << store->getTotalWeight() << endl;

  // shutdown
  delete ear_ring;
  delete watch;
  delete safe;

  return 0;
}

/*
output:

store: total value: 15200
store: total weight: 5160

*/
