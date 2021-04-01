#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include "point.h"
#include "circle.h"
using namespace std;

class my_round : public circle
{
public:
	//Перезагрузка вывода               //частный случай - радиус 0. что если радиус отрицательный?(есть не слишком умные пользователи)
	friend ostream& operator<<(ostream& out, const my_round& c);
	//Перезагрузка ввода
	friend istream& operator>>(istream& in, my_round& p);
	//Конструктор окружности
	my_round(double x = 0.0, double y = 0.0, double r = 1.0);
	//Возвращает площадь круга           //не повторяются ли функции из родительского класса?
	double get_square() const;
	//Возвращает площадь сегмента, аргумент - угол в радианах
	double get_square_of_segment(double a = 1) const;
	void quarter() const;
	//деструктор? наследуется, но вызывать виртуально
	//сеттеры не нужны? конструктор не инициализатор

	point* _p;//почему не приватные?
	double _r;
};
