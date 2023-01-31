// Pointers and Arrays 05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "header.h"
#include <optional>

// The <signature> definition(s)
std::optional<char> valueInCharTbl(char const* char_tbl, size_t rows, size_t cols, size_t row_nr, size_t col_nr);

int main()
{
	return 0;

}


std::optional<char> valueInCharTbl(char const* char_tbl, size_t rows, size_t cols, size_t row_nr, size_t col_nr) {

	if (rows<row_nr || cols<col_nr || char_tbl == nullptr)
	{
		return std::nullopt;
	}
	else {
		//gjør omm til en dimensjonal index
		return char_tbl[row_nr* cols + col_nr];
	}
}
