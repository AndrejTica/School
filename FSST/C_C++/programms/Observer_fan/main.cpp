/*
Der Observer (Beobachter, Listener) ist ein Entwurfsmuster aus dem Bereich der
Softwareentwicklung. Es dient zur Weitergabe von Änderungen an einem Objekt an
von diesem Objekt abhängige Objekte.
Dieses Entwurfsmuster ist auch unter dem Namen publish-subscribe bekannt,
frei übersetzt veröffentlichen und abonnieren.

Im unteren Beispiel: Die 2 Vereine werden von Fans und der APA beobachtet.
*/

#include <iostream>

#include "fanclub.h"
#include "presseagentur.h"

#include "fussballverein.h"

using namespace std;

int main() {
        cout << "Demo: ANWENDUNG: Beobachter-Muster!!!" << endl<<endl;

        Fanclub* fan1= new Fanclub("Fanclub Wiesn");    //needs to be pointer, cuz we passing a pointer to the object into vector when adding, doesnt need to be on heap tho
        Fanclub* fan2= new Fanclub("Fanclub Wald und Wiesn");
        Fanclub* fan3= new Fanclub("Fanclub Schwabenwald");
        Presseagentur* apa= new Presseagentur("Austria Presse Agentur");


       // Fanclub* fan4;
       // fan4 = &Fanclub("Hi");

        Fussballverein* bayern= new Fussballverein("FC Bayern");
        Fussballverein* stuttgart= new Fussballverein("VfB Stuttgart");

        bayern->addObserver(fan1);
        bayern->addObserver(fan2);
        bayern->addObserver(apa);

        stuttgart->addObserver(fan3);

        cout<< "!!! Hey, bei Bayern tut sich was ............"<<endl;
        bayern->setPresseMitteilung("FC Bayern ist Meister!!!");    //weil bayern 3 observer hat wird 3 mal die update methode in setPresse methode aufgerufen


        cout<< endl<<"!!! Hey, bei Stuttgart tut sich was ............"<<endl;
        stuttgart->setPresseMitteilung("VfB Stuttgart ist zweiter!!!");

        delete fan1;
        delete fan2;
        delete fan3;
        delete apa;
        delete bayern;
        delete stuttgart;

        cout <<endl<<endl;
        return 0;
}


/*
Demo: ANWENDUNG: Beobachter-Muster!!!
!!! Hey, bei Bayern tut sich was ............
FANCLUB: [Fanclub Wiesn] bin aktiviert worden.
    M I T T E I L U N G: <FC Bayern ist Meister!!!>

FANCLUB: [Fanclub Wald und Wiesn] bin aktiviert worden.
    M I T T E I L U N G: <FC Bayern ist Meister!!!>

PRESSE: [Austria Presse Agentur] bin aktiviert worden.
    P R E S S E M I T T E I L U N G: <FC Bayern ist Meister!!!>

!!! Hey, bei Stuttgart tut sich was ............
FANCLUB: [Fanclub Schwabenwald] bin aktiviert worden.
    M I T T E I L U N G: <VfB Stuttgart ist zweiter!!!>

*/





