
#include "oppgave2.h"



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
    cout << "Skriv inn tallene som skal summeres og avslutt med 0: ";
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


double NOKtoEUR(){
    //får ikke desimaltall hvis jeg bruker inputDouble()
    double NOK = inputDouble();
    if (NOK < 0)
    {
        cout << "Du kan ikke skrive inn et negativt tall!" << endl;
        NOKtoEUR();
        return 0;
    }
    double EUR = NOK * 0.11;
    cout << "Beløpet i EUR er: " << fixed << setprecision(2) << EUR << endl;
    return EUR;
}

void ganngetabell(){
    int sizeHorizontal;
    int sizeVertical;
    cout << "Skriv inn størrelsen på tabellen: ";
    cin >> sizeHorizontal;
    cin >> sizeVertical;
    for (int i = 1; i <= sizeHorizontal; i++)
    {
        for (int j = 1; j <= sizeVertical; j++)
        {
            cout << i*j << "\t";
        }
        cout << endl;
    }
}