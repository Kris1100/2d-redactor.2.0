#include "point.h"
//����������, �������!!!!
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

<<<<<<< HEAD
=======
bool point::is_elem_line(line& l) const
{
	double a, b, c;
	l.coef(a, b, c);
	if (_x * a + _y * b + c == 0)
		return true;
	return false;
}

bool point::is_elem_segment(const segment& s) const
{
	line l(s.get_start(), s.get_end());
	//åñëè íå ïðèíàäëåæèò ïðÿìîé, íà êîòîðîé ëåæèò îòðåçîê, òî âûõîäèì
	if (!is_elem_line(l))
		return false;
	double p1 = s.get_start().get_x();
	double p2 = s.get_end().get_x();
	double p = _x;
	//åñëè âåðòèêàëüíûé, òî ñðàâíèâàåì ïî êîîðäèíàòå ó
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

bool point::is_elem_ray(const ray& r) const
{
	point t(_x, _y);
	//åñëè ñîâïàäàåò ñ îáúÿâëåííûìè òî÷êàìè ëó÷à
	if (t == r.get_p() || t == r.get_begin())
		return true;
	//ïåðíàäëåæèò ëè ïðÿìîé, íà êîòîðîé ëåæèò ëó÷
	line l(r.get_begin(), r.get_p());
	if (!is_elem_line(l))
		return false;
	//÷òîáû èçáåæàòü êîïèïàñòà, äîáàâëåíû ïåðåìåííûå, õàðàêòåðèçóþùèå êîîðäèíàòû òî÷åê
	double tmp_b = r.get_begin().get_x();
	double tmp_p = r.get_p().get_x();
	double  tmp_t = _x;
	//ñëó÷àé ñ âåðòèêàëüíûì ëó÷îì
	if (r.get_begin().get_x() == r.get_p().get_x())
	{
		tmp_b = r.get_begin().get_y();
		tmp_p = r.get_p().get_y();
		tmp_t = _y;
	}
	//îòëè÷èÿ â áëîêàõ - òîëüêî â çíàêàõ áîëüøå/ìåíüøå
	//ïîýòîìó èñïîëüçóþ íîâóþ ïåðåìåííóþ, ÷òîáû èçáåæàòü êîïèïàñòà
	int sign = 1;
	//åñëè ââåðõ èëè âïðàâî
	if (tmp_b < tmp_p)
		sign = 1;
	//åñëè âíèç èëè âëåâî
	else if (tmp_b < tmp_p)
		sign = -1;
	if (tmp_t > tmp_b * sign || tmp_t > tmp_p * sign)
		return true;
	else
		return false;
}

bool point::is_elem_triangle(const triangle& abc) const
{
	segment ab = abc.get_ab();
	segment bc = abc.get_bc();
	segment ac = abc.get_ac();
	if (is_elem_segment(ab) || is_elem_segment(bc) || is_elem_segment(ac))
		return true;
	return false;
}

bool point::is_elem_polygon(const polygon& abz) const//check if works
{
	int n = abz.get_num();
	for (int i = 0; i < n; i++)
	{
		segment ab(abz.vertex[i % n], abz.vertex[(i + 1) % n]);
		if (is_elem_segment(ab))
			return true;
	}
	return false;
}

bool point::is_elem_circle(const circle& w) const
{
	point cntr = w.get_p();
	double r = w.get_r();
	if ((_x - cntr.get_x()) * (_x - cntr.get_x()) + 
		(_y - cntr.get_y()) * (_y - cntr.get_y()) - r * r == 0)
		return true;
	return false;
}

>>>>>>> aa7505c72e20659a07bdb3b5858f1256172644f4
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