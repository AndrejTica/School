// matrix.h
// ahofmann, 2017

#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
	private:
		int rows, cols;
		double **m;
	public:
		Matrix (int row, int col);
		Matrix (const Matrix& o);
		~Matrix ();

		double& operator() (int i, int j);
		double operator() (int i, int j) const;

		Matrix&	operator=(const Matrix& other);

		Matrix	operator+(const Matrix& other);
		Matrix	operator*(const Matrix& other);

		friend ostream&	operator<<(ostream& os, const Matrix& other);
//mab		Matrix&	operator+=(const Matrix& other);
};
#endif
