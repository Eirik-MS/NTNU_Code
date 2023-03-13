#include <cassert>

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
	double* operator[](int pos);
};

