/*	
test-diffie-hellman.cpp

Übersetzen:
g++ test-diffie-hellman.cpp cipher.cpp xorsubstitution.cpp streamcipher.cpp -o test-diffie-hellman.exe

Das Programm kann zum Beispiel folgendermaßen aufgerufen werden.

$ ./test-diffie-hellman.exe
[ 95,124,-125,-125,-122,67,55,-114,-122,-119,-125,123,56 ]
true
*/

#include <string>

#include "dhcipher.h"

#include <cstdio>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    // ------------- DHCipher -------------------------------
    string plainText = "Hello, world!";

    cout << "DIFFIE-HELLMAN..." << endl;
    int n = 5;
    int g = 23;

    DHCipher *alice = new DHCipher(n, g);
    DHCipher *bob = new DHCipher(n, g);

    // ALICE encrypt

    string cryptText = alice->encrypt(plainText, bob->getPublicKey());

    cout << "[ ";
    for (unsigned int i = 0; i < cryptText.size() - 1; i++)
    {
        cout << (int)cryptText[i] << ",";
    }
    cout << (int)cryptText[cryptText.size() - 1];
    cout << " ]" << endl;

    // BOB decrypt

    string decoded = bob->decrypt(cryptText, alice->getPublicKey());

    if (plainText == decoded)
        cout << "true" << endl;
    else
        cout << "false" << endl;
	 
	 delete alice;
	 delete bob;

    return 0;
}
