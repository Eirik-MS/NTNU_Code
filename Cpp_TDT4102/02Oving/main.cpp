//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"
#include "oppgave1.h"
#include "oppgave2.h"
#include "oppgave3.h"
#include "oppgave4.h"


//------------------------------------------------------------------------------'

// C++ programs start by executing the function main
int main() {
    while (1)
    {    
        cout << "Velg funksjon: \n" 
        << "0) Avslutt \n" 
        << "1) Summer to heltall \n" 
        << "2) Summer flere heltall \n"
        << "3) Print tall \n" 
        << "4) Print tall fra funksjon \n"
        << "5) Summer flere heltall fra funksjon \n" 
        << "6) Oddetall/partall \n"
        << "7) Tid \n"
        << "Angi valg (0-3): ";
        int number = inputInteger();
        int a;
        int b;
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 0:
            return 0;
            break;
        case 1:
            cin >> a;
            cin >> b;
            cout << a << " + " << b << " = " << add(a, b) << endl;
            break;
        case 2:
            /* code */
            break;
        case 3:
            inputIntegersAndPrint();
            break;
        case 4:
            cout << number << endl;
            break;
        case 5:
            inputIntegersAndPrintSum();
            break;
        case 6:
            for (int i = 0; i < 15; i++)
            {
                if (isOdd(i))
                {
                    cout << i << " er et oddetall" << endl;
                }
                else
                {
                    cout << i << " er et partall" << endl;
                }
            }
            break;
        case 7:
            cin >> number;
            printHumanReadableTime(number);
            break;

        case 8:
            pythagoras();
            break;
        default:
            cout << "Ugyldig valg" << endl;
            break;
        }

        // This lets the operating system (Windows, Mac, Linux, etc.) know that the program
        // did not encounter any errors
        return 0;
    }
}

//------------------------------------------------------------------------------
