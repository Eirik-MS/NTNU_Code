#pragma once
#ifndef HEADER_H
#define HEADER_H

// Include needed standard library functions (STL)
#include <tuple>
#include <string>
#include <cstddef>
#include <numbers>

// The <signature> declaration(s)
void nameMeEspenAskeladd(std::string& name);
int  lengthOfName(std::string const& name);
int  sumTheFactors(int a, int b);

std::pair<double, double>
computeTheCircleCircumferenceAndArea(double radius);

#endif // HEADER_H
