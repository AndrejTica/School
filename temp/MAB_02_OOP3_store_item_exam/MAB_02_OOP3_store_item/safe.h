#pragma once

#include "item.h"

class Safe : public Item
{ // ENTER CODE
private:
  double content_value;

public:
  Safe(string name, double weight, double content_value);
  string toString() const override;

  // ENTER CODE
  // value= content_value - weight

};
