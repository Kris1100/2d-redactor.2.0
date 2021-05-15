#pragma once
#include <iostream>
using namespace std;
class figure
{
public:
	virtual void draw() {};

	friend std::istream& operator>>(std::istream& in, figure& p) { return in; };
	virtual figure& operator=(figure& f) { return *this; };
};

