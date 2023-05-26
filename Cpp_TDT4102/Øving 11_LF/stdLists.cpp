#include <algorithm>
#include <forward_list>
#include <iostream>
#include <iterator>
#include <list>
#include <string>


class Person{
private:
    std::string firstName;
    std::string lastName;
public:
    Person(const std::string& f, const std::string& l) : firstName(f), lastName(l){}
    std::string getFirstName() const {return firstName;}
    std::string getLastName() const {return lastName;}

    bool operator <(const Person& p) const;
    friend std::ostream& operator <<(std::ostream& out, const Person& p);
};

bool Person::operator <(const Person& p) const{
    // concatenate last + first and compare
    return (lastName + firstName) < (p.lastName + p.firstName);
}

std::ostream& operator <<(std::ostream& out, const Person& p){
    out << p.lastName << ", " << p.firstName;
    return out;
}

void insertOrdered(std::list<Person> &p, const Person& person){
    // pit has type list<Person>::iterator
    for (auto pit = p.begin(); pit != p.end(); ++pit){ // Iterate through the list
        if (person < *pit){                            // until we reach an element that is larger than the element we wish to insert
            p.insert(pit, person);                     // and insert out element at the found position.
            return;
        }
    }
    p.push_back(person); // If there is no element in the list larger than the one we wish to insert,
                         // the element is inserted at the back of the list.
    // Alternativt <algorithm>
    // auto it = std::lower_bound(p.begin(), p.end(), person);
    // p.insert(it, person);
}

void testStdLists(){
    std::cout << "std::list:" << '\n';

    std::list<Person> people;
    insertOrdered(people, Person("Trond", "Aalberg"));
    insertOrdered(people, Person("Trine", "Bakke"));
    insertOrdered(people, Person("Arne", "Aalberg"));
    insertOrdered(people, Person("Ola", "Norman"));
    insertOrdered(people, Person("Kari", "Norman"));

    for (const auto& p : people){
        std::cout << p << '\n';
    }
    // Alternativt <algorithm>
    // std::copy(people.begin(), people.end(), std::ostream_iterator<Person>(std::cout, "\n"));

    std::cout << '\n';
}
