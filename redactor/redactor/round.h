#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include "point.h"
#include <circle.h>
using namespace std;
class my_round : public circle
{
public:
	//Перезагрузка вывода
	friend ostream& operator<<(ostream& out, const my_round& c);
	//Перезагрузка ввода
	friend istream& operator>>(istream& in, my_round& p);
	//Конструктор окружности
	my_round(double x = 0.0, double y = 0.0, double r = 1.0);
	//Возвращает площадь круга
	double get_square() const;
	//Возвращает площадь сегмента, аргумент - угол в радианах
	double get_square_of_segment(double a = 1) const;
	void quarter() const;

	point* _p;
	double _r;
};
