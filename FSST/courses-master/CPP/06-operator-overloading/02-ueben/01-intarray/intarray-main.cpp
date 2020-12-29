/** Überladen von Operatoren (intarray.h/intarray.cpp)
 * @name
 * @file
 * @date
 * @description

 * OPERATOR OVERLOADING

    Intarray(const Intarray&);// Kopierkonstruktor
    ~Intarray(); //Destruktor
    
    bool operator==(const Intarray&);
    bool operator>(const Intarray&);
    
    Intarray& operator<<(const Intarray&); //  (append) ??????
    
    friend ostream& operator<< (ostream& o , const Intarray&);
    
    int& operator[](int i); // ia[2]=99;
    int operator[](int i) const;  // int x= ia[2];
    
    Intarray& operator=(const Intarray& other);
    Intarray operator+(const Intarray& other); //vgl. append

*/

#include <iostream>
using namespace std;

#include "intarray.h"



int main(){
//Konstruktoren
	Intarray ia(10),  ib(10);

	int a[]= {1,2,3};
	int b[]= {3,2,1};
	Intarray ta(a,3), tb(b,3);
	

cout << "\n\nLINE: " <<__LINE__ <<": " <<"*** operator<< ueberladen ****" <<endl;
cout << "-----------------------------------------------------------" <<endl;
//friend operator<< (ostream o , IntArray&)
	cout << "ia= " << endl;
	cout << ia;



cout << "\n\nLINE: " <<__LINE__ <<": "  <<"*** operator== ueberladen ****" <<endl;
cout << "-----------------------------------------------------------" <<endl;
// operator==
	if (ia == ib){
		cout << "ia ist gleich ib" << endl;
	}else{
		cout << "ia ist NICHT gleich ib" << endl;
	
	}
	cout << "ia= " << endl;
	cout << ia;
	cout << "ib= " << endl;
	cout << ib;

cout << "\n\nLINE: " <<__LINE__ <<": "  <<"*** operator> ueberladen ****" <<endl;
cout << "-----------------------------------------------------------" <<endl;
// MAB: > Operator überladen
	if (ta > tb){ // zB: (3,2,1) ist groesser als (1,2,3)
		cout << "ta ist groesser als tb" << endl;
	}else{
		cout << "ta ist NICHT groesser als tb" << endl;
	}
	cout << "ta= " << endl;
	cout << ta;
	cout << "tb= " << endl;
	cout << tb;
	

cout << "\n\nLINE: " <<__LINE__ <<": "  <<"*** operator= ueberladen ****" <<endl;
cout << "-----------------------------------------------------------" <<endl;
// Der Zuweisungsoperator =
	Intarray z1(10,1),  z2(5,2);  // 10 Elemente mit 1 initialisiert
	cout << "z1= " << endl;
	cout << z1;
	cout << "z2= " << endl;
	cout << z2;

	z1= z2;
	cout <<"nach der Zuweisung: z1= z2" <<endl;
	cout << "z1= " << endl;
	cout << z1;
	cout << "z2= " << endl;
	cout << z2;

	cout <<"nach der Zuweisung: z1= z1" <<endl;
	cout << "z1= " << endl;
	cout << z1;


cout << "\n\nLINE: " <<__LINE__ <<": "  <<"*** KopierKONSTRUKTOR ****" <<endl;
cout << "-----------------------------------------------------------" <<endl;
	Intarray z3(z1);
	cout <<"nach Intarray z3(z1);" <<endl;
	cout << "z1= " << endl;
	cout << z1;
	cout << "z3= " << endl;
	cout << z3;

	
cout << "\n\nLINE: " <<__LINE__ <<": "  <<"*** operator[] ueberladen ****" <<endl;
cout << "-----------------------------------------------------------" <<endl;
	int x= z3[0];
	cout <<"nach int x= z3[0];" <<endl;
	cout << "x= " << x << endl;
	
	z3[0]= 99;
	cout <<"nach z3[0]= 99;" <<endl;
	cout << "z3= " << endl;
	cout << z3;
	
cout << "\n\nLINE: " <<__LINE__ <<": "  <<"*** operator+ ueberladen ****" <<endl;
cout << "-----------------------------------------------------------" <<endl;
	Intarray tc;
	cout << "ta= " << endl;
	cout << ta;
	cout << "tb= " << endl;
	cout << tb;
	
	tc= ta+tb; // elementweise addieren
	cout <<"nach tc= ta+tb;" <<endl;
	cout << "tc= " << endl;
	cout << tc;
	
	cout <<endl<<endl;
	return 0;
}

// mab-termin: ?
