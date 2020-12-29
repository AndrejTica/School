// u-templateMatrix.cpp
// name: ???????????????
//
// Bringen Sie dieses Programm zum Laufen
//

#include <iostream>
using namespace std;


// class matrix as template class
#include "matrix.h"


int main(){

	Matrix<double> m(5,5);

	m(1,1)=5.9;

	cout << m << endl;

	return 0;
}

