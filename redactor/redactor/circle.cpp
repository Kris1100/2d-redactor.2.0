#include "circle.h"
const double PI = 3.141592653589793238463; //� ����� �������������� ����� ����������

circle::circle(double x, double y, double r) 
{
	_p = new point(x, y);
	set_r(r);
}

ostream& operator<<(ostream& out, const circle& c) 
{
	out << "���������� ������ (" << c._p->get_x() << ", " 
		<< c._p->get_y() << ")" << endl << "������: " << c._r << endl;
	return out;
}

istream& operator>>(istream& in, circle& c) 
{
	double x, y, r;
	cout << "������� ���������� ������ � ������: ";
	in >> x >> y >> r;
	c._p = new point(x, y);
	c.set_r(r);
	return in;
}


int circle::quarter() const //�����, ����� ���������� ������� ���, ����� ��� ���������� ��������, � �� �������� ���
                             //����� ��� ����� ��������
{
	if ((_p->get_x() - _r) > 0 && (_p->get_y() - _r) > 0) return 1;
	else if ((_p->get_x() + _r) < 0 && (_p->get_y() - _r) > 0) return 2;
	else if ((_p->get_x() + _r) < 0 && (_p->get_y() + _r) < 0) return 3;
	else if ((_p->get_x() - _r) > 0 && (_p->get_y() + _r) < 0) return 4;
	else return -1;
}


void circle::intersection() const 
{    //�� ����������� ��� - ���������, ����� ��� � ����������
	if (_r * _r - (_p->get_x() * _p->get_x()) > 0)
		cout << "����� ����������� � ���� x:(0, " << sqrt(_r * _r - (_p->get_x() * _p->get_x())) << ")  " << endl;
	else if (_r * _r - (_p->get_y() * _p->get_y()) > 0) 
		cout << "����� ����������� � ���� y:(" << sqrt(_r * _r - (_p->get_y() * _p->get_y())) << " ,0) " << endl;
	else cout << "��� ����������� � �����" << endl;
}


line circle::tangent(point& p) //������� ������ ��������? ���� ���, �� �����
{
	double a = -2 * _p->get_x()+p.get_x();
	double b = -2 * _p->get_y()+p.get_y();
	double c = pow(_p->get_x(), 2) + pow(_p->get_y(), 2) - pow(_r, 2);
	return line(a, b, c);
}