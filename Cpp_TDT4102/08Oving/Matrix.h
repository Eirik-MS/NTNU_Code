#include <cassert>
#include <iostream>
#include <iomanip>
#include <ios>

class Matrix{
private:
	int nrows;
	int ncolums;
	double** listPtrCol;

public:
	//constructors and destructors
	Matrix(int nRows,int nColums);
	explicit Matrix(int nRows);
	~Matrix();
	
	//Get and set functions
	double get(int Row, int Col) const;
	void set(int Row, int Col, double value);
	int getRows();
	int getColums() const;

	//Oveload of operators
	Matrix(Matrix& mat);
	double* operator[](int pos);
	Matrix& operator=(Matrix& mat);
	Matrix& operator+=(Matrix& mat);
	friend std::ostream& operator<<(std::ostream& os, Matrix& mat);
	
};

