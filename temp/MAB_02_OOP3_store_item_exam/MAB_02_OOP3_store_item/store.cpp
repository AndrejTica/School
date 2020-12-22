#include "store.h"


// ---------------------------
Store::Store(string name) : name(name){}


void Store::addItem(Item* item){
  items.push_back(item);
}

double Store::getTotalValue() const{
  double value = 0.0;

  // ENTER CODE

  return value;
}

double Store::getTotalWeight() const{
  double value = 0.0;

  // ENTER CODE

  return value;
}


string Store::toString() const{
  string ret="STORE: " + name + "\n";

  // ENTER CODE
  for(auto i : items){
    ret += i->toString()+"\n";
  }

  return ret;
}
