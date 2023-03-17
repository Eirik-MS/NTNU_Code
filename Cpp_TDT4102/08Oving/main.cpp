#include "stdio.h"
#include <iostream>
#include "Matrix.h"
#include "dummy.h"



int main(){
	std::cout <<"Start of program"<<std::endl;
	Matrix A(4,4);
	Matrix B(4,4);
	Matrix C(4,4);
	for (int i = 0; i < 4; i++){
		for (int k = 0; k < 4; k++){
			A.set(i,k, 4+k);
			B.set(k,i, 3-i*2);
		}
		
	}
	C += A;
	C += B;

	std::cout << A << B << C << std::endl;


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