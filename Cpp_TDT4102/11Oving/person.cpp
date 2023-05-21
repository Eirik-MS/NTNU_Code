#include "person.h"

void insertOrdered(std::list<Person> &p, const Person& person){
    
    for (auto pit = p.begin(); pit != p.end(); ++pit){ 
        if (person < *pit){                           
            p.insert(pit, person);                   
            return;
        }
    }
    p.push_back(person); 
}

