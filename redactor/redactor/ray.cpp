#include "ray.h"

ray::ray(const point& begin, const point& p)
{
	if (p != begin)
	{
		_begin = begin;
		_p = p;
	}
}

<<<<<<< HEAD
bool ray::is_elem_line(line& l) const
{
	if (_begin.is_elem_line(l) && _p.is_elem_line(l))
=======
bool ray::is_element(const point& t) const
{
	//���� ��������� � ������������ ������� ����
	if (t == _p || t == _begin)
>>>>>>> 6e2314bef907c45c389be0c4b4753a8f3afd65e7
		return true;
	//����������� �� ������, �� ������� ����� ���
	line l(_begin, _p);
	double a, b, c;
	l.coef(a, b, c);
	if (a * t.get_x() + b * t.get_y() + c != 0)
		return false;
	//����� �������� ���������, ��������� ����������, ��������������� ���������� �����
	double tmp_b, tmp_p, tmp_t;
	//������ � ������������ �����
	if (_begin.get_x() == _p.get_x())
	{
		tmp_b = _begin.get_y();
		tmp_p = _p.get_y();
		tmp_t = t.get_y();
	}
	//��������� ������
	else
	{
		tmp_b = _begin.get_x();
		tmp_p = _p.get_x();
		tmp_t = t.get_x();
	}
	//������� � ������ - ������ � ������ ������/������
	//������� ��������� ����� ����������, ����� �������� ���������
	int sign = 1;
	//���� ����� ��� ������
	if (tmp_b < tmp_p)
		sign = 1;
	//���� ���� ��� �����
	else if (tmp_b < tmp_p)
		sign = -1;
	if (tmp_t > tmp_b * sign || tmp_t > tmp_p * sign)
		return true;
	else
		return false;
}