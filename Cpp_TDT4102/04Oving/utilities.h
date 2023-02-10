#pragma once

int incrementByValueNumTimes(int startValue, int increment, int numTimes);
void incrementByValueNumTimesRef(int& startValue, int& increment, int& numTimes);
void swapNumbers(int& A, int& B);
void printStudent(struct Student);
bool isInProgram(struct Student info, string studie);
string randomizeString(int len, char lower, char upper);
string readInputToString(int n, char lower, char upper);
int countChar(string word, char letter);

void playMasterMind();

struct Student
{
    string name;
    string studyProgram;
    int age;
};

