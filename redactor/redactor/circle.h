#pragma once
#include <iostream>
#include <vector>
#include "point.h"
using namespace std;
class circle
{
public:
	//Перезагрузка вывода
	friend ostream& operator<<(ostream& out, const circle& c);
	//Перезагрузка ввода
	friend istream& operator>>(istream& in, circle& p)const;
	//Возвращает диаметр
	double get_d() const;
	//Конструктор окружности
	circle(point p, double r = 1) const;
	//Задание через уравнение !!НЕДОДЕЛАНО!!
	void equation(double a, double b, double r);
	//Сеттер центра
	void set_center(double x, double y);
	//Возвращает радиус
	double get_r()const;
	//Сеттер радиуса
	void set_r(double r);
	//Четверть, если окружность полностью в ней
	void quarter() const;
	//Возвращает длину окружности
	double length() const;

private:
	point _p;
	double _r;
};
