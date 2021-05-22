#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include "point.h"
#include "circle.h"
#include "Figure.h"
using namespace std;

class my_round : public circle
{
public:
	//Конструктор круга
	my_round(double x = 0.0, double y = 0.0, double r = 1.0);

	//Перезагрузка вывода               //частный случай - радиус 0. что если радиус отрицательный?(есть не слишком умные пользователи)
	friend ostream& operator<<(ostream& out, const my_round& c);
	//Перезагрузка ввода
	friend istream& operator>>(istream& in, my_round& p);

	//Возвращает площадь сегмента, аргумент - угол в радианах
	double get_square_of_segment(double a = 1) const;

	void draw();
	
private:
	point _p;
	double _r;
	//Сеттер радиуса
	void set_r(double r = 1.0) {
		_r = r;
	}
};
