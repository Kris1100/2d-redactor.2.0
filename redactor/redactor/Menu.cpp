#include "Menu.h"

void print_menu(int num, int col)
{
	int col2;
	if (col == 1)
		col2 = 7;
	else
		col2 = 1;
	system("cls");
	SetColor(15, 1);
	cout << "\n";
	SetColor(1, 15);
	if (num < 0)
		num = 7;
	if (num > 7)
		num = 0;
	if (num == 0)
	{
		SetColor(col, col2);
		cout << "0. �����\n";
		SetColor(1, 15);
	}
	else
		cout << "0. �����\n";
	if (num == 1)
	{
		SetColor(col, col2);
		cout << "1. �����\n";
		SetColor(1, 15);
	}
	else
		cout << "1. �����\n";
	if (num == 2)
	{
		SetColor(col, col2);
		cout << "2. ������\n";
		SetColor(1, 15);
	}
	else
		cout << "2. ������\n";
	if (num == 3)
	{
		SetColor(col, col2);
		cout << "3. ����������\n";
		SetColor(1, 15);
	}
	else
		cout << "3. ����������\n";
	if (num == 4)
	{
		SetColor(col, col2);
		cout << "4. �����������\n";
		SetColor(1, 15);
	}
	else
		cout << "4. �����������\n";
	if (num == 5)
	{
		SetColor(col, col2);
		cout << "5. �������������\n";
		SetColor(1, 15);
	}
	else
		cout << "5. �������������\n";
	if (num == 6)
	{
		SetColor(col, col2);
		cout << "6. �������\n";
		SetColor(1, 15);
	}
	else
		cout << "6. �������\n";
	if (num == 7)
	{
		SetColor(col, col2);
		cout << "7. ������\n";
		SetColor(1, 15);
	}
	else
		cout << "7. ������\n";
}

void print_point(int num)
{
	double x, y;
	cout << "������� ���������� �����" << endl;
	cin >> x >> y;
	point p(x, y);
	cout << "������ ����� ����� � ";
	double a=p.quarter();
	cout << a << "��������" << endl;
	double b = p.dist();
	cout << "���������� �� ������ ����� �� ������ ���������: " << b << endl;
	if (p.bisector() == true) 
		cout << "������ ����� ����� �� ����������� ������������ ���������";
	else
		cout << "������ ����� �� ����� �� ����������� ������������ ���������";
	cout << endl;
}

void print_line(int num)
{
	double x1, y1, x2, y2;
	cout << "������� ���������� ���� ����� ��� ������� ������" << endl;
	cout << "������� ���������� ������ �����" << endl;
	cin >> x1 >> y1;
	cout << "������� ���������� ������ �����" << endl;
	cin >> x2 >> y2;
	point p1(x1, y1);
	point p2(x2, y2);
	line l(p1, p2);
	l.print();
	l.print_param();
	myvector v = l.normal_vector();
	cout <<"���������� ������� �������: "<< v;
}

void print_polygon(int num)
{
	int n;
	cout << "������� ���������� ������ ";
	cin >> n;
	polygon p(n);
	cin >> p;
	cout << p;
	double per = p.perimetr();
	cout << "�������� " << per << endl;
	double sq = p.area();
	cout << "������� " << sq << endl;
	bool f = p.is_convex();
	if (f)
		cout << "������������� ��������" << endl;
	else
		cout << "������������� ����������" << endl;
	if (p.is_regular(f))
		cout << "������������� ����������" << endl;
	else
		cout << "������������� �� �������� ����������" << endl;
}

void print_circle(int num)
{
	circle c;
	cin >> c;
	cout << c;
	c.quarter();
	c.intersection();
	c.length();
}

void print_segment(int num)
{
	point p1, p2;
	double x1, x2, y1, y2;
	cout << "������� ���������� �����: ";
	cin >> x1 >> y1;
	cout << "������� ���������� �����: ";
	cin >> x2 >> y2;
	p1.set_x(x1);
	p1.set_y(y1);
	p2.set_x(x2);
	p2.set_y(y2);
	segment s(p1, p2);
	cout << "����� ������� " << s.len();
}

void print_triangle(int num)
{
	triangle abc;
	abc.init();
	if (abc.is_equilateral())
		cout << "����������� ��������������" << endl;
	if (abc.is_isosceles())
		cout << "����������� ��������������" << endl;
	if (abc.is_right())
		cout << "����������� �������������" << endl;
	cout << "�������: " << abc.area() << endl;
	cout << "��������: " << abc.perimetr() << endl;
	cout << "������ ��������� ����������: " << abc.radius_inside() << endl;
	cout << "������ ��������� ����������: " << abc.radius_outside() << endl;
	//abc.~triangle();
}

void print_vector(int num)
{
	point p1, p2;
	double x1, x2, y1, y2;
	cout << "������� ���������� ��������� �����: ";
	cin >> x1 >> y1;
	cout << "������� ���������� �������� �����: ";
	cin >> x2 >> y2;
	p1.set_x(x1);
	p1.set_y(y1);
	p2.set_x(x2);
	p2.set_y(y2);
	myvector v(p1, p2);
	cout << "����� ������� " << v.len();
}

void SetColor(int text, int Fon)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, (Fon << 4) + text);
}