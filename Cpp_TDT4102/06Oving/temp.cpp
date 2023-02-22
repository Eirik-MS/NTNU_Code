#include "temp.hpp"
#include "std_lib_facilities.h"

istream& operator>>(istream& is, Temps& t){
    is >> t.max >> t.min;
    return is;
}

vector<Temps> readTempsFromFile(string fileName){
    std::filesystem::path file{fileName};
    std::ifstream inputStream{file};
    vector<Temps> temps;
    Temps temp;
    while (inputStream >> temp) {
        temps.push_back(temp);
        
    }
    return temps;
}

void TempsStat(vector<Temps> temps){
    double max = temps[0].max;
    double min = temps[0].min;
    for (Temps t : temps) {
        if (t.max > max) {
            max = t.max;
        }
        if (t.min < min) {
            min = t.min;
        }
    }
    cout << "Max: " << max << endl;
    cout << "Min: " << min << endl;

}