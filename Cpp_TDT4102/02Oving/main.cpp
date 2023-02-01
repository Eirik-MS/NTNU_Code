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
#include "oppgave5.h"


//------------------------------------------------------------------------------'

// C++ programs start by executing the function main
int main() {

    //lik er dårlig ide på index 0
    //vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    //for (int i = 0; i <= v.size(); i++) {
    //    cout << v.at(i) << endl;
    //}
    //Makes a Menu in Terminal
    while (1)
    {
        cout << "Choose a function " << endl;
        cout << "0. Exit" << endl;
        cout << "1. Multiplication" <<endl;
        cout << "2. Sum" << endl;
        cout << "3. is it Odd?" << endl;
        cout << "4. seconds to time" << endl;
        cout << "5. Sum of Many" << endl;
        cout << "6. NOK to EURO" << endl;
        cout << "7. Multiplication" << endl;
        cout << "8. Solve Quadratic equation" << endl;
        cout << "9. Pythagoras" << endl;
        cout << "10. Check Balance" << endl;
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 0:
            exit(0);
            return 0;
            break;
        case 1:
            inputIntegersAndPrintProduct();
            break;
        case 2:
            inputIntegersAndPrintSum();
            break;
        case 3:
            cout << "Skriv inn et heltall: ";
            int x;
            cin >> x;
            if (isOdd(x))
            {
                cout << "Tallet er oddetall" << endl;
            }
            else
            {
                cout << "Tallet er partall" << endl;
            }
            break;
        case 4:
            cout << "Skriv inn antall sekunder: ";
            int seconds;
            cin >> seconds;
            printHumanReadableTime(seconds);
            break;
        case 5:
            sumOfManyInt2();
            break;
        case 6:
            NOKtoEUR();
            break;
        case 7:
            ganngetabell();
            break;
        case 8:
            solveQuadraticEquation();
            break;
        case 9:
            pythagoras();
            break;
        case 10:
            int inskudd;
            int rente;
            int antallAar;
            cout << "Skriv inn inskudd: ";
            cin >> inskudd;
            cout << "Skriv inn rente: ";
            cin >> rente;
            cout << "Skriv inn antall år: ";
            cin >> antallAar;
            printBalance(calculateBalance(inskudd, rente , antallAar));
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
    return 0;
}

//------------------------------------------------------------------------------
