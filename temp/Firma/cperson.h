// a.hofmann 2010
// cperson.h

#ifndef CPERSON_H
#define CPERSON_H

#include <string>
using namespace std;


class CPerson{
    private:
        // Private member. NIEMAND darf direkt drauf zugreifen
           int alter;

           // Protected member.
           // NUR Unterklassen dürfen direkt drauf zugreifen
        protected:
            string name;

    public:
           // Konstruktor
           CPerson(int alter, string name);

           // Zugriffsmethoden
           int getAlter() const;

           // virtuelle Methoden
           virtual double getGehalt() const {return 0.0;};

           virtual string toString() const;
};
#endif
