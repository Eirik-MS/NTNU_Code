#include "header.h"

// stl
#include <iostream>

// The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{

    // Create some items for testing
    auto const any_int_type = toAny("int 3");
    auto const any_double_type = toAny("int 3");

    // Try printing the value to standard out
    try
    {
        std::cout << std::any_cast<int>(any_int_type) << '\n';
        std::cout << std::any_cast<double>(any_double_type) << '\n';
    }
    catch (const std::bad_any_cast& e)
    {
        std::cout << e.what() << '\n';
    }

    // Return the value Zero to the operating system
    // Indicating that your program terminated successfully without sideeffects
    return 0;
}