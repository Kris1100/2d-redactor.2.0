#pragma once
#include <iostream>
using namespace std;

class figure
{
public:
	virtual void draw() {};
	virtual void mymenu() {};

	friend istream& operator>>(istream& in, figure& f) { return in; }
	template<typename T> figure& operator=(T& f) { return *this; }
	//������ �� ������
	bool is_created = false;
	//��������� �� ������
	bool is_drawn = false;
};

