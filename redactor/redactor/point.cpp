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

point point::centerize()
{
	double x, y;
	int step = 40;
	x = round(_x * constants::scale + constants::width / 2);
	y = round(_y * constants::scale + constants::height / 2);
	point p(x, y);
	return p;
}

void point::draw()
{
	int R_ = 230, G_ = 168, B_ = 215;
	point p(_x, _y);
	glColor3ub(R_, G_, B_);
	int N = 360;
	int R = 3;
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 1; i <= N; i++)
	{
		glVertex2f(p.centerize().get_x() + R * cos(2 * 3.14 / N * i), 
				   p.centerize().get_y() + R * sin(2 * 3.14 / N * i));
	}
	glEnd();
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

	char x1[256];
	char y1[256];

	double x, y;

	in >> x1 >> y1;
	x = atof(x1);
	y = atof(y1);

	p._x = x;
	p._y = y;
	return in;
}

ostream& operator<<(ostream& out, const point& p)
{
	cout << p._x << " " << p._y;
	return out;
}

point& point::operator=(const point& p) 
{
	if (this == &p) 
		return *this;
	_x = p.get_x();
	_y = p.get_y();
	return *this;
}

void point::mymenu()
{
	ifstream in("point.txt");
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
			case 1: cin >> *this; break;
			case 2:
			{
				cout << "Данная точка лежит в ";
				double a = quarter();
				cout << a << "четверти" << endl;
			}
			break;
			case 3:
			{
				double b = dist();
				cout << "Расстояние от данной точки до начала координат: " << b << endl;
			}
			break;
			case 4:
			{
				if (bisector() == true)
					cout << "Данная точка лежит на биссектрисе координатной плоскости";
				else
					cout << "Данная точка не лежит на биссектрисе координатной плоскости";
				cout << endl;
			}
			break;
			case 5:
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
			case 6:
			{
				if (this->is_drawn)
				{
					roll_back_draw();
					this->is_drawn = false;
					cout << "Объект успешно удален из очерди на отрисовку";
				}
				else
					cout << "Вы еще не нарисовали объект";
			}
			break;
			case 7:
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
			case 53:item = 5; break;
			case 54:item = 6; break;
			case 55:item = 7; break;
			}
			print_inmenu(item, 15, commands);
			if (item < 0)
				item = commands.size() + 1;
			if (item > commands.size() + 1)
				item = 0;
		}
	}
}