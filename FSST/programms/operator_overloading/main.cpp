// PROBLEM1 ist aktiviert und PROBELM2 ist noch deaktiviert
//
// g++ t_mystring.cpp -o t_mystring.exe
// ./t_mystring.exe
// alles scheint zu funktionieren
// ABER:
// wir haben vergessen, den Destruktor zu schreiben
// TODO:
// Destruktor programmieren
//
// PROBLEM1
// Fragen:
// 1. warum passiert ein Fehler ? weil der Konstructor MyString(MyString) nicht existiert -> pointer zeigt auf das selbe object wie das zu kopierende
// 2. wie löst man das Problem ?
// Lösung:
// copy constructor erstellen
//
// PROBLEM2
// Fragen:
// 1. warum passiert ein Fehler ? weil der operator = falsch definiert ist -> pointer zeigt auf das selbe object wie das zu kopierende
// 2. wie löst man das Problem
// Lösung:
// = operator neu schreiben
//



#include <iostream>
#include <cstring>

using namespace std;

class MyString {
private:
    char* s;
    int size;
public:
    MyString(const char* s) {
        this->size = strlen(s); //object pointer hat zugang zu privat members, in size wird die länge von string gespeichert, this braucht man nicht weil man keine andere lokale variable mit dem namen hat
        this->s = new char[size + 1]; //neuer array wurde erstellt, da braucht man this schon weil ein lokales s schon gibt
        strcpy(this->s, s); //der string das im object übergeben wurde, wird jetzt auch in den member pointer gesetzt. wir haben ein memeber char* und lokal char*
    }

    MyString(MyString &other) { //referenz damit das original benutzt wird
        this->size = other.size; //links size ist das neue size, rechts alte
        s = new char[size + 1]; //wir haben jetzt 2 mal char array aber auf unterschiedlichen speicherstellen
        strcpy(s, other.s);    //s sind nun 2 cchar arrays aber auf unterschieldicchen speicher stellen
    }

    void operator= (MyString &other) {
        size = other.size;
        s = new char[size + 1];
        strcpy(s, other.s);
    }

    friend ostream& operator<<(ostream& o, const MyString& e) { //damit wir ostream object überschrieben können, muss es friend sein
        o << e.s; //stream = bytefolge
        return o; //überladen weil ccout kann nicht objekte einfach ausgeben. Deswegen sagen wir ihm was er vom object ausgeben soll
    }

    ~MyString() { delete[](s); } //Bei problem 1. beim freigeben, bleiben die pointer noch da. Wenn jetzt ein anderes programm drauf zugreift, error -> man kann einen speicher nicht extern verwenden wenn schon ein anderer pointer drauf ist
                                 //der speicher wird nicht gelöscht sondern nur freigegeben, damit es wieder überschrieben werden kann
                                //wenn es freigegeben wird,kann man nicht mehr davon lesen, bis etwas neues rein kommt.

     char& operator[] (int i){ //mit der referenz können wir den char array überarbeiten mit sglobal1[1] = 5; wenn keine referenz, dann heisst es, es ist eine copie von G
     return s[i];
     }
};

//globs
MyString sglobal1("SGLOBAL1");
MyString sglobal2("SGLOBAL2");

// funcs
void dowhat(void) {
    // Problem 1 ??????????????????????
    MyString slocal1(sglobal1); //wir haben 2 pointer vom gleichen wert, unterschiedlichen addresen, also char von object local ist gleich wie objecct global, aber halt unterschiedlich adressen
    cout << "slocal1= " << slocal1 << endl;
    // Problem 2 ??????????????????????
    sglobal2 = slocal1;
}

int main() {
   dowhat();
    cout << "sglobal1= " << sglobal1 << endl;
    cout << "sglobal2= " << sglobal2 << endl;
    cout << sglobal1[1] << endl;
    return 0;
}
