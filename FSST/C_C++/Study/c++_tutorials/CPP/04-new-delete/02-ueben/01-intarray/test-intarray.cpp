// ahofmann, 2016
// test-intarray.cpp

#include <iostream>
using namespace std;

#include "intarray.h"

int main(){
	Intarray a1; 		// def. cons
	Intarray a2(10,9);	// 10 Stück mit Wert 9
	Intarray a3=a2;  	// copy cons
	//Intarray a3(a2);
	int feld[5]={1,2,3,4,5};
	Intarray a4(feld, 5);	// typ-Umwandlungs-cons
	
	Intarray* pa2;
	
	cout<<"a1= ..." <<endl;
	cout<< a1.toString();
	
	cout<<"a2= ..." <<endl;
	cout<< a2.toString();
	
	cout<<"a3= ..." <<endl;
	cout<< a3.toString();
	
	cout<<"a4= ..." <<endl;
	cout<< a4.toString();
	
	a4.setAt(1,4711);
	cout<<"a4= ..." <<endl;
	cout<< a4.toString();
	
	a4.append(a2);
	cout<<"a4= ..." <<endl;
	cout<< a4.toString();
	
	pa2= a2.clone();
	cout<<"pa2= ..." <<endl;
	cout<< pa2->toString();
	delete pa2;
	

	cout << endl<<endl;
	return 0;
}
