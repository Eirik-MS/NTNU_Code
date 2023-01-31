//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
// This program outputs the message "Hello, World!" to the monitor

#include "oppgave1.h"

// C++ programs start by executing the function main
//------------------------------------------------------------------------------
// This is the entry point for the program
void inputIntegersAndPrintProduct() {
    int x = 0;
    int y = 0;
    cout << "Skriv inn to heltall: ";
    cin >> x;
    cin >> y;
    int product = x * y;
    cout << x << " * " << y << " = " << product << endl;
}

int add(int a, int b) {
    return a + b;
}

void inputIntegersAndPrint(){
    int x; // define a variable called x
    cout << "Skriv inn et heltall: "; // output (print) a message
    cin >> x; // read an integer from the keyboard and assign it to x
    cout << "Du skrev inn: " << x << endl; // output the value of x
}

int inputInteger() {
    int x;
    cout << "Skriv inn et heltall: ";
    cin >> x;
    return x;
}

void inputIntegersAndPrintSum() {
    int x = inputInteger();
    int y = inputInteger();
    int sum = add(x, y);
    cout << " Summen av tallene " << sum << endl;
}

bool isOdd(int x) {
    return x % 2 == 1;
}

void printHumanReadableTime(int seconds) {
    int hours = seconds / 3600;
    int minutes = (seconds % 3600) / 60;
    int remainingSeconds = seconds % 60;
    cout << hours << " timer, " << minutes << " minutter og " << remainingSeconds << " sekunder" << endl;
}
//------------------------------------------------------------------------------'
