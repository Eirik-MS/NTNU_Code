
#include "std_lib_facilities.h"



int sumOfManyInt(){
    cout << "Skriv inn hvor mange heltall som skal summeres: ";
    int amount;
    cin >> amount;
    int sum = 0;
    int number;
    for (int i = 0; i < amount; i++)
    {
        cin >> number;
        sum += number;
    }
    cout << "Summen av tallene er: " << sum << endl;
    return sum;
}

int sumOfManyInt2(){
    int sum = 0;
    int number;
    while (cin >> number)
    {   
        if (number == 0)
        {
            break;
        }
        sum += number;
    }
    cout << "Summen av tallene er: " << sum << endl;
    return sum;    
}

/*
En for løkke er bra når du vet hvor mange ganger du skal gjenta noe.
Mens en while løkke er en mer åpen løkke som kan gjenta så mange ganger du vil.
*/

double inputDouble(){
    double x;
    cout << "Skriv inn et desimaltall: ";
    cin >> x;
    return x;
}


double NOKtoEUR(double NOK){
    double EUR = NOK * 0.11;
    return EUR;
}