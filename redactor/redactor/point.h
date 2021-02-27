#pragma once
#include<iostream>
#include <cmath>
using namespace std;
class point
{
public:
	point(double x=0, double y=0);//конструктор точки
	double get_x();
	void set_x(double x);
	double get_y();
	void set_y(double y);
	void quarter();//определение в какой четверти лежит точка
	double dist();//расстояние от начала координат
	void bisector();//лежит ли точка на биссектрисе координатной плоскости
private:
	double _x, _y;
};

