#include "header.h"
#include <sstream>
#include <iomanip>

// The <signature> function definition(s)
std::string toString(Item const& item);
double      totalPrice(Item const& itemOne, Item const& itemTwo, Item const& itemThree);
Person      createRecord(std::string const& first_name, std::string const& last_name,
    int year_of_birth);
int         yearOfBirth(Person const& record);
bool        canBuy(Person const& record, Item const& item);
void        restrictFromBuying(Item& item, Person const& record1,
    Person const& record2, Person const& record3);

int main() {
    return 0;
}

std::string toString(Item const& item) {
    std::stringstream newStr;
    //"Item: [category] - [name] : [price] NOK"
    newStr << "Item: " << item.category << " - " << item.name << " : " << std::setprecision(2) << std::fixed << item.price << " NOK";
    return newStr.str();

}

double totalPrice(Item const& itemOne, Item const& itemTwo, Item const& itemThree) {
    double sum = itemOne.price + itemTwo.price + itemThree.price;
    return sum;
}

Person createRecord(std::string const& first_name, std::string const& last_name, int year_of_birth) {
    Person newPerson;
    newPerson.name = first_name + " " + last_name;
    newPerson.age = 2022 - year_of_birth;

    return newPerson;
}

int yearOfBirth(Person const& record) {
    return 2022 - record.age;
}

bool canBuy(Person const& record, Item const& item) {
    if (record.age >= item.age_limit)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void restrictFromBuying(Item& item, Person const& record1, Person const& record2, Person const& record3) {
    item.age_limit = 18;
    canBuy(record1, item);
    canBuy(record2, item);
    canBuy(record3, item);
}