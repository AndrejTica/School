#pragma once

#include "item.h"

// sub classes 
class Jewel : public Item {  // ENTER CODE
  private:
    double raw_material_value;
  public:
    Jewel(string name, double weight, double raw_material_value);
    
    string toString() const override;
   
    // ENTER CODE
    // value= raw_material_value*weight
    
};
