#ifndef HEADER_H
#define HEADER_H

// Include needed standard library functions (STL)
#include <optional>

// The <signature> declaration(s)
std::optional<char> valueInCharTbl(char const* char_tbl,
    size_t rows, size_t cols,
    size_t row_nr, size_t col_nr);

#endif // HEADER_H