#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include "point.h"
#include "line.h"
using namespace std;

class circle
{
public:
	//Перезагрузка вывода                 //последовательность функций? разделение на смысловые блоки?
	friend ostream& operator<<(ostream& out, const circle& c);
	//Перезагрузка ввода
	friend istream& operator>>(istream& in, circle& p);
	//Возвращает диаметр
	double get_d() const;
	//Конструктор окружности
	circle(double x = 0.0, double y = 0.0, double r = 1.0);
	/*Задание через уравнение
	void equation(double a = 0.0, double b = 0.0, double r = 1.0);
	*/
	//Возвращает радиус
	double get_r()const;
	//Сеттер радиуса
	void set_r(double r = 1.0); //прриватная?
	//Четверть, если окружность полностью в ней
	void quarter() const;
	//Возвращает длину окружности
	void length() const;
	//Точки пересечения с осями
	void intersection() const; // может, тогда получить на вход точки и поменять их в функции, чтобы она была полезна

	point get_p(); //конст?
	//Возвращает касательную к окружности через данную точку
	line tangent(point &p);
	//деструктор?
private:
	point* _p;
	double _r;
};
