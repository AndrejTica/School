// a.hofmann, 2007
// carbeiter.h
// Vererbung

#include <string>
#include "cperson.h"


#ifndef CARBEITER
#define CARBEITER

class CArbeiter : public CPerson
{
        private:
            int stunden;
            double stundenLohn;

        public:
            // Konstruktor
            CArbeiter( int alter, string name,
                            int stunden, double stundenLohn );

            // Zugriffsmethoden
     //       int getAlter() const;

            string toString()const;

            double getGehalt() const;
};
#endif
