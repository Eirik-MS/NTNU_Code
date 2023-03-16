#include "Matrix.h"


//Constructors and destructors
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

//Set and get functions

double Matrix::get(int Row, int Col) const {
	return (listPtrCol[Col][Row]);
} 

void Matrix::set(int Row, int Col, double value){
	listPtrCol[Col][Row] = value;
};


int Matrix::getRows(){
	return nrows;
}

int Matrix::getColums()const{
	return ncolums;
}

//Overload of operators

Matrix::Matrix(Matrix& mat){
	nrows = mat.getRows();
	ncolums = mat.getColums();
	listPtrCol = new double*[ncolums];
	for (int i = 0; i < ncolums; i++){
		listPtrCol[i] = new double[nrows];
		for (int k = 0; k < nrows; k++){
			listPtrCol[i][k] = mat.get(i,k);
		}
	}
}

double* Matrix::operator[](int pos){
	return listPtrCol[pos];
}

std::ostream& operator<<(std::ostream& os, Matrix& mat){
	std::cout << "Matrix: " << mat.getRows() << "x" << mat.getColums() << std::endl;
	std::cout << "_"<< std::setw(mat.getColums()*2+2) << "_" << std::endl;
	for (int i = 0; i < mat.getRows(); i++){
		std::cout << "| ";
		for (int k = 0; k < mat.getColums(); k++){
			std::cout << mat.get(i,k) << " ";
		}
		std::cout << "|" << std::endl;
	}
	std::cout << "¯"<< std::setw(mat.getColums()*2+2) << " ¯" << std::endl;

	return os;
}


Matrix& Matrix::operator=(Matrix& mat){
	for (int i = 0; i< mat.getColums(); i++){
		delete[] listPtrCol[i];
	}
	delete listPtrCol;
	 

	nrows = mat.getRows();
	ncolums = mat.getColums();
	for (int i =0; i<ncolums; i++){
		for (int k = 0; i<nrows; k++){
			listPtrCol[i][k] = mat.get(i,k);
		}
	}


}