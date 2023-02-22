#pragma once
#include "std_lib_facilities.h"

typedef enum Course_returncode {
	Operation_sucsess    = 0,
    Write_error          = 1,
    Read_error           = 2,
} Course_returncode;



class CourseCatalog{
    private:
        map<string,string> courses;
    public:
    void addCourse(string courseCode, string courseName);
    void removeCourse(string courseCode);
    void changeName(string courseCode, string courseName);
    string getCourse(string courseCode);
    void writeToFile(string fileName);
    void readFromFile(string fileName);
};

