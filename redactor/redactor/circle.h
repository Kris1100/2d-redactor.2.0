#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>
#include "point.h"
#include "line.h"
using namespace std;

class circle
{
public:	
	//Конструктор окружности
	circle(double x = 0.0, double y = 0.0, double r = 1.0);//что если радиус 0? это точка? а если отрицательный?
	//дкструктор
	~circle {}
	
	//Перезагрузка вывода                
	friend ostream& operator<<(ostream& out, const circle& c);
	//Перезагрузка ввода
	friend istream& operator>>(istream& in, circle& p);
	//Возвращает диаметр
	double get_d() const { return _r * 2; }
	//Возвращает радиус
	double get_r()const { return _r; }
	// Возвращает центр
	// !!TODO переименовать
	point get_p() const { return _p; }
	
	//Возвращает номер четверти, если окружность полностью в ней и -1 если лежит в окружности не полностью
	int quarter() const;
	//Возвращает длину окружности
	double length() const {	return (get_r() * M_PI * 2); }
	//Точки пересечения с осями
	// !!TODO может, тогда получить на вход точки и поменять их в функции, чтобы она была полезна
	void intersection() const; 
	//Возвращает касательную к окружности через данную точку
	line tangent(const point &p) ;
private:
	point _p; //что такое р?? может переименовать в center/centr/cntr?
	double _r;
	//Сеттер радиуса
	void set_r(double r = 1.0) { _r = r; }
};
