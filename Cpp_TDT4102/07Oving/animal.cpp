#include "animal.hpp"


string Animal::toString(){
    stringstream ss;
    ss << "Animal: " <<name << ", " << age;
    return ss.str();    
}

string Dog::toString(){
    stringstream ss;
    ss << "Dog: " <<name << ", " << age;
    return ss.str();    
}

string Cat::toString(){
    stringstream ss;
    ss << "Cat: " << name << ", " << age;
    return ss.str();    
}   


void testAnimal(){;
    Dog dog("Husky", 3);
    Cat cat("Katt", 2);
    cout << dog.toString() << endl;
    cout << cat.toString() << endl;

    vector<std::unique_ptr<Animal>> animals;
    animals.emplace_back(new Dog("Husky", 3));
    animals.emplace_back(new Cat("Katt", 2));

    for(auto& a : animals){
        cout << a->toString() << endl;
    }
}