//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
// This program outputs the message "Hello, World!" to the monitor

#include "oppgave1.h"

// C++ programs start by executing the function main
int menu1() {
    
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



//------------------------------------------------------------------------------
