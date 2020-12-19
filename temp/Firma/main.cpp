// a.hofmann, 2018

#include "cperson.h"
#include "carbeiter.h"
#include "cmanager.h"
#include "cverkaeufer.h"
#include "CStudent.h"
#include "cabteilung.h"

#include <iostream>
using namespace std;


int main(int argc, char *argv[])
{

    // verschiedene Personenobjekte erstellen
    CArbeiter *ich= new CArbeiter(50, "WorkerMaxi", 20, 10.0);
    CManager *sie= new CManager(40, "ManagerMaxi", 9.0);
    CVerkaeufer *er= new CVerkaeufer(40, "VerkaeuferMaxi", 40, 9.0, 9, 11.0);
	CStudent* stud= new CStudent(22,"Maxi Studiosi", 200, 20.0);
	 


    // ein Abteilungsobjekt erstellen und die Personenobjekte einfügen
    CAbteilung* abteilung= new CAbteilung("Programmierer-Abteilung");

    abteilung->addMitarbeiter(ich);
    abteilung->addMitarbeiter(sie);
    abteilung->addMitarbeiter(er);
    abteilung->addMitarbeiter(stud);

    cout << abteilung->toString() << endl;

    cout<< "\nDIE verschiedenen MITARBEITER erhalten in Summe= ";
    cout<< abteilung->getGesamtGehalt() << " EURO" << endl;


    cout <<endl;

    delete ich;
    delete sie;
    delete er;
    delete stud;
	 
    delete abteilung;

    return 0;

}

