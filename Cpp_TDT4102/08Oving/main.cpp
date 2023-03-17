#include "stdio.h"
#include <iostream>
#include "Matrix.h"
#include "dummy.h"



int main(){
	std::cout <<"Start of program"<<std::endl;
	Matrix A(3,3);
	Matrix B(3,3);
	Matrix C(2,3);
	for (int i = 0; i < 3; i++){
		for (int k = 0; k < 3; k++){
			A.set(i,k, 4+i);
			B.set(k,i, 3-1);
		}
		
	}
	C += A;
	C += B;

	std::cout << A << C << std::endl;


	dummyTest();
	return 0;
}


//Training in the use of dynamic memory allocation
void fillINFibonacciNumbers(int *result, int length){
	for (int i = 0; i < length; i++){
		if (i > 1){
			result[i] = result[i - 1] + result[i - 2];
		}
		else if (i == 1){
			result[i] = 1;
		}
		else{
			result[i] = 0;
		}
	}
}

void printFibonacciNumbers(int *result, int length){
	for (int i = 0; i < length; i++){
		std::cout << result[i] << std::endl;
		//printf("%d\n", result[i]);
	}
}

void createFibonacci(){
	int length = 0;
	std::cout << "Enter the length of the Fibonacci sequence: ";
	std::cin >> length;
	int *result = new int[length];
	fillINFibonacciNumbers(result, length);
	printFibonacciNumbers(result, length);
	
}