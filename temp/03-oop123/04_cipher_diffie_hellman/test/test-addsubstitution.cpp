/*	
test-xorsubstitution.cpp

Übersetzen:
g++ test-addsubstitution.cpp addsubstitution.cpp cipher.cpp -o addsubstitution.exe

Das Programm kann zum Beispiel folgendermaßen aufgerufen werden.

$ ./test-addsubstitution.exe
[ 95,124,-125,-125,-122,67,55,-114,-122,-119,-125,123,56 ]
true
*/

#include <string>

#include "addsubstitution.h"

#include <cstdio>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    string plainText = "Hello, world!";
    int key = 23;

    Cipher *cipher = new ADDSubstitution();
    string cryptText = cipher->encrypt(plainText, key);

    /*	
Die Bytes des verschlüsselten Textes werden auf der Konsole gezeigt. In der Regel kann dieser String nicht lesbar ausgegeben werden, weil bei der Verschlüsselung nichtdruckbare Zeichen entstehen.
*/
    cout << "[ ";
    for (int i = 0; i < cryptText.size() - 1; i++)
    {
        cout << (int)cryptText[i] << ",";
    }
    cout << (int)cryptText[cryptText.size() - 1];
    cout << " ]" << endl;

    /*
Schließlich wird der Geheimtext wieder dechiffriert und zur Kontrolle mit dem ursprünglichen Klartext verglichen. Die Ausgabe müsste true lauten:
*/
    string decoded = cipher->decrypt(cryptText, key);

    if (plainText == decoded)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    delete cipher;

    return 0;
}
