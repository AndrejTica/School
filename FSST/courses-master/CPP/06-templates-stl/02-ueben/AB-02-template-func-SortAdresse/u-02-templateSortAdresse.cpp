// N.N
// templateSortAdresse.cpp
// Array mit Addressobjekten sortieren
//
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
    bool changed;       // Tauschflag

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

// Definition der Klasse fuer die Adressdaten
class Address{
    std::string name;           // Name
    std::string location;       // Ort
public:
    Address()              // ctor, hat nichts zu tun
    {}
    void SetData(const char* const pN, const char* const pL);
    friend std::ostream& operator << (std::ostream& os, const Address& obj2);
};

// Definition der Memberfunktionen
// Setzen der Objektdaten
void Address::SetData(const char* const pN, const char* const pL){
    name = pN;
    location = pL;
}

// Ueberladener Operator << fuer Ausgabe
std::ostream& operator << (std::ostream& os, const Address& obj2){
    os << "Name: " << obj2.name;
    os << "  Ort: " << obj2.location << endl;
    return os;
}

//
// HAUPTPROGRAMM
// =============
int main()
{
    int     index;

    // Array fuer Adressdaten Objekte anlegen
    const int SIZE = 4;
    Address *pAddress = new Address[SIZE];

    // Objektfeld mit Daten belegen
    pAddress[0].SetData("Karl Maier","AStadt");
    pAddress[1].SetData("Agathe Mueller","XDorf");
    pAddress[2].SetData("Xaver Lehmann","CHausen");
    pAddress[3].SetData("Berta Schmitt","FStadt");

    // Array unsortiert ausgeben
    cout << "Unsortierte Adressen:\n";
    for (index=0; index<SIZE; index++)
        cout << pAddress[index] << endl;

    // Adressen sortieren und
    // erneut ausgeben
    // ????????????????????????????????????????????????


    delete [] pAddress;
    return 0;
}
