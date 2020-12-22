#pragma once

#include "item.h"

class Watch : public Item { // ENTER CODE
  private:
    double price;
    string manufacturer;
  public:
    Watch(string name, double weight, double price, string manufacturer);
    string toString() const override;
  
    // ENTER CODE
    // if manufacturer=="Omega" then value= weight* price* 1.2; 
    // else value= weight* price

};
