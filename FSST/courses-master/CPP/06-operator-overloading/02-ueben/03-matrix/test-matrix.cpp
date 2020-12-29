// test-matrix.cpp
// NAME
// 2013

#include <iostream>
using namespace std;

#include "matrix.h"


int main(){
	Matrix a(3,3), b(3,3), c(3,3);

	cout << "\nLINE " << __LINE__ << ":\n";
	cout << "*** der operator() der Klasse Matrix ***" <<endl;
	cout << "------------------------------------------------" << endl;
	a(0,0) = 10.0;	a(1,1) = 100.0;	a(2,2) = 1000.0;
	cout << a << endl;


	cout << "\nLINE " << __LINE__ << ":\n";
	cout << "*** der operator* der Klasse Matrix ***" <<endl;
	cout << "------------------------------------------------" << endl;
	a(0,0)=1.0;	a(0,1)=2.0;	a(0,2)=0.0;
	a(1,0)=2.0;	a(1,1)=1.0;	a(1,2)=0.0;
	a(2,0)=0.0;	a(2,1)=1.0;	a(2,2)=1.0;
	b(0,0)=1.0;	b(0,1)=2.0;	b(0,2)=1.0;
	b(1,0)=0.0;	b(1,1)=1.0;	b(1,2)=1.0;
	b(2,0)=2.0;	b(2,1)=1.0;	b(2,2)=0.0;

	c= a * b;   //Matrixmultiplikation
	cout << "*** Matrixmultiplikation ***" << endl;
	cout << "*** a=\n" << a << endl;
	cout << "*** b=\n" << b << endl;
	cout << "*** c=\n" << c << endl;


	cout << "\nLINE " << __LINE__ << ":\n";
	cout << "*** der operator+ der Klasse Matrix ***" <<endl;
	cout << "------------------------------------------------" << endl;
	c= a + b;   //Matrixaddition
	cout << "*** a=\n" << a << endl;
	cout << "*** b=\n" << b << endl;
	cout << "*** c=\n" << c << endl;

	cout << endl<<endl;
	return 0;
} //main
