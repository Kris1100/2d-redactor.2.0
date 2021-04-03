#include "ray.h"

ray::ray(const point& begin, const point& p)
{
	if (p != begin)
	{
		_begin = begin;
		_p = p;
	}
}

bool ray::is_element(const point& t)
{
	//если совпадает с объявленными точками луча
	if (t == _p || t == _begin)
		return true;
	//пернадлежит ли прямой, на которой лежит луч
	line l(_begin, _p);
	double a, b, c;
	l.coef(a, b, c);
	if (a * t.get_x() + b * t.get_y() + c != 0)
		return false;
	//чтобы избежать копипаста, добавлены переменные, характеризующие координаты точек
	double tmp_b, tmp_p, tmp_t;
	//случай с вертикальным лучом
	if (_begin.get_x() == _p.get_x())
	{
		tmp_b = _begin.get_y();
		tmp_p = _p.get_y();
		tmp_t = t.get_y();
	}
	//остальные случаи
	else
	{
		tmp_b = _begin.get_x();
		tmp_p = _p.get_x();
		tmp_t = t.get_x();
	}
	//отличия в блоках - только в знаках больше/меньше
	//поэтому использую новую переменную, чтобы избежать копипаста
	int sign = 1;
	//если вверх или вправо
	if (tmp_b < tmp_p)
		sign = 1;
	//если вниз или влево
	else if (tmp_b < tmp_p)
		sign = -1;
	if (tmp_t > tmp_b * sign || tmp_t > tmp_p * sign)
		return true;
	else
		return false;
}