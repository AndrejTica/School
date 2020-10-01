#include <iostream>
#include <string>

using std::cout;
using std::endl;
// Funktionstemplate zum Tauschen von Werten beliebigen Datentyps
// ==============================================================
template <typename T>
void Swap(T& val1, T& val2){
T temp(val1);
val1 = val2;
val2 = temp;
}
// Funktionstemplate zum Sortieren von Zahlen
// beliebigen Datentyps innerhalb eines Feldes
// ===========================================
// pValues ist der Zeiger auf den Beginn des Datenfeldes
// und noOfValues enthaelt die Anzahl der Daten
template <typename T>
void Sort(T pValues, int noOfValues){
bool changed;
// Tauschflag
// Tauschschleife
do
{
// Tauschflag loeschen
changed = false;
// Alle Elemente vergleichen
for (int index=0; index<noOfValues-1; index++)
{
// Falls getauscht werden muss
if (pValues[index]>pValues[index+1])
{
// Werte tauschen
Swap(pValues[index],pValues[index+1]);
// Tauschflag setzen
changed = true;
}
}
} while (changed);
// Schleife so lange durchlaufen, bis nicht mehr getauscht wurde
}

class Address {

    std::string name;
    std::string location;

public:
    Address(){}
    Address(const Address& x)
    {
        this->name = x.name;
        this->location = x.location;
    }
    Address& operator=(const Address& x)
    {
        this->name = x.name;
        this->location = x.location;
        return *this;
    }
    bool operator>(const Address& x) const{
        return this-> name > x.name;
    }
    void SetData(const char* const pN, const char* const pL);
    friend std::ostream& operator << (std::ostream& os, const Address& obj2);


};

void Address::SetData(const char* const pN, const char* const pL){
    name = pN;
    location = pL;
}

std::ostream& operator << (std::ostream& os, const Address& obj2){
os << "Name: " << obj2.name;
os << " Ort: " << obj2.location << endl;
return os;
}

//
// HAUPTPROGRAMM
// =============
int main()
{
int
index;
// Objektfeld fuer Adressdaten anlegen
const int SIZE = 4;
Address *pAddress = new Address[SIZE];
// Objektfeld mit Daten belegen
pAddress[0].SetData("Karl Maier","AStadt");
pAddress[1].SetData("Agathe Mueller","XDorf");
pAddress[2].SetData("Xaver Lehmann","CHausen");
pAddress[3].SetData("Berta Schmitt","FStadt");
// unsortiertes Objektfeld ausgeben
cout << "Unsortierte Adressen:\n";
for (index=0; index<SIZE; index++)
cout << pAddress[index] << endl;
// Hier fuer die Uebung die Adressen sortieren und
Sort<Address*>(pAddress, SIZE);
// erneut ausgeben
for(index=0; index < SIZE; index++)
    cout << pAddress[index] << endl;
delete [] pAddress;
return 0;
}
