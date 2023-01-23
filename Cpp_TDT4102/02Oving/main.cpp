//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"
#include "oppgave1.h"

//------------------------------------------------------------------------------'

// C++ programs start by executing the function main
int main() {
    // Show a nice message in the Terminal window
    cout << "Hello, World!" << endl;
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        menu1();
        break;
    case 2:
        menu2();
        break;

    default:
        break;
    }
    menu1();

    // This lets the operating system (Windows, Mac, Linux, etc.) know that the program
    // did not encounter any errors
    return 0;
}

//------------------------------------------------------------------------------
