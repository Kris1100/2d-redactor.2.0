#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include "point.h"
using namespace std;
class my_round
{
public:
	//Перезагрузка вывода
	friend ostream& operator<<(ostream& out, const my_round& c);
	//Перезагрузка ввода
	friend istream& operator>>(istream& in, my_round& p);
	//Возвращает диаметр
	double get_d() const;
	//Конструктор окружности
	my_round(double x = 0.0, double y = 0.0, double r = 1.0);
	//Задание через уравнение
	void equation(double a = 0.0, double b = 0.0, double r = 1.0);
	//Возвращает радиус
	double get_r()const;
	//Сеттер радиуса
	void set_r(double r = 1.0);
	//Четверть, если окружность полностью в ней
	void quarter() const;
	//Возвращает длину окружности
	double length() const;
	//Точки пересечения с осями
	void intersection() const;
	//Возвращает площадь круга
	double get_square() const;
	//Возвращает площадь сегмента, аргумент - угол в радианах
	double get_square_of_segment(double a = 1) const;

	point get_p();



private:
	point* _p;
	double _r;
};
