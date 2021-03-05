//#pragma once
//#include <iostream>
//#include <vector>
//#include "point.h"
//using namespace std;
//class circle
//{
//public:
//	//Перезагрузка вывода
//	friend ostream& operator<<(ostream& out, const circle& c);
//	//Перезагрузка ввода
//	friend istream& operator>>(istream& in, circle& p);
//	//Возвращает диаметр
//	double get_d() const;
//	//Конструктор окружности
//	circle(double x = 0.0, double y = 0.0, double r = 1.0);
//	//Задание через уравнение !!НЕДОДЕЛАНО!!
//	void equation(double a = 0.0, double b = 0.0, double r = 1.0);
//	//Сеттер центра
//	void set_center(point* p);
//	//Возвращает радиус
//	double get_r()const;
//	//Сеттер радиуса
//	void set_r(double r = 1.0);
//	//Четверть, если окружность полностью в ней
//	void quarter() const;
//	//Возвращает длину окружности
//	double length() const;
//	//
//	void intersection() const;
//
//
//private:
//	point* _p;
//	double _r;
//};
