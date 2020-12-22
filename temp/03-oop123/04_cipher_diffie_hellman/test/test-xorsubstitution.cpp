/*	
test-xorsubstitution.cpp

Übersetzen:
g++ test-xorsubstitution.cpp xorsubstitution.cpp cipher.cpp -o xorsubstitution.exe

Das Programm kann zum Beispiel folgendermaßen aufgerufen werden.

$ ./test-xorsubstitution.exe
[95, 114, 123, 123, 120, 59, 55, 96, 120, 101, 123, 115, 54]
true
*/

#include <string>

#include "xorsubstitution.h"

#include <cstdio>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	string plainText = "Hello, world!";
	int key = 23;

	Cipher *cipher = new XORSubstitution(); //objekt von XORsubs. Cipher ist abstrackt davon nix erben. Bei new wählt man welche klasse man will
	string cryptText = cipher->encrypt(plainText, key); //hier bekommen wir einen verschlüsselten text zurück

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
		cout << "false" << endl; //bei false ist ein fehler passiert

	delete cipher;

	return 0;
}
