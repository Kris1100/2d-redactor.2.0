#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class point
{
public:
	// онструктор точки
	point(double x = 0, double y = 0);

	//«адать координату х
	void set_x(double x) { _x = x; }
	//«адать координату у
	void set_y(double y) { _y = y; }

	//ѕолучить координату у
	double get_y() const { return _y; }
	//ѕолучить координату х
	double get_x() const { return _x; }

	//¬озвращает # четверти, лежит данна€ точка, 0 - в случае, если точка принадлежит началу координат
	int quarter();
	//¬озвращает рассто€ние от начала координат
	double dist();
	//Ћежит ли точка на биссектрисе координатной плоскости
	bool bisector();

	//перегрузка операторов равенства, вводва, вывода,присваивани€
	friend bool operator==(const point& p1, const point& p2);
	friend bool operator!=(const point& p1, const point& p2);
	friend istream& operator>>(istream& in, point& p);
	friend ostream& operator<<(ostream& out, const point& p);
	point& operator=(const point& p);
private:
	double _x, _y;
};