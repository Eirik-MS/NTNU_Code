#include <string>
#include <iostream>
#include <list>

class Person {
    std::string fornavn;
    std::string etternavn;

public:
    Person(const std::string fornavn, const std::string etternavn) : fornavn{fornavn}, etternavn{etternavn} {}
    std::string const get_name(){return fornavn;}
    std::string const get_lastname(){return etternavn;}

    friend std::ostream& operator<<(std::ostream& os, const Person& person) {
        os << person.etternavn << ", " << person.fornavn;
        return os;
    }
    bool operator <(const Person& p) const{
    // concatenate last + first and compare
    return (etternavn + fornavn) < (p.etternavn + p.fornavn);
}

};





void insertOrdered(std::list<Person> &l, const Person& p);
