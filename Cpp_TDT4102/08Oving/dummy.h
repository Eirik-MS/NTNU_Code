#pragma once
#include <iostream>
#include <utility>
class Dummy {
	public:
	int *num;

	Dummy() {num = new int{0};}
	Dummy(const Dummy& other) {num = new int{*other.num};}
	Dummy& operator=(const Dummy& other);
	~Dummy() {delete num;}
	
};

void dummyTest();
