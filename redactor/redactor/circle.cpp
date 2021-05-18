#include "circle.h"

circle::circle(double x, double y, double r)
{
	_p = point(x, y);
	set_r(r);
}

circle::circle(const circle& c) 
{
	_p = c.get_p();
	_r = c.get_r();
}

ostream& operator<<(ostream& out, const circle& c)
{
	out << "���������� ������ (" << c._p.get_x() << ", "
		<< c._p.get_y() << ")" << endl << "������: " << c._r << endl;
	return out;
}

istream& operator>>(istream& in, circle& c)
{
	double x, y, r;
	cout << "������� ���������� ������ � ������: ";
	in >> x >> y >> r;
	c._p = point(x, y);
	c.set_r(r);
	return in;
}

int circle::quarter() const //�����, ����� ���������� ������� ���, ����� ��� ���������� ��������, � �� �������� ���
							 //����� ��� ����� ��������
{
	if ((_p.get_x() - _r) > 0 && (_p.get_y() - _r) > 0) return 1;
	else if ((_p.get_x() + _r) < 0 && (_p.get_y() - _r) > 0) return 2;
	else if ((_p.get_x() + _r) < 0 && (_p.get_y() + _r) < 0) return 3;
	else if ((_p.get_x() - _r) > 0 && (_p.get_y() + _r) < 0) return 4;
	else return -1;
}

void circle::intersection() const
{    //�� ����������� ��� - ���������, ����� ��� � ����������
	if (_r * _r - (_p.get_x() * _p.get_x()) > 0)
		cout << "����� ����������� � ���� x:(0, " << sqrt(_r * _r - (_p.get_x() * _p.get_x())) << ")  " << endl;
	else if (_r * _r - (_p.get_y() * _p.get_y()) > 0)
		cout << "����� ����������� � ���� y:(" << sqrt(_r * _r - (_p.get_y() * _p.get_y())) << " ,0) " << endl;
	else cout << "��� ����������� � �����" << endl;
}

void circle::draw() 
{
	glColor3ub(220, 195, 232);
	//long long int a, b; do you really need it?
	//a = constants::width;
	//b = constants::height;
	int N = 300;
	int xp = _p.centerize().get_x();
	int yp = _p.centerize().get_y();
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 1; i <= N + 2; i++)
	{
		glVertex2f(xp + _r * 40 * cos(2 * 3.14 / N * i),
			yp + _r * 40 * sin(2 * 3.14 / N * i));
	}
	glEnd();
}

//line circle::tangent(point& p)  //входные данные меняются? если нет, то конст
//{
//	double a = -2 * _p.get_x() + p.get_x();
//	double b = -2 * _p.get_y() + p.get_y();
//	double c = pow(_p.get_x(), 2) + pow(_p.get_y(), 2) - pow(_r, 2);
//	return line(a, b, c);
//}