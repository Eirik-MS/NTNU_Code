#ifndef HEADER_H
#define HEADER_H

// Include needed standard library functions (STL)
#include <string>
#include <any>
#include <variant>
#include <optional>

// The <signature> function declarations
std::any toAny(std::string const& input);
std::variant<float, int> solve(int a);
std::optional<int> division(int a, int b, int c);
std::string toString(std::variant<int, float> const& num,
    std::optional<int> const& precision);

#endif // HEADER_H