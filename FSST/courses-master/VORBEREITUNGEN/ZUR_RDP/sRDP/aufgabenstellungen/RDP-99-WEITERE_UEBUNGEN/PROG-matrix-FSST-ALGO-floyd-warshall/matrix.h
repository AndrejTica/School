// ANLAGE-TEMPLATE-MATRIX.h

#pragma once

// forward decl and // decl of c-func
template <typename T> class Matrix;
template <typename T> ostream& operator<< ( ostream& o, const Matrix<T>& other);

template <typename T>
class Matrix{ // --------------------------- class Matrix
private:
	T** matrix_;
	unsigned irows_;
	unsigned icols_;
public:
	Matrix(int irows=3, int icols=3);
	Matrix(const Matrix<T>& other);
	~Matrix();

	friend ostream& operator<< <>( ostream& o, const Matrix<T>& other);

	T& operator()(int i, int j) ;
	T operator()(int i, int j) const;
	Matrix<T> operator*(const Matrix<T>& other);
	Matrix<T>& operator=(const  Matrix<T>& other);
};

template <typename T>
Matrix<T>::Matrix(int irows, int icols){  // ---------- cons, destr
	irows_= irows;
	icols_= icols;

	matrix_= new T* [irows];
	for (int i=0; i < irows_; i++)
		matrix_[i]= new T [icols_];
	for (int i=0; i < irows_; i++)
		for (int j=0; j < icols_; j++)
			matrix_[i][j]= 0;
}

template <typename T>
Matrix<T>::Matrix(const Matrix<T>& other){
	icols_= other.icols_;
	irows_= other.irows_;
	matrix_= new T* [irows_];

	for (int i=0; i < irows_; i++)
		matrix_[i]= new T [icols_];

	for (int i=0; i < irows_; i++)
		for (int j=0; j < icols_; j++)
			matrix_[i][j]= other.matrix_[i][j];
}

template <typename T>
Matrix<T>::~Matrix(){
	?????????????????????????????????????????????????????
}

// operators
template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& other){
	Matrix<T> a;
	T sum;
	for(int i=0; i<irows_; i++){      
		for(int j=0; j<icols_; j++){
            ?????????????????????????????????????????????
		}
	}
	return a;  // calls copy cons
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& other){
	if (this!= &other){
		for (int i=0; i < irows_; i++)  // free memory
			delete [] matrix_[i];
		delete [] matrix_;

		icols_= other.icols_; // alloc new 
		irows_= other.irows_;
		matrix_= new T* [irows_];
		for (int i=0; i < irows_; i++)
			matrix_[i]= new T [icols_];
		for (int i=0; i < irows_; i++)
			for (int j=0; j < icols_; j++)
				matrix_[i][j]= other.matrix_[i][j];
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
		// … as above but with index j
	}else
		return matrix_[i][j];
}
