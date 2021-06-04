﻿#include "Triangle.h"

triangle::triangle()
{
	point* vert = new point[3];
	vertex = vert;
}

triangle::triangle(const point* vert)
{
	point* tmp_vert = new point[3];
	vertex = tmp_vert;
	vertex[0] = vert[0];
	vertex[1] = vert[1];
	vertex[2] = vert[2];
}

void triangle::set_vertex(const point& a, const point& b, const point& c)
{
	vertex[0] = a;
	vertex[1] = b;
	vertex[2] = c;
}

bool triangle::exists() const
{
	if (vertex[0] == vertex[1] || vertex[1] == vertex[2] || vertex[2] == vertex[0])
		return false;
	line l(vertex[0], vertex[1]);
	double a, b, c;
	l.coef(a, b, c);
	double x = vertex[2].get_x(), y = vertex[2].get_y();
	if (abs(a * x + b * y + c) <= 0.00000001)
		return false;
	return true;
}

bool triangle::is_equilateral() const
{
	if (vertex[0] == vertex[1] || vertex[1] == vertex[2] || vertex[2] == vertex[0])
		throw "error";
	segment ab(vertex[0], vertex[1]);
	segment bc(vertex[1], vertex[2]);
	segment ac(vertex[0], vertex[2]);
	if (abs(ab.len() - bc.len()) <= constants::eps &&
		abs(ab.len() - ac.len()) <= constants::eps)
		return true;
	return false;
}

bool triangle::is_isosceles() const
{
	if (vertex[0] == vertex[1] && vertex[1] == vertex[2])
		throw "error";
	if (vertex[0] == vertex[1] || vertex[1] == vertex[2] || vertex[2] == vertex[0])
		return true;
	segment ab(vertex[0], vertex[1]);
	segment bc(vertex[1], vertex[2]);
	segment ac(vertex[0], vertex[2]);
	if (abs(ab.len() - bc.len()) <= constants::eps ||
		abs(ab.len() - ac.len()) <= constants::eps ||
		abs(ac.len() - bc.len()) <= constants::eps)
		return true;
	return false;
}

bool triangle::is_right() const
{
	if (!exists())
		return false;
	segment ab(vertex[0], vertex[1]);
	segment bc(vertex[1], vertex[2]);
	segment ac(vertex[0], vertex[2]);
	if (ab.len() < bc.len())
		swap(ab, bc);
	if (ab.len() < ac.len())
		swap(ab, ac);
	double kat1 = ac.len(), kat2 = bc.len();
	double hyp = ab.len();
	if (abs(kat1 * kat1 + kat2 * kat2 - hyp * hyp) < constants::eps)
		return true;
	return false;
}

double triangle::radius_inside() const
{
	if (!exists())
		throw "Вырожденный случай";
	return 2 * area() / perimetr();
}

double triangle::radius_outside() const
{
	if (!exists())
		throw "Вырожденный случай";
	double abc_square = area();
	segment ab(vertex[0], vertex[1]);
	segment bc(vertex[1], vertex[2]);
	segment ac(vertex[0], vertex[2]);
	return ab.len() * bc.len() * ac.len() / (4 * abc_square);
}

bool triangle::is_inside(const point& p) const
{
	if (!exists())
		return false;
	double a, b, c;
	int count = 0;
	for (int i = 0; i < 3; i++)
	{
		line l(vertex[i], vertex[(i + 1) % 3]);
		l.coef(a, b, c);
		point tmp = vertex[(i + 2) % 3];
		if (a * p.get_x() + b * p.get_y() + c < 0 && a * tmp.get_x() + b * tmp.get_y() + c < 0 ||
			a * p.get_x() + b * p.get_y() + c > 0 && a * tmp.get_x() + b * tmp.get_y() + c > 0)
		{
			count++;
		}
	}
	if (count == 3)
		return true;
	return false;
}

segment triangle::middle_line(const segment& ab, const segment& bc) const
{
	segment l(ab.middle(), bc.middle());
	return l;
}

segment triangle::median(const point& a, const segment& bc) const
{
	segment l(a, bc.middle());
	return l;
}

point* triangle::get_vertex() const
{
	point* vert = new point[3];
	vert[0] = vertex[0];
	vert[1] = vertex[1];
	vert[2] = vertex[2];
	return vert;
}

std::istream& operator>>(istream& in, triangle& t)
{
	double x, y;
	cout << "Введите координаты " << 3 << " вершин:" << endl;
	for (int i = 0; i < 3; i++)
	{
		cin >> x >> y;
		t.vertex[i].set_x(x);
		t.vertex[i].set_y(y);
	}
	return in;
}

