#include "header.h"
#include <sstream>
#include <iostream>

// The <signature> function definition(s)

// Item
Item::Item()
{
	m_category = "n/a";
	m_name = "n/a";
	m_price = 0.0;
	m_age_limit = 100;
}

Item::Item(std::string const& name, double price)
{
	m_name = name;
	m_price = price;
	m_age_limit = 100;
	m_category = "n/a";
}

std::string const& Item::category() const
{
	return this->m_category; 
}

std::string const& Item::name() const
{
	return this->m_name;
}

double Item::price() const
{
	
	return this->m_price;
}

int Item::ageLimit() const
{
	return this->m_age_limit;
}

void Item::setCategory(std::string const& category)
{
	this->m_category = category;
}

void Item::setName(std::string const& name)
{
	this->m_name = name;
}

void Item::setPrice(double price)
{
	this->m_price = price;
}

void Item::setAgeLimit(int ageLimit)
{
	this->m_age_limit = ageLimit;
}

// Person
Person::Person()
{
	m_name = "n/a";
	m_year_of_birth = 0;
	m_id = s_next_id;
	generateNextId();
}

Person::Person(std::string const& name, int age)
{
	m_name = name;
	m_year_of_birth = CURRENT_YEAR - age;
	m_id = s_next_id;
	generateNextId();
}

std::string const& Person::name() const
{
	return this->m_name;
}

int Person::yearOfBirth() const
{
	return this->m_year_of_birth;
}

void Person::setAge(int age)
{
	this->m_year_of_birth = CURRENT_YEAR - age;
}

void Person::setName(std::string const& name)
{
	this->m_name = name;
}

// Static members
int Person::s_next_id = 1;

int Person::generateNextId()
{
	s_next_id += 1;
	return s_next_id;
}

// Other
std::string toString(Person const& person)
{
	std::string name = person.m_name;
	int age = CURRENT_YEAR - person.m_year_of_birth;
	const int id = person.m_id;
	//Person ([id]): [name] - [age] year[s] of age
	if (age <= 1) {
	std::stringstream returnStr;
	returnStr << "Person (" << id << "): " << name << " - " << age << " year of age";
	return returnStr.str();
	}
	else
	{
		std::stringstream returnStr;
		returnStr << "Person (" << id << "): " << name << " - " << age << " years of age";
		return returnStr.str();
	}
}


