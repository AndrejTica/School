// ahofmann, 2017
// mab-intarray.cpp (6)

#include <iostream>
using namespace std;

// #include "intarray.h"

#include <sstream>
using namespace std;

class Intarray{
	private:
        int* a;
        int size;
public:
	// Konstruktoren
	Intarray(int size=100, int value=99);	 	// 100 mal 99
	Intarray(const Intarray& other);  			// Copy cons !!!!!
	Intarray(int* p, int len);		  			// Typ-conv cons !!!!!

	// Destructor
	~Intarray();

	// mab
	void append(int* p, int len);
	Intarray* getSubArray( int index);

	string toString() const;	
};

Intarray::Intarray(int size, int value){
	????????????????
}

Intarray::Intarray(const Intarray& other){
	????????????????
}

Intarray::Intarray(int* p, int len){
	????????????????
}

Intarray::~Intarray(){
	????????????????
}

void Intarray::append(int* p, int len){
	????????????????
}

Intarray* Intarray::getSubArray( int index){
	????????????????
}
string Intarray::toString() const{
	????????????????
}


int main(){
	Intarray a2(5,9);	// 5 Stück mit Wert 9		// A (1)
	Intarray a3(a2);	// copy cons				// B (1)
	int feld[5]={1,2,3,4,5};
	
	Intarray* pa2;
	
	cout<<"a2= ..." <<endl;
	cout<< a2.toString();							// C (1)
		
	a2.append(feld,5);								// D (3)
	cout<<"a2= ..." <<endl;
	cout<< a2.toString();		// gibt 9,9,9,9,9,1,2,3,4,5
	
	pa2= a2.getSubArray(5);		// ab index 5		// E (3)
	cout<<"pa2= ..." <<endl;
	cout<< pa2->toString();   	// gibt 1,2,3,4,5 aus
	
	delete pa2;
	
	cout << endl<<endl;
	return 0;
}
/* Ausgabe:
a2= ...
9,9,9,9,9,
a2= ...
9,9,9,9,9,1,2,3,4,5,
pa2= ...
1,2,3,4,5,
*/
