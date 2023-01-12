#ifndef HEADER_H
#define HEADER_H

// Include needed standard library functions (STL)
#include <string>

// Predefined types
struct Item {
  std::string category{"n/a"};
  std::string name{"n/a"};
  double      price{0.0};
  int         age_limit;
};

struct Person {
  std::string name{"n/a"};
  int         age{0};
};

// The <signature> function  declaration (s)
std::string toString(Item const& item);
double      totalPrice(Item const& itemOne, Item const& itemTwo,
                       Item const& itemThree);
Person createRecord(std::string const& first_name, std::string const& last_name,
                    int year_of_birth);
int    yearOfBirth(Person const& record);
bool   canBuy(Person const& record, Item const& item);
void   restrictFromBuying(Item& item, Person const& record1,
                          Person const& record2, Person const& record3);

#endif // HEADER_H