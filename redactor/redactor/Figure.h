#pragma once
#include <iostream>
using namespace std;

class figure
{
public:
	virtual void draw() {}

	friend istream& operator>>(istream& in, figure& f) { return in; }
	virtual figure& operator=(figure& f) { return *this; }
};

