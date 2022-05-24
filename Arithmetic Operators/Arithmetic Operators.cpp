#include "header.h"
#include <cmath>

// The <signature> definition(s)
double sum(double a, double b, double c, double d);
int prod(int a, int b, int c, int d, int e, int f);
double divByReal(double numerator, double denominator);
int divByInt(double numerator, int denominator);
int divByIntRem(double numerator, int denominator);

int main() {

	return 0;
}

double sum(double a, double b, double c, double d) {
	return a + b + c + d;
}

int prod(int a, int b, int c, int d, int e, int f) {
	return a * b * c * d * e * f; 
}

double divByReal(double numerator, double denonminator) {
	return numerator / denonminator;
}

int divByInt(double numerator, int denominator) {
	return numerator / denominator;
}

int divByIntRem(double numerator, int denominator) {
	return fmod(numerator, denominator);
}

