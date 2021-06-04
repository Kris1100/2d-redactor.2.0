#pragma once
#include "point.h"
#include <cmath>
#include <math.h>
#include <cassert>
#include "Figure.h"
using namespace std;
//Класс отрезок
class segment : public figure
{
public:
	//Конструктор отрезка
	segment(const point& p1, const point& p2);
	//Конструктор по умолчанию необходим для класса vector
	segment() {};
	//Конструктор копирования
	segment(const segment& s);
	//Деструктор
	~segment() {}
	//Получить ссылку на начальную точку (начальная - p1_, в классе точка нет разницы, какая будет начальной)
	point get_start() const {  
		return p1_;
	}
	//Ссылка на конечную точку
	point get_end() const {
		return p2_;
	}
	//Задать крайние точки
	void set_extm_points(const point& p1,const point& p2);
	//Длина отрезка
	double len() const;
	//Координаты середины отрезка
	point middle() const;
	void is_correct();

	//Нарисовать отрезок
	void draw();
	void mymenu();

	//Фрэнд функции
	//Опретатор ввода
	friend std::istream& operator>>(std::istream& in, segment& s);
protected:
	point p1_;
	point p2_;
};

