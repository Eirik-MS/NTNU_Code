// Functions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include "header.h"
#include <numbers>

// The <signature> definition(s)
void nameMeEspenAskeladd(std::string& name);
int lengthOfName(std::string const& name);
int sumTheFactors(int a, int b);
std::pair<double, double> computeTheCircleCircumferenceAndArea(double radius);

int main()
{
    return 0;
}


void nameMeEspenAskeladd(std::string& name) {
    name = "Espen Askeladd";
    return;
}


int lengthOfName(std::string const& name) {
    return name.length();
}


int sumTheFactors(int a, int b) {
    return a + b;
}


std::pair<double, double> computeTheCircleCircumferenceAndArea(double radius) {
    double circumference = 2 * radius * std::numbers::pi;
    double area = radius * radius * std::numbers::pi;
    return std::pair<double, double> (circumference, area);
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