void triangle::draw()
{
	int x1, x2, x0, y1, y2, y0;

	x0 = vertex[0].centerize().get_x();
	y0 = vertex[0].centerize().get_y();
	x1 = vertex[1].centerize().get_x();
	y1 = vertex[1].centerize().get_y();
	x2 = vertex[2].centerize().get_x();
	y2 = vertex[2].centerize().get_y();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
	glVertex2f(x0, y0);
	glColor3ub(205, 164, 222);
	glVertex2f(x1, y1);
	glVertex2f(x1, y1);
	glColor3ub(88, 84, 171);
	glVertex2f(x2, y2);
	glVertex2f(x2, y2);
	glColor3ub(255, 255, 255);
	glVertex2f(x0, y0);
	glEnd();
}

void triangle::mymenu()
{
	ifstream in("triangle.txt");
	vector<string> commands;
	while (in)
	{
		string s = "";
		getline(in, s, '\n');
		commands.push_back(s);
	}
	if (commands[commands.size() - 1] == "" || commands[commands.size() - 1] == "\n")
		commands.pop_back();
	SetColor(1, 15);
	int item = 0;
	print_inmenu(0, 1, commands);
	if (not this->is_created)
	{
		cin >> *this;
		this->is_created = true;
	}
	while (true)
	{
		int key = _getch();

		if (key == 13)
		{
			switch (item)
			{
			case 0:
			{
				in.close();
				cout << "Работа завершена, перейдите в главное меню" << endl;
				return;
			}
			case 1:
			{
				cin >> *this;
			}
			break;
			case 2:
			{
				bool flag = false;
				try
				{
					flag = is_equilateral();
					if (flag)
						cout << "Треугольник равносторонний" << endl;
					else
						cout << "Треугольник не является расносторонним" << endl;
				}
				catch (...)
				{
					cout << "Невозможно определить" << endl;
				}
			}
			break;
			case 3:
			{
				bool flag = false;
				try
				{
					flag = is_isosceles();
					if (flag)
						cout << "Треугольник равнобедренный" << endl;
					else
						cout << "Треугольник не является равнобедренным" << endl;
				}
				catch (...)
				{
					cout << "Невозможно определить" << endl;
				}
			}
			break;
			case 4:
			{
				if (is_right())
					cout << "Треугольник прямоугольный" << endl;
				else
					cout << "Треугольник не является прямоугольным" << endl;
			}
			break;
			case 5:
			{
				cout << "Площадь: " << area() << endl;
			}
			break;
			case 6:
			{
				cout << "Периметр: " << perimetr() << endl;
			}
			break;
			case 7:
			{
				double rad = 0;
				cout << "Радиус вписанной окружности";
				try
				{
					rad = radius_inside();
					cout << ": " << rad << endl;
				}
				catch (...)
				{
					cout << " неопределён" << endl;
				}
			}
			break;
			case 8:
			{
				double rad = 0;
				cout << "Радиус описанной окружности";
				try
				{
					rad = radius_outside();
					cout << ": " << rad << endl;
				}
				catch (...)
				{
					cout << " неопределён" << endl;
				}
			}
			break;
			case 9:
			{
				point p;
				cin >> p;
				if (is_inside(p))
					cout << "Точка внутри треугольника" << endl;
				else
					cout << "Точка снаружи" << endl;
			}
			break;
			case 10:
			{
				if (not this->is_drawn)
				{
					add_draw(*this);
					cout << "Объект успешно добавлен в очередь на отрисовку, вы увидите его, когда завершите работу";
					this->is_drawn = true;
				}
				else
				{
					cout << "Объект уже в очереди на отрисовку";
				}
			}
			break;
			case 11:
			{
				if (this->is_drawn)
				{
					roll_back_draw();
					this->is_drawn = false;
					cout << "Объект успешно удален из очерди на отрисовку";
				}
				else cout << "Вы еще не нарисовали объект";
			}
			break;
			case 12:
			{
				roll_back_create();
				cout << "Объект успешно удален,перейдите в главное меню";
				return;
			}
			break;
			default:
				break;
			}
		}
		else
		{
			switch (key)
			{
			case 72: item--;  break;
			case 80: item++;  break;
			case 48: item = 0;  break;
			case 49: item = 1;  break;
			case 50: item = 2;  break;
			case 51: item = 3;  break;
			case 52: item = 4;  break;
			case 53: item = 5;  break;
			case 54: item = 6;  break;
			case 55: item = 7;  break;
			case 56: item = 8; break;
			case 57: item = 9; break;
			case 58: item = 10; break;
			case 59: item = 11; break;
			case 60: item = 12; break;
			}
			print_inmenu(item, 15, commands);
			if (item < 0)
				item = commands.size() + 1;
			if (item > commands.size() + 1)
				item = 0;
		}
	}
}