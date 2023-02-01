
#include "oppgave5.h"

vector<int> calculateBalance(int inskudd, int rente, int antallAar){
    vector<int> balance;
    balance.push_back(inskudd);
    for (int i = 1; i < antallAar; i++)
    {
        balance.push_back(balance[i-1] + balance[i-1]*rente/100);
    }
    return balance;
}

void printBalance(vector<int> balance){
    cout << "År " << "Saldo " << endl;
    for (int i = 0; i < (int) balance.size(); i++)
    {
        cout << i << setw(10) << balance.at(i) << endl;
    }
}

