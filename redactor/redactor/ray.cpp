#include "ray.h"

ray::ray(const point& begin, const point& p)
{
	if (p != begin)
	{
		_begin = begin;
		_p = p;
	}
	else
		throw "������������ ���������� � ����";
}

ifstream& operator>>(ifstream& in, ray& r)
{
	cout << "������� ���������� ������ ����:" << endl;
	cin >> r._begin;
	cout << "������� ������������ ����� �� ����:" << endl;
	cin >> r._p;
	if (r._begin == r._p)
		throw "������������ ���������� � ����";
	return in;
}

ostream& operator<<(ostream& out, const ray& r)
{
	cout << "����� ������ ����: " << r._begin << endl;
	cout << "������������ ����� �� ����: " << r._p << endl;
	return out;
}