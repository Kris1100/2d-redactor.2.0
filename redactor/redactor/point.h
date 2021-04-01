#pragma once
#include<iostream>
#include <cmath>
using namespace std;

class point
{
public:
	// онструктор точки
	point(double x=0, double y=0);

	//«адать координату х
	void set_x(double x);
	//«адать координату у
	void set_y(double y);

	//ѕолучить координату у
	double get_y() const;
	//ѕолучить координату х
	double get_x() const;

	//¬озвращает в какой четверти лежит данна€ точка,0-в случае,если точка принадлежит началу координат
	double quarter();
	// ¬озвращает рассто€ние от начала координат
	double dist();
	//Ћежит ли точка на биссектрисе координатной плоскости
	//возвращает true /false
	bool bisector();

private:
	double _x, _y;
};

