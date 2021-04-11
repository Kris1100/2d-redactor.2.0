#include "polygon.h"
#include "math_const.h"

//������������ � �����������

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

//�������

void polygon::set_point_array(point* vert) 
{
	//�� ��������� ���������� ���������� n- ��������, ������ �� ����� �� ������������ ��� ���������� ��-�� ����������� ���������. ���� ��� � ���������� ��������������
	vertex = vert;
	//��������� ��������� ����������
	int R = 1;
	//��������� ����
	double ang = 0;
	for (int i = 0; i < num_vert_; i++) {
		//��������� ���������� ��������� ����� - ���������� ������� � ������� � ����� (0,0), ����������� �� ���� ang ������ ������� �������
		vertex[i].set_x(R * round(cos(ang*constants::pi/180)*constants::rd)/constants::rd);
		vertex[i].set_y(R * round(sin(ang * constants::pi /180)*constants::rd)/constants::rd);
		//�������� ����
		ang +=(360 / num_vert_);
	}
}

void polygon::set_num(int num_vert)
{
	num_vert_ = num_vert;
}

//�������

int polygon::get_num()const
{
	return num_vert_;
}
point* polygon::get_vertexes() const {
	return vertex;
}

//�������� ������� ������

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
	//���������� ������� ������� ������ https://cpp.mazurok.com/tag/%D0%BF%D0%BB%D0%BE%D1%89%D0%B0%D0%B4%D1%8C-%D0%BC%D0%BD%D0%BE%D0%B3%D0%BE%D1%83%D0%B3%D0%BE%D0%BB%D1%8C%D0%BD%D0%B8%D0%BA%D0%B0/#:~:text=%D0%94%D0%BB%D1%8F%20%D1%82%D0%BE%D0%B3%D0%BE%2C%20%D1%87%D1%82%D0%BE%D0%B1%D1%8B%20%D0%B2%D1%8B%D1%87%D0%B8%D1%81%D0%BB%D0%B8%D1%82%D1%8C%20%D0%B5%D0%B3%D0%BE,%D0%BF%D1%80%D0%BE%D0%B8%D0%B7%D0%B2%D0%BE%D0%BB%D1%8C%D0%BD%D0%BE%D0%B3%D0%BE%20%D0%BC%D0%BD%D0%BE%D0%B3%D0%BE%D1%83%D0%B3%D0%BE%D0%BB%D1%8C%D0%BD%D0%B8%D0%BA%D0%B0%20%D0%BC%D0%BE%D0%B6%D0%BD%D0%BE%20%D0%BF%D1%80%D0%BE%D1%87%D0%B5%D1%81%D1%82%D1%8C%20%D0%B7%D0%B4%D0%B5%D1%81%D1%8C.
	double s1 = 0, s2 = 0, s = 0;                         
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
			myvector v1(vertex[i+1], vertex[i]);
			point p;
			if (i == num_vert_ - 2) p = vertex[0];
			else p = vertex[i + 2];
			myvector v2 (vertex[i + 1],p);
			//����� ������ ���������� �������� ������
			if (ang == -1)
				ang = angle(v1, v2);
			else
				if (ang != angle(v1, v2))
					return false;
		}
		//��������� �������� ��� ��������� �������, �� � ��� ������ ���������� � ������� �����
		segment s(vertex[num_vert_ - 1], vertex[0]);
		myvector v1(vertex[0], vertex[num_vert_-1]);
		myvector v2(vertex[0], vertex[1]);
		if (side != s.len())
			return false;
		if (ang != angle(v1, v2)&&ang!=angle(v1,v2)+constants::eps && ang!=angle(v1,v2)-constants::eps)
			return false;
		//������ ��������������� ��������
		s.~segment();
		v1.~myvector();
		v2.~myvector();
 		return true;
	}
}

//Friend �������

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