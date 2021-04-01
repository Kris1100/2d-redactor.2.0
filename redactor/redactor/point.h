#pragma once
#include<iostream>
#include <cmath>
using namespace std;

class point
{
public:
	//Конструктор точки
	point(double x=0, double y=0);
	//Получить координату х
	double get_x() const;
	//Задать координату х
	void set_x(double x);
	//Получить координату у
	double get_y() const;
	//Задать координату у
	void set_y(double y);
	//Определить, в какой четверти лежит точка
	void quarter();
	//Расстояние от начала координат
	double dist();
	//Лежит ли точка на биссектрисе координатной плоскости
	void bisector();

private:
	double _x, _y;
};

