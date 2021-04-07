#include "point.h"

point::point(double x, double y)
{
	set_x(x);
	set_y(y);
}

int point::quarter()
{
	int res;
	if (_x >= 0 && _y >= 0)
		res=1;
	if (_x <= 0 && _y >= 0)
		res=2;
	if (_x <= 0 && _y <= 0)
		res=3;
	if (_x >= 0 && _y <= 0)
		res=4;
	if (_x == 0 && _y == 0)
		res = 0;
	return res;
}

double point::dist()
{
	double res;
	res = _x * _x + _y * _y;
	return sqrt(res);
}

bool point::bisector()
{
	bool f;
	if (abs(_x) == abs(_y))
		f = true;
	else
		f = false;
	return f;
}

bool point::is_element(line& l) const
{
	double a, b, c;
	l.coef(a, b, c);
	if (_x * a + _y * b + c == 0)
		return true;
	return false;
}

bool point::is_element(const segment& s) const
{
	line l(s.get_start(), s.get_end());
	//если не принадлежит прямой, на которой лежит отрезок, то выходим
	if (!is_element(l))
		return false;
	double p1 = s.get_start().get_x();
	double p2 = s.get_end().get_x();
	double p = _x;
	//если вертикальный, то сравниваем по координате у
	if (s.get_start().get_x() == s.get_end().get_x())
	{
		p1 = s.get_start().get_y();
		p2 = s.get_end().get_y();
		p = _y;
	}
	if (p >= p1 && p <= p2 || p >= p2 && p <= p1)
		return true;
	return false;
}

bool point::is_element(const ray& r) const
{
	point t(_x, _y);
	//если совпадает с объявленными точками луча
	if (t == r.get_p() || t == r.get_begin())
		return true;
	//пернадлежит ли прямой, на которой лежит луч
	line l(r.get_begin(), r.get_p());
	if (!is_element(l))
		return false;
	//чтобы избежать копипаста, добавлены переменные, характеризующие координаты точек
	double tmp_b = r.get_begin().get_x();
	double tmp_p = r.get_p().get_x();
	double  tmp_t = _x;
	//случай с вертикальным лучом
	if (r.get_begin().get_x() == r.get_p().get_x())
	{
		tmp_b = r.get_begin().get_y();
		tmp_p = r.get_p().get_y();
		tmp_t = _y;
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

bool point::is_element(const triangle& abc) const
{
	segment ab = abc.get_ab();
	segment bc = abc.get_bc();
	segment ac = abc.get_ac();
	if (is_element(ab) || is_element(bc) || is_element(ac))
		return true;
	return false;
}

bool point::is_element(const poligon& abz) const//check if works
{
	int n = abz.get_num();
	for (int i = 0; i < n; i++)
	{
		segment ab(abz.vertex[i % n], abz.vertex[(i + 1) % n]);
		if (is_element(ab))
			return true;
	}
	return false;
}

bool is_element(const circle& w) const
{
	point cntr = w.get_p();
	double r = w.get_r();
	if ((_x - cntr.get_x()) * (_x - cntr.get_x()) + 
		(_y - cntr.get_y()) * (_y - cntr.get_y()) - r * r == 0)
		return true;
	return false;
}

bool operator==(const point& p1, const point& p2)
{
	if (p1._x == p2._x && p1._y == p2._y)
		return true;
	return false;
}

bool operator!=(const point& p1, const point& p2)
{
	if (p1._x != p2._x || p1._y != p2._y)
		return true;
	return false;
}

istream& operator>>(istream& in, point& p)
{
	cin >> p._x >> p._y;
	return in;
}

ostream& operator<<(ostream& out, const point& p)
{
	cout << p._x << " " << p._y;
	return out;
}