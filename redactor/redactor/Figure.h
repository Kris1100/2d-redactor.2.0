#pragma once
#include <iostream>
using namespace std;

class figure
{
public:
	//Рисование объекта
	virtual void draw() {};
	//Меню объекта
	virtual void mymenu() {};

	friend istream& operator>>(istream& in, figure& f) { return in; }
	template<typename T> figure& operator=(T& f) { return *this; }
	//Создан ли объект
	bool is_created = false;
	//Нарисован ли объект
	bool is_drawn = false;
};

