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
	//Конструктор окружности
	circle(double x = 0.0, double y = 0.0, double r = 1.0);
	//Перезагрузка вывода                
	friend ostream& operator<<(ostream& out, const circle& c);
	//Перезагрузка ввода
	friend istream& operator>>(istream& in, circle& p);
	//Возвращает диаметр
	double get_d() const;
	//Возвращает радиус
	double get_r()const;
	// Возвращает центр
	point get_p() const;
	//Возвращает четверть, если окружность полностью в ней и -1 если лежит в окружности не полностью
	int quarter() const;
	//Возвращает длину окружности
	double length() const;
	//Точки пересечения с осями
	void intersection() const; // может, тогда получить на вход точки и поменять их в функции, чтобы она была полезна
	//Возвращает касательную к окружности через данную точку
	line tangent(point &p) ;
	//деструктор?
private:
	point* _p;
	double _r;
	//Сеттер радиуса
	void set_r(double r = 1.0); 
};
