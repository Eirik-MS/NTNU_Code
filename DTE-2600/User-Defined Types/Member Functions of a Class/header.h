#ifndef HEADER_H
#define HEADER_H

// Include needed standard library functions (STL)
#include <string>
#include <optional>

constinit const int CURRENT_YEAR = 2022 ;

// Predefined types
class Item {
protected:
    std::string m_category{ "n/a" };
    std::string m_name{ "n/a" };
    double      m_price{ 0.0 };
    int         m_age_limit{ 100 };

public:
    Item();
    Item(std::string const& name, double price);

    std::string const& category() const;
    std::string const& name() const;
    double             price() const;
    int                ageLimit() const;

    void               setCategory(std::string const& category);
    void               setName(std::string const& name);
    void               setPrice(double);
    void               setAgeLimit(int);
};

class Person {
protected:
    std::string m_name{ "n/a" };
    int         m_year_of_birth{ 0 };
    int         m_id{ 0 };

public:
    Person();
    Person(std::string const& name, int age);

    std::string const& name() const;
    int                yearOfBirth() const;

    void setAge(int age);
    void setName(std::string const& name);

protected:
    static int s_next_id;
    static int generateNextId();

    friend std::string toString(Person const&);
};

std::string toString(Person const& person);

#endif // HEADER_H