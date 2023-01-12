//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------'

int maxOfTwo(int a, int b) {
    if (a > b) {
        cout << "A is greater than B" << endl;
        return a;
    } else {
        cout << "B is greater than or equal A" << endl;
        return b;
    }
}

int fibonacci(int n){
    int a = 0;
    int b = 1;
    cout << "Fibonacci sequence: " << endl;
    for (int i = 0; i < n; i++) {
        cout << a << endl;
        int temp = b;
        b += a;
        a = temp;
    }
}

int squareNumberSum(int n){
    int totalSum = 0;
    for (int i = 1; i <= n; i++) {
        totalSum += i*i;
    }
    return totalSum;
}


void triangleNumbersBelow(int n){
    int acc = 1;
    int num = 2; 
    cout << "Triangle numbers below " << n << ":"<< endl;
    while (acc < n) {
        cout << acc << endl;
        acc += num;
        num++;
    }
    cout << endl;
}

bool isPrime (int n){
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void naivePrimeNumberSearch(int n){
    for (int i =2; i < n; i++) {
        if (isPrime(i)) {
            cout << i << "is a Prime" << endl;
        }
    }
}

int findGreatestDivisor(int n){
    for (int i = n-1; i > 1; i--) {
        if (n % i == 0) {
            return i;
        }
    }
    return 0;
}

// C++ programs start by executing the function main
int main() {
    // Show a nice message in the Terminal window
    cout << "Oppgave a)" << endl;
    cout << maxOfTwo(5, 6) << endl;

    // This lets the operating system (Windows, Mac, Linux, etc.) know that the program
    // did not encounter any errors
    return 0;
}

//------------------------------------------------------------------------------