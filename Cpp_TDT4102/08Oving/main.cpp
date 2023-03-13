#include "stdio.h"
#include <iostream>
#include "Matrix.h"



int main(){
	std::cout <<"Start of program"<<std::endl;
	Matrix test1{3,3};
	test1.set(1,1,4);
	std::cout << "Yo " << test1.get(1,1) << std::endl;

	std::cout<<"End of program"<<std::endl;
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