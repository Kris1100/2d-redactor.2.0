#include "circle.h"

circle::circle(double x, double y, double r)
{
	_p = point(x, y);
	if (r <= 0)
		r = 1;
	set_r(r);
}

circle::circle(const circle& c)
{
	_p = c.get_p();
	_r = c.get_r();
}

circle::~circle()
{
	_p.~point();
	_r = 0;
	is_drawn = false;
}

ostream& operator<<(ostream& out, const circle& c)
{
	out << "Координаты центра (" << c._p.get_x() << ", "
		<< c._p.get_y() << ")" << endl << "Радиус: " << c._r << endl;
	return out;
}

istream& operator>>(istream& in, circle& c)
{
	double x, y, r;
	cout << "Введите координаты центра и радиус: ";
	in >> x >> y >> r;
	if (r <= 0)
		throw "error";
	c._p = point(x, y);
	c.set_r(r);
	return in;
}

int circle::quarter() const
{
	if ((_p.get_x() - _r) > 0 && (_p.get_y() - _r) > 0) return 1;
	else if ((_p.get_x() + _r) < 0 && (_p.get_y() - _r) > 0) return 2;
	else if ((_p.get_x() + _r) < 0 && (_p.get_y() + _r) < 0) return 3;
	else if ((_p.get_x() - _r) > 0 && (_p.get_y() + _r) < 0) return 4;
	else return -1;
}

void circle::intersection() const
{
	bool fl = false;
	if (_r * _r - (_p.get_x() * _p.get_x()) > 0)
	{
		cout << "Точка пересечения с осью x:(0, " << _p.get_y() +
			sqrt(_r * _r - (_p.get_x() * _p.get_x())) << ")  " << endl;
		cout << "Точка пересечения с осью x:(0, " << -_p.get_y() +
			sqrt(_r * _r - (_p.get_x() * _p.get_x())) << ")  " << endl;

		fl = true;
	}
	if (_r * _r - (_p.get_y() * _p.get_y()) > 0)
	{
		cout << "Точка пересечения с осью y:(" << _p.get_x() +
			sqrt(_r * _r - (_p.get_y() * _p.get_y())) << " ,0) " << endl;
		cout << "Точка пересечения с осью y:(" << -_p.get_x() +
			sqrt(_r * _r - (_p.get_y() * _p.get_y())) << " ,0) " << endl;

		fl = true;
	}
	if (!fl) cout << "Нет пересечения с осями" << endl;
}

void circle::draw()
{
	glColor3ub(220, 195, 232);
	glLineWidth(3);
	int n = 300;
	int xp = _p.centerize().get_x();
	int yp = _p.centerize().get_y();
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < n; i++)
	{
		double angle = 2 * 3.14 * i / n;
		glVertex2f(xp + _r * 40 * cos(angle), yp + _r * 40 * sin(angle));
	}
	glEnd();
}

line circle::tangent(point& p)  //входные данные меняются? если нет, то конст
{
	double a = -2 * _p.get_x() + p.get_x();
	double b = -2 * _p.get_y() + p.get_y();
	double c = pow(_p.get_x(), 2) + pow(_p.get_y(), 2) - pow(_r, 2);
	return line(a, b, c);
}

void circle::mymenu()
{
	ifstream in("circle.txt");
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
		bool flag = false;
		while (!flag)
		{
			try
			{
				cin >> *this;
				flag = true;
			}
			catch (...)
			{
				cout << "Недостаточно информации" << endl;
			}
		}
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
				bool flag = false;
				while (!flag)
				{
					try
					{
						cin >> *this;
						flag = true;
					}
					catch (...)
					{
						cout << "Недостаточно информации" << endl;
					}
				}
				roll_back_draw();
				add_draw(*this);
			}
			break;
			case 2:
			{
				cout << "Длина окружности " << length();
			}
			break;
			case 3:
			{
				int k = quarter();
				if (k > 0)
					cout << "Окружность лежит в " << k << " четверти.";
				else
					cout << "" << endl;
			}
			break;
			case 4:
			{
				intersection();
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
			case 53: item = 5;  break;
			case 54: item = 6;  break;
			case 55: item = 7; break;
			}
			print_inmenu(item, 15, commands);
			if (item < 0)
				item = commands.size() + 1;
			if (item > commands.size() + 1)
				item = 0;
		}
	}
}