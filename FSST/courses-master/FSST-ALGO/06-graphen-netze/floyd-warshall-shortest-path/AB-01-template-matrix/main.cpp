#include "matrix.h"

#include <iostream>
using namespace std;


int main(){

	Matrix<double> a(3,3);
	Matrix<double> b(3,3);
	Matrix<double> c(3,3);

	a(0,0)=0; a(0,1)=0;a(0,2)=0;
	a(1,0)=1; a(1,1)=1;a(1,2)=1;
	a(2,0)=2; a(2,1)=2;a(2,2)=2;

	b(0,0)=0; b(0,1)=0;b(0,2)=0;
	b(1,0)=1; b(1,1)=1;b(1,2)=1;
	b(2,0)=2; b(2,1)=2;b(2,2)=2;


	cout << "a= " << endl;
	cout << a << endl;

	cout << "b= " << endl;
	cout << b << endl;

	cout << "c= " << endl;
	cout << c << endl;


	c= a*b;
	cout << "c= a * b; " <<endl;
	cout << "c= " << endl;
	cout << c << endl;

	return 0;
}

