#include "header.h"

// stl
#include <iostream>

// The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{

	// Create an item for testing
	auto item = Item("Apple", 12.0);
	item.setCategory("Food");
	item.setAgeLimit(0);

	Person myGuy = { "Johnny Enkeltmann", 22 };

	// Turn the item into a string
	auto const item_str = toString(myGuy);

	// Print the string to standard out
	std::cout << item_str << '\n';

	// Return the value Zero to the operating system
	// Indicating that your program terminated successfully without sideeffects
	return 0;
}