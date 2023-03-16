
#include "dummy.h"

void dummyTest() {
	Dummy a;
	*a.num = 4;
	Dummy b{a};
	Dummy c;
	c = a;
	
	std::cout << "a: " << *a.num << '\n';
	std::cout << "b: " << *b.num << '\n';
	std::cout << "c: " << *c.num << '\n';

	*b.num = 3;
	*c.num = 5;

	std::cout << "a: " << *a.num << '\n';
	std::cout << "b: " << *b.num << '\n';
	std::cout << "c: " << *c.num << '\n';

	//Alle pekere peker til samme verdi
	//Den krasjer når den prøver å slette num
}

Dummy& Dummy::operator=(const Dummy& other){
	int newNum = *other.num;
	delete num;
	num = new int{newNum};
	return *this;
}