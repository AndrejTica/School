// MEILENSTEIN-CPP-u_mystring.cpp
//
// PROBLEM1 ist aktiviert und PROBELM2 ist noch deaktiviert
//
// g++ MEILENSTEIN-CPP-u_mystring.cpp -o MEILENSTEIN-CPP-u_mystring.exe
// ./MEILENSTEIN-CPP-u_mystring.exe
//
// alles scheint zu funktionieren
// ABER:
// wir haben vergessen, den Destruktor zu schreiben
// TODO:
// Destruktor programmieren
// 
// PROBLEM1 
// Fragen:
// 1. warum passiert ein Fehler ?
// 2. wie löst man das Problem
// Lösung:
// ?????????????????????
//
// PROBLEM2 
// Fragen:
// 1. warum passiert ein Fehler ?
// 2. wie löst man das Problem
// Lösung:
// ?????????????????????
//
#include <iostream>
#include <cstring>
using namespace std;

class MyString{
	private:
		char* s;
		int size;
	public:
		MyString(const char* s){
			this->size= strlen(s);
			this->s= new char[size+1];
			strcpy(this->s, s);
		}		
		friend ostream& operator<<(ostream& o, const MyString& e){
			o << e.s;
			return o;
		}
};

//globs
MyString sglobal1("SGLOBAL1");
MyString sglobal2("SGLOBAL2");

// funcs
void dowhat(void){
// Problem 1 ??????????????????????
	MyString slocal1(sglobal1);	
	cout << "slocal1= " << slocal1 << endl;
// Problem 2 ??????????????????????
//	sglobal2= slocal1;
}

int main(){
	dowhat();
	cout << "sglobal1= " <<sglobal1 << endl;
	cout << "sglobal2= " <<sglobal2 << endl;
	return 0;
}
