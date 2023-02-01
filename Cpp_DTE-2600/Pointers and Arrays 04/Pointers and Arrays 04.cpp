// Pointers and Arrays 04.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "header.h"
#include <array>

// The <signature> definition(s)
char const* addressOfChar(char const* char_array, size_t length, char c);


int main()
{
	return 0;
}


char const* addressOfChar(char const *char_array, size_t length, char c) {
	char* returnvalue;
	if (char_array == nullptr)
	{
		return nullptr;
	}
	for (size_t i = 0; i < length; i++)
	{
		if (char_array[i] == c)
		{
			return &char_array[i];
		}
		else
		{
			returnvalue = nullptr;
		}
	}
	return returnvalue;
}