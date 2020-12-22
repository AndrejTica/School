#pragma once

#include <string>
using namespace std;

// ---------------------------
// abstract class (for Polymorphism)
class Item {
  private:
    string name;
    double weight;
  public:
    Item(string name, double weight);
    double getWeight() const { return weight; }
    
    virtual string toString() const;

    // ENTER CODE


};
