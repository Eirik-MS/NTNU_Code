// The basics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <iomanip>
#include <tuple>
#include <cstddef>

// sizeof: bool,char,int,float and double;
std::tuple<bool, char, int, float, double> getTypeSizes() {
    return std::make_tuple(true, 'A', 1, 1.2, 3.4);
    
};


int main() {
    auto type = getTypeSizes();
    std::cout << sizeof(std::get<0>(type)) << '\n'
        << sizeof(std::get<1>(type)) << '\n'
        << sizeof(std::get<2>(type)) << '\n'
        << sizeof(std::get<3>(type)) << '\n'
        << sizeof(std::get<4>(type));
    

    return 0;
};
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
