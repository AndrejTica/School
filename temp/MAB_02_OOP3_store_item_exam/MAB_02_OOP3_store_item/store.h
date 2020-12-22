#pragma once

#include <vector>
#include <string>
using namespace std;

#include "item.h"

class Store
{
private:
  string name;

  // ENTER CODE

public:
  Store(string name);

  // ENTER CODE


  double getTotalValue() const;
  double getTotalWeight() const;

  string toString() const;
};
