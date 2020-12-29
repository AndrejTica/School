// ANLAGE matrix.h
// see: http://msdn.microsoft.com/en-us/library/f1b2td24.aspx
#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <sstream>
#include <stdexcept>
using namespace std;

// forward decl and // decl of c-func
template <typename T> class Matrix;
template <typename T> ostream& operator<< ( ostream& o, const Matrix<T>& other);

// the class 
template <typename T>
class Matrix{
private:
	T** matrix_;
	unsigned irows_;
	unsigned icols_;
public:
	Matrix(int irows=3, int icols=3);
	Matrix(const Matrix<T>& other);
	~Matrix();

	friend ostream& operator<< <>( ostream& o, const Matrix<T>& other);

	T& operator()(int i, int j) throw (std::out_of_range);
	T operator()(int i, int j) const throw (std::out_of_range);
	Matrix<T> operator*(const Matrix<T>& other);
	Matrix<T>& operator=(const  Matrix<T>& other);
};

// cons, destr
// -----------------------------------------------------------------------------
template <typename T>
Matrix<T>::Matrix(int irows, int icols){
	irows_= irows;
	icols_= icols;

	matrix_= new T* [irows];

	for (int i=0; i < irows_; i++){
		matrix_[i]= new T [icols_];
	}
	for (int i=0; i < irows_; i++){
		for (int j=0; j < icols_; j++){
			matrix_[i][j]= 0;
		}
	}
}

template <typename T>
Matrix<T>::Matrix(const Matrix<T>& other){
	icols_= other.icols_;
	irows_= other.irows_;

	matrix_= new T* [irows_];

	for (int i=0; i < irows_; i++){
		matrix_[i]= new T [icols_];
	}

	for (int i=0; i < irows_; i++){
		for (int j=0; j < icols_; j++){
			matrix_[i][j]= other.matrix_[i][j];
		}
	}
}

template <typename T>
Matrix<T>::~Matrix(){
	for (int i=0; i < irows_; i++){
		delete [] matrix_[i];
	}

	delete [] matrix_;
}


// operators
// -----------------------------------------------------------------------------
template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& other){
	Matrix<T> a;
	T sum;

	for(int i=0; i<irows_; i++){      
		for(int j=0; j<icols_; j++){
			sum=0;
			for (int k=0; k < icols_; k++)
				sum += matrix_[i][k] * other.matrix_ [k][j];
			a(i,j)= sum;
		}
	}
	return a;  // calls copy cons
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& other){
	if (this!= &other){
		// free memory
		for (int i=0; i < irows_; i++)
			delete [] matrix_[i];
		delete [] matrix_;

		// alloc new 
		icols_= other.icols_;
		irows_= other.irows_;

		matrix_= new T* [irows_];

		for (int i=0; i < irows_; i++){
			matrix_[i]= new T [icols_];
		}

		for (int i=0; i < irows_; i++){
			for (int j=0; j < icols_; j++){
				matrix_[i][j]= other.matrix_[i][j];
			}
		}
	}
	return *this;
}

template <typename T>
T& Matrix<T>::operator()(int i, int j) throw (std::out_of_range){
	if (i < 0 || i >= irows_) {
		ostringstream o;
		o << "\nerror:" <<__FILE__ << ":" << __LINE__ <<":";
		o << "wrong index for row: " << i << endl;
		o << *this<<endl;
		throw std::out_of_range(o.str());
	}
	else if (j < 0 || j >= icols_){
		ostringstream o;
		o << "\nerror:" <<__FILE__ << ":" << __LINE__ <<":";
		o << "wrong index for col: " << j <<  endl;
		o << *this<<endl;
		throw std::out_of_range(o.str());
	}else
		return matrix_[i][j];
}

template <typename T>
T Matrix<T>::operator()(int i, int j) const throw (std::out_of_range){
	if (i < 0 || i >= irows_) {
		ostringstream o;
		o << "\nerror:" <<__FILE__ << ":" << __LINE__ <<":";
		o << "wrong index for row: " << i << endl;
		o << *this<<endl;
		throw std::out_of_range(o.str());
	}
	else if (j < 0 || j >= icols_){
		ostringstream o;
		o << "\nerror:" <<__FILE__ << ":" << __LINE__ <<":";
		o << "wrong index for col: " << j <<  endl;
		o << *this<<endl;
		throw std::out_of_range(o.str());
	}else
		return matrix_[i][j];
}

// output
template <typename T>
ostream& operator<<( ostream& o, const Matrix<T>& other){
	for (int i=0; i < other.irows_; i++){
		for (int j=0; j < other.icols_; j++){
			o << other.matrix_[i][j] << ",";
		}
		o << endl;
	}
	return o;
}
#endif

