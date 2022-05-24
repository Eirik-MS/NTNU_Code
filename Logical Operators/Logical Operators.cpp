// Logical Operators.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <bitset>
#include "header.h"

// The <signature> definition(s)
bool circuit01(bool a, bool b);
bool circuit02(bool a, bool b, bool c);
bool circuit03(bool a, bool b, bool c);
std::bitset<8> bitEval01(std::bitset<8> a, std::bitset<8> b, std::bitset<8> c);
std::bitset<4> bitEval02(std::bitset<4> a, std::bitset<4> b);

int main()
{
    return 0;
}

bool circuit01(bool a, bool b) {
    return !(a && b);
}

bool circuit02(bool a, bool b, bool c) {
    return !(a && b) || c;
}

bool circuit03(bool a, bool b, bool c) {
    return (!(a && b) && (b || c));
}

std::bitset<8> bitEval01(std::bitset<8> a, std::bitset<8> b, std::bitset<8> c) {
    return (a&b)|(~c);
}

std::bitset<4> bitEval02(std::bitset<4> a, std::bitset<4> b) {
    return a ^ b;
}
