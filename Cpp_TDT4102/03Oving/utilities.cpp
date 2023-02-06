#include "utilities.h"

int randomWithLimits(int lowerLimit, int upperLimit) {
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_real_distribution<double> distribution(0,1);
    double number = distribution(generator);
    return (int) (number * (upperLimit - lowerLimit) + lowerLimit);
}