#include "polygon.h"

polygon::polygon(int num_vert)
{
	if (num_vert < 3)
		num_vert = 3;
	set_num(num_vert);
	point* vert = new point[num_vert];
	set_point_array(vert);                  
}

polygon::~polygon()
{
	delete[] vertex;
	vertex = nullptr;
}

std::istream& operator>>(istream& in, polygon& p)
{
	double x, y;
	cout << "������� ���������� " << p.num_vert_ << " ������";
	for (int i = 0; i < p.num_vert_; i++)
	{
		cin >> x >> y;
		p.vertex[i].set_x(x);
		p.vertex[i].set_y(y);
	}
	return in;
}

std::ostream& operator<<(ostream& out, polygon& p)
{
	out << "���������� ����� " << p.num_vert_ << endl;
	for (int i = 0; i < p.num_vert_; i++)
	{
		out << "x= " << p.vertex[i].get_x() << " y= " << p.vertex[i].get_y() << endl;
	}
	return out;
}

void polygon::set_point_array(point* vert) 
{
	vertex = vert;
}

void polygon::set_num(int num_vert)
{
	num_vert_ = num_vert;
}

int polygon::get_num()const
{
	return num_vert_;
}

double polygon::perimetr() const
{
	double p = 0;
	for (int i = 0; i < num_vert_ - 1; i++)
	{
		segment s(vertex[i], vertex[i + 1]);
		p += s.len();
	}
	segment s(vertex[num_vert_ - 1], vertex[0]);
	p += s.len();
	s.~segment();
	return p;
}

double polygon::area() const
{
	double s1 = 0, s2 = 0, s = 0;                          // ����� �������� ����������� � ����� �����: � �������, ��� ���������
	for (int i = 0; i < num_vert_ - 1; i++)
	{
		s1 += vertex[i].get_x() * vertex[i + 1].get_y();
	}
	s1 += vertex[0].get_y() * vertex[num_vert_ - 1].get_x();
	for (int i = 0; i < num_vert_ - 1; i++)
	{
		s2 += vertex[i + 1].get_x() * vertex[i].get_y();
	}
	s2 += vertex[num_vert_ - 1].get_y() * vertex[0].get_x();
	s = 0.5 * abs(s1 - s2);
	return s;
}

void polygon::print() const
{
	for (int i = 0; i < num_vert_; i++)
	{
		cout << "x= " << vertex[i].get_x() << " y= " << vertex[i].get_y() << endl;
	}
}

bool polygon::is_convex() const
{
	//������������� ����� �������� ���� ��� ��� ������ � ������ ������ ���������������� ������ 
	//���������� ������� ������ � ���� � �� �� �������. ��� ������ �������������� ������ �������
	//������� ������� ����� ������ ������, � ��� ������ �� ������� - �������.
	//��� �������� ������ ���(�������� ������� � total) �������� ����� �������������, � ��� �������� ������� - �������������.
	int sign = 0;
	//���������� ��� ������ ������, � ������� ����� ���������� ����������
	for (int i = 0; i < num_vert_ - 2; i++)
	{
		//������� ��� ������� ����� ��� ������� (���� ������� �����)
		myvector v1(vertex[i], vertex[i + 1]);
		myvector v2(vertex[i + 1], vertex[i + 2]);
		//��������� ��������� ������������ ������ ��������
		double total = v1.get_x() * v2.get_y() - v1.get_y() * v2.get_x();
		//���������, ����������� �� ����
		if (sign == 0)
		{
			if (total < 0)
				sign = -1;
			else
				sign = 1;
		}
		else
			if (total * sign < 0)
				return false;
	}
	//�������� ������������� ��� ��������� ������, ������ ���� �����
	myvector v1(vertex[num_vert_ - 1], vertex[0]);
	myvector v2(vertex[0], vertex[1]);
	myvector v3(vertex[num_vert_ - 2], vertex[num_vert_ - 1]);
	double total = v1.get_x() * v2.get_y() - v1.get_y() * v2.get_x();
	if (total * sign < 0)
		return false;
	total = v3.get_x() * v1.get_y() - v3.get_y() * v1.get_x();
	if (total * sign < 0)
		return false;
	v1.~myvector();
	v2.~myvector();
	v3.~myvector();
	return true;
}

bool polygon::is_regular(bool convexity) const
{
	//�������� �� ����������. ���������� ������������� �� �������� ����������.
	//������������� �������� ����������, ���� ��� ��� ������� � ���� �����
	if (not convexity)
		return false;
	else
	{
		double side = -1; double ang = -1;
		//��������� �� ���� ��������, ����� ���������
		for (int i = 0; i < num_vert_ - 1; i++)
		{
			segment s(vertex[i], vertex[i + 1]);
			//���� �� ������ ��� ��������� ����� �������, �� ��� ���� �� � ��� �� ���������. ������� ������� (������)
			if (side == -1)
				side = s.len();
			else
				//���� ��������� ������� �� ����� �������, �� ������������� ������������
				if (side != s.len())
					return false;
			//������� ��� �������, ����� �������� ����� ���������� ����
			myvector v1(vertex[i], vertex[i + 1]);
			myvector v2(vertex[i + 1], vertex[i + 2]);
			//����� ������ ���������� �������� ������
			if (ang == -1)
				ang = angle(v1, v2);
			else
				if (ang != angle(v1, v2))
					return false;
		}
		//��������� �������� ��� ��������� �������, �� � ��� ������ ���������� � ������� �����
		segment s(vertex[num_vert_ - 1], vertex[0]);
		myvector v1(vertex[num_vert_ - 1], vertex[0]);
		myvector v2(vertex[0], vertex[1]);
		if (side != s.len())
			return false;
		if (ang != angle(v1, v2))
			return false;
		//������ ��������������� ��������
		s.~segment();
		v1.~myvector();
		v2.~myvector();
 		return true;
	}
}