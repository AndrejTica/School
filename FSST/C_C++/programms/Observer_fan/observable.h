#ifndef OBSERVABLE_H_INCLUDED
#define OBSERVABLE_H_INCLUDED

#include "observer.h"

#include <vector>
using namespace std;

class Observable{

private:
    vector<Observer*> observers;
public:
        Observable();
        bool addObserver(Observer* observer);
        bool removeObserver(Observer* observer);
        void notifyStateChange();
        void notifyStateChange(Observable* o);
};

#endif // OBSERVABLE_H_INCLUDED
