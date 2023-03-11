#include "/home/eirik/Documents/NTNU_Code/Cpp_TDT4102/07Oving/subprojects/std_lib_facilities/std_lib_facilities.h"

class Animal{
    protected:
    string name; 
    int age;

    public: 
    Animal(string name, int age) : name{name}, age{age} {};
    virtual ~Animal(){};
    virtual string toString() = 0;
};

class Dog : public Animal{
    public:
    Dog(string name, int age) : Animal(name, age) {};
    ~Dog(){};
    string toString();
};

class Cat : public Animal{
    public:
    Cat(string name, int age) : Animal(name, age) {};
    ~Cat(){};
    string toString();
};

void testAnimal();