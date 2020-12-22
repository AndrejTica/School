/*	
test-streamcipher.cpp

Übersetzen:
g++ test-streamcipher.cpp streamcipher.cpp xorsubstitution.cpp cipher.cpp -o test-streamcipher.exe

Das Programm kann zum Beispiel folgendermaßen aufgerufen werden.

$ ./test-streamcipher.exe
[ 70,-5,114,-2,-9,-14,0,36,-128,85,94,57,-3 ]
true
*/

#include <string>

#include "streamcipher.h"

#include <cstdio>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	string plainText = "Hello, world!";
	int key = 23;

	Cipher* cipher = new StreamCipher(); //base class pointer, diesmal wähle ich streamcipher, overrode, weil zeiger zeigt drauf. Cipher ist nur der rückgabe wer
	//StreamCipher* cipher = new StreamCipher(); // 
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
