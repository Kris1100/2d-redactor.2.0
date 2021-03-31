#pragma once
#include "point.h"
#include <cmath>
#include <math.h>

// ласс отрезок
class segment
{
public:
	// онструктор отрезка                  //если точки совпадают??
	segment(point& p1, point& p2) {
		set_extm_points(p1, p2);
	}
	segment() {}
	//ƒеструктор
	~segment() {}
	//«адать крайние точки
	void set_extm_points(point& p1, point& p2);//приватна€ 
	                                           //мне кажетс€, что уточнение про крайние лишнее в названии(хот€, может, и нет) - нужно проконсультироватьс€
	//ѕолучить ссылку на начальную точку (начальна€ - p1_, в классе точка нет разницы, кака€ будет начальной)
	point& get_start() {   //константные геттеры
		return p1_;
	}
	//—сылка на конечную точку
	point& get_end() {
		return p2_;
	}
	//ƒлина отрезка
	double len();
	// оординаты середины отрезка
	point middle();

protected:
	point p1_;
	point p2_;
};

