#include "header.h"
#include <iostream>

// The <signature> function definition(s)
size_t                sizeOf(Item const& item);
size_t                sizeOf(Person const& record);
size_t                sizeOfAge(Person const& record);
size_t                sizeOfItem();
size_t                sizeOfPerson();
std::optional<double> priceOfItem(void* item);
void                  raiseAgeLimitBy(Item& item, char no_years);
void                  setAge(void* record, char new_age);

int main() {
	
	return 0;
}

size_t                sizeOf(Item const& item) {
	return sizeof(item);
}

size_t                sizeOf(Person const& record) {
	return sizeof(record);
}

size_t                sizeOfAge(Person const& record) {
	return sizeof(record.age);
}

size_t                sizeOfItem() {
	Item test1;
	return sizeof(test1);
}

size_t                sizeOfPerson() {
	Person test1;
	return sizeof(test1);
}

std::optional<double> priceOfItem(void* item) {
	if (item == nullptr) { return NULL; }
	Item* stuff = reinterpret_cast<Item*>(item);
	return stuff->price; 
}

void                  raiseAgeLimitBy(Item& item, char no_years) {
	int changeYears = static_cast<int>(no_years);
	item.age_limit = item.age_limit + changeYears;
	return;
}

void                  setAge(void* record, char new_age) {
	int updateedAge = static_cast<int>(new_age);
	Person* human = reinterpret_cast<Person*>(record);
	human->age = updateedAge;
	return;
}