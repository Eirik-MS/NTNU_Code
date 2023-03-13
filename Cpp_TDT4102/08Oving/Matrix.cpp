#include "Matrix.h"

Matrix::Matrix(int nRows, int nColums): nrows{nRows}, ncolums{nColums}{
	//assert(nRows>1);
	//assert(nColums>1);
	listPtrCol = new double*[nColums];
	for (int i = 0; i < nColums; i++){
		listPtrCol[i] = new double[nRows];
		for (int k = 0; k < nRows; k++){
			listPtrCol[i][k] = 0;
		}
	}
}

Matrix::Matrix(int nRows): Matrix(nRows,nRows){
	for (int i = 0; i < nRows; i++){
		for (int k = 0; k< nRows; k++){
			if (i==k){
				listPtrCol[i][k] = 1;
			}
		}
	}
}


Matrix::~Matrix(){
	for (int i = 0; i < ncolums; i++){
		delete[] listPtrCol[i];
	}
	delete[] listPtrCol;
}

double Matrix::get(int Row, int Col) const {
	return (listPtrCol[Col][Row]);
} 

void Matrix::set(int Row, int Col, double value){
	listPtrCol[Col][Row] = value;
};

double* Matrix::operator[](int pos){
	return listPtrCol[pos];
}

int Matrix::getRows(){
	return nrows;
}

int Matrix::getColums()const{
	return ncolums;
}

std::ostream& operator<<(){
	
}