//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"
#include "cannonball.h"
#include "utilities.h"
#define MAXERROR 0.01

void testDeviation(double compareOperand, double toOperand, double maxError, string name);
void testAll();

//------------------------------------------------------------------------------'

// C++ programs start by executing the function main
int main() {
    // Show a nice message in the Terminal window
    playTargetPractice();
    // This lets the operating system (Windows, Mac, Linux, etc.) know that the program
    // did not encounter any errors
    return 0;
}

//------------------------------------------------------------------------------



void testDeviation(double compareOperand, double toOperand, double maxError, string name) {
    if (abs(compareOperand - toOperand) > maxError) {
        cout << "ERROR: " << name << " is off by " << abs(compareOperand - toOperand) << ", that is more than error clerance " << maxError << "with value "<< toOperand << "expected: "<< compareOperand <<endl;
    }else{
        cout << "SUCCESS: " << name << " is off by " << abs(compareOperand - toOperand) << ", that is less than error clerance " << maxError << endl;
    }
}

void testAll() {

    testDeviation(-9.81, acclY(), MAXERROR, "acclY()");
    testDeviation(0.475, velY(25, 2.5), MAXERROR, "velY(25, 2.5)");
    testDeviation(125.0, posX(50, 2.5, 0), MAXERROR, "posX(50, 2.5, 0)");
    testDeviation(31.84, posY(25, 2.5, 0), MAXERROR, "posY(25, 2.5, 0)");

}