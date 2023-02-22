#include "std_lib_facilities.h"

typedef struct {
    double max;
    double min;
} Temps;

istream& operator>>(istream& is, Temps& t);

vector<Temps> readTempsFromFile(string fileName);
void TempsStat(vector<Temps> temps);