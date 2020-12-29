/*mab-templates-max-swap-stack.cpp
================================================================================

1. (6) (PAPIER)Erstelle die Template-Klasse Stack
--------------------------------------------------------------------------------
1.1. (6)Die Klasse Stack als template:
            private member:
                T* arr; int size; int sp;
            a) Konstruktor   b) Destruktor  c) push    d) pop

2. (6) Template Klassen/Funktionen (PROGRAMM)
--------------------------------------------------------------------------------
2.1. (2) Frage: Welche Methoden muss die Klasse Stack zusätzlich implementieren?
		 Antwort: 


2.2. (4) Bringen Sie das folgende Programm zum Laufen.*/
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

template <typename T> T& maximum( T& a, T& b){
	if (a > b) return a;
	else return b;
}
template <typename T> void swapIt( T& a, T& b){
	T h=a; a= b; b= h;
}

// ??????????? class stack als template hier einfügen ?????????????

int main(){
	Stack<int> s1(10);
	Stack<int> s2(10);
	Stack<int> s3(10);

	for (int i=1; i<=3; i++)s1.push(i);	
	for (int i=1; i<=5; i++)s2.push(i);

	cout << "Stack s1: " << s1.toString() << endl;
	cout << "Stack s2: " << s2.toString() << endl;

	s3= maximum<Stack<int> >(s1, s2);
	cout << "Groesser (=mehr Werte am Stack hat) " << s3.toString() << endl;

	swapIt<Stack<int> >(s1, s2);

	cout << "Nach dem Tauschen von s1 und s2..." <<endl;
	cout << "Stack s1: " << s1.toString() << endl;
	cout << "Stack s2: " << s2.toString() << endl;

	return 0;
}

