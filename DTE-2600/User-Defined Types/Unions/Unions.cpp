#include "header.h"
#include <any>
#include <variant>
#include <optional>
#include <iostream>
#include <iomanip>
#include <sstream>

// The <signature> function definition(s)

std::any toAny(std::string const& input)
{
    std::string type;
    std::stringstream Input;
    Input << input;
    Input >> type;


    if (type == "int") {
        int value;
        Input >> value;
        return value;
    }
    else if (type == "float") {
        float value;
        Input >> value;
        return value;
    }
    else if (type == "doubble") {
        double value;
        Input >> value;
        return value;
    }
    else if (type == "string") {
        std::string value;
        Input >> value;
        return value;
    }
    else {
        return NULL;
    }
    
}

std::variant<float, int> solve(int a)
{
    
    if (a % 10 > 0) {
        std::cout <<  a % 10;
        return a/ 10.0f;
    }
    else {
        return a / 10;
    }
}


std::optional<int> division(int a, int b, int c)
{
    if ((a - b) / c > -(a - b) / c) {
        return (a - b) / c;
    }
    else
    {
        return -(a - b) / c;
    }
}

std::string toString(std::variant<int, float> const& num, std::optional<int> const& precision)
{
    return "nope";
}
