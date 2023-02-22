#include "emnekatalog.hpp"

void CourseCatalog::addCourse(string courseCode, string courseName){
    courses.insert({courseCode, courseName});
}

void CourseCatalog::removeCourse(string courseCode){
    courses.erase(courseCode);
}

string CourseCatalog::getCourse(string courseCode){
    return courses.at(courseCode);
}

void CourseCatalog::changeName(string courseCode, string courseName){
    courses.at(courseCode) = courseName;
}

void CourseCatalog::writeToFile(string fileName){
    std::filesystem::path file{fileName};
    std::ofstream outputStream{file};

    for (auto& [key, value] : courses){
        outputStream << key << "|" << value << endl;
    }
 
}

void CourseCatalog::readFromFile(string fileName){
    std::filesystem::path file{fileName};
    std::ifstream inputStream{file}; 

    string line;
    string key;
    string value;

    while(std::getline(inputStream, line)){
        std::istringstream iss(line);
        std::getline(iss, key, '|');
        std::getline(iss, value, '|');
        courses.insert({key, value});
    }

}