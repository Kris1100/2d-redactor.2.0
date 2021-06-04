#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>
#include "point.h"
#include "line.h"
#include "math_const.h"
#include "Figure.h"
#include "glut-3.7.6-bin/glut.h"
using namespace std;

class circle : public figure
{
public:
	//Конструктор окружности
	circle(double x = 0.0, double y = 0.0, double r = 1.0);
	//Конструктор копирования
	circle(const circle& c);
	//Деструктор
	~circle();

	//Перезагрузка вывода                
	friend ostream& operator<<(ostream& out, const circle& c);
	//Перезагрузка ввода
	friend istream& operator>>(istream& in, circle& p);

	//Возвращает диаметр
	double get_d() const {
		return _r * 2;
	}
	//Возвращает радиус
	double get_r()const {
		return _r;
	}
	// Возвращает центр
	point get_p() const {
		return _p;
	}

	//Возвращает четверть, если окружность полностью в ней и -1 если лежит в окружности не полностью
	int quarter() const;
	//Возвращает длину окружности
	double length() const {
		return (get_r() * constants::pi * 2);
	}
	//Точки пересечения с осями
	void intersection() const; // может, тогда получить на вход точки и поменять их в функции, чтобы она была полезна
	//Возвращает касательную к окружности через данную точку
	line tangent(point &p);

	//Рисование окружности
	void draw();
	
	void mymenu();

private:
	point _p;
	double _r;
	//Сеттер радиуса
	void set_r(double r = 1.0) {
		_r = r;
	}
};
