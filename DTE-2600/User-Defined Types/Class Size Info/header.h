#ifndef HEADER_H
#define HEADER_H

// Include needed standard library functions (STL)
#include <string>
#include <optional>

// Predefined types
struct Item {
	std::string category{ "n/a" };
	std::string name{ "n/a" };
	double      price{ 0.0 };
	int         age_limit{0};
};

struct Person {
	std::string name{ "n/a" };
	int         age{ 0 };
};

// The <signature> function  declaration (s)
size_t sizeOf(Item const& item);
size_t sizeOf(Person const& record);
size_t sizeOfAge(Person const& record);
size_t sizeOfItem();
size_t sizeOfPerson();
std::optional<double>  priceOfItem(void* item);
void   raiseAgeLimitBy(Item& item, char no_years);
void   setAge(void* record, char new_age);

#endif // HEADER_H