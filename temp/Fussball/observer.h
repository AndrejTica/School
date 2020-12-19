#ifndef OBSERVER_H
#define OBSERVER_H

//#include "observable.h"
class Observable;

#include <iostream>
using namespace std;

class Observer
{
public:
    virtual void update() = 0;
    virtual void update(Observable* o) = 0;
};

#endif // OBSERVER_H
