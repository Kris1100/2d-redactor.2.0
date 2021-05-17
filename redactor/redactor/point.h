#pragma once
#include <iostream>
#include <cmath>
#include "Figure.h"
#include "math_const.h"
#include "glut-3.7.6-bin/glut.h"
using namespace std;

class point: public figure
{
public:
	//Конструктор точки
	point(double x = 0, double y = 0);
	//Деструктор
	~point() {};
	//Задать координату х
	void set_x(double x) { _x = x; }
	//Задать координату у
	void set_y(double y) { _y = y; }

	//Получить координату у
	double get_y() const { return _y; }
	//Получить координату х
	double get_x() const { return _x; }

	//Возвращает # четверти, лежит данная точка, 0 - в случае, если точка принадлежит началу координат
	int quarter();
	//Возвращает расстояние от начала координат
	double dist();
	//Лежит ли точка на биссектрисе координатной плоскости
	bool bisector();
	//Центеризация координат
	point centerize();
	//
	void draw();

	//перегрузка операторов равенства, вводва, вывода,присваивания
	friend bool operator==(const point& p1, const point& p2);
	friend bool operator!=(const point& p1, const point& p2);
	friend istream& operator>>(istream& in, point& p);
	friend ostream& operator<<(ostream& out, const point& p);
	point& operator=(const point& p);
private:
	double _x, _y;
};