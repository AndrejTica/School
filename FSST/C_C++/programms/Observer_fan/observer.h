#ifndef OBSERVER_H_INCLUDED
#define OBSERVER_H_INCLUDED

//#include "observable.h"
class Observable;

#include <iostream>
using namespace std;

class Observer
{
public:
    Observer();
    virtual void update() = 0;
    virtual void update(Observable* o) = 0;

};


#endif // OBSERVER_H_INCLUDED
