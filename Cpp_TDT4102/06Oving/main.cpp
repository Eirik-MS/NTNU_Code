//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"
#include "emnekatalog.hpp"
#include "temp.hpp"

//------------------------------------------------------------------------------'

void writeToFile();
void addLinnumberFile();
void lettersInFile();

// C++ programs start by executing the function main
int main() {
    // Show a nice message in the Terminal window
    CourseCatalog emnekatalog;
    emnekatalog.addCourse("TDT4102", "Objektorientert programmering");
    emnekatalog.addCourse("TDT4110", "Informasjonsteknologi grunnkurs");
    emnekatalog.addCourse("TDT4100", "Programmering grunnkurs");
    emnekatalog.addCourse("TTK4145", "Sanntidsprogrammering");
    emnekatalog.writeToFile("emner.txt");

    emnekatalog.readFromFile("emner.txt");
    cout << emnekatalog.getCourse("TDT4102") << endl;
    cout << emnekatalog.getCourse("TTK4145") << endl;


    TempsStat(readTempsFromFile("temperatures.txt"));


    // This lets the operating system (Windows, Mac, Linux, etc.) know that the program
    // did not encounter any errors
    return 0;
}

//------------------------------------------------------------------------------

void writeToFile() {
    cout << "Enter the name of the file you want to write: ";
    string fil;
    cin >> fil;
    std::filesystem::path fileName{fil};
    std::ofstream outputStream{fileName};

    while (true) {
        cout << "Enter a line to write to the file (or 'q' to quit): ";
        string line;
        getline(cin, line);
        if (line == "q") {
            break;
        }
        outputStream << line << endl;
    }

}

void addLinnumberFile(){
    cout << "Enter file name: ";
    string fil;
    cin >> fil;
    std::filesystem::path fileName{fil};
    std::ifstream inputStream{fileName};

    string linjer;
    int linjeNr = 1;

    std::ofstream outputStream{"log.txt"};
    while (getline(inputStream, linjer)) {
        outputStream << linjeNr << ": " << linjer << endl;
        linjeNr++;
    }
}

void lettersInFile(){
    string fil;
    map <char, int> letters = {
        {'a', 0}, {'b', 0}, {'c', 0}, {'d', 0}, {'e', 0}, {'f', 0}, {'g', 0}, {'h', 0}, {'i', 0}, {'j', 0}, {'k', 0}, {'l', 0}, {'m', 0}, {'n', 0}, {'o', 0}, {'p', 0}, {'q', 0}, {'r', 0}, {'s', 0}, {'t', 0}, {'u', 0}, {'v', 0}, {'w', 0}, {'x', 0}, {'y', 0}, {'z', 0}
    };
    string linjer;
    
    cout << "Enter a file name: ";
    cin >> fil;

    std::filesystem::path fileName{fil};
    std::ifstream inputStream{fileName};
    
    while (getline(inputStream, linjer)) {
        for (char c : linjer) {
            if (isalpha(c)) {
                c = tolower(c);
                letters.at(c) += 1;
            }
        }
    }

    for (auto& [key, value] : letters) {
        cout << key << ": " << value << endl;
    }
}