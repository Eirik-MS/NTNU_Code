
#include "oppgave3.h"

int discriminant(int a, int b, int c){
    int d = b*b - 4*a*c;
    return d;
}

void printRealRoots(int a, int b, int c){
    int d = discriminant(a, b, c);
    if (d < 0){
        cout << "Ingen reelle røtter" << endl;
    }
    else if (d == 0){
        int x = -b / (2*a);
        cout << "En reell rot: " << x << endl;
    }
    else {
        int x1 = (-b + sqrt(d)) / (2*a);
        int x2 = (-b - sqrt(d)) / (2*a);
        cout << "To reelle røtter: " << x1 << " og " << x2 << endl;
    }
}

void solveQuadraticEquation(){
    cout << "Skriv inn a, b og c for å løse en likning på formen ax^2 + bx + c" << endl;
    double a = inputDouble();
    double b = inputDouble();
    double c = inputDouble();
    printRealRoots(a, b, c);
}