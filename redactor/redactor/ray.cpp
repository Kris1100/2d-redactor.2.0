#include "ray.h"

ray::ray(const point& begin, const point& p)
{
	//if (p != begin)
	//{
		_begin = begin;
		_p = p;
	//}
	//else
	//	throw "������������ ���������� � ����";
}

ray::~ray()
{
	_p.~point();
	_begin.~point();
	is_drawn = false;
}

ray::ray(const ray& r)
{
	_begin = r.get_begin();
	_p = r.get_p();
	is_drawn = r.is_drawn;
}

bool ray::is_element(const point& t)
{
	//���� ��������� � ������������ ������� ����
	if (t == _p || t == _begin)
		return true;
	//����������� �� ������, �� ������� ����� ���
	double x = t.get_x(), y = t.get_y();
	line l(_begin, _p);
	double a, b, c;
	l.coef(a, b, c);
	if (abs(a * x + b * y + c) >= constants::eps)
		return false;
	//����� �������� ���������, ��������� ����������, ��������������� ���������� �����
	double tmp_b = _begin.get_x();
	double tmp_p = _p.get_x();
	double  tmp_t = x;
	//������ � ������������ �����
	if (_begin.get_x() == _p.get_x())
	{
		tmp_b = _begin.get_y();
		tmp_p = _p.get_y();
		tmp_t = y;
	}
	//������� � ������ ������ � ������ ������/������
	//p������ ��������� ����� ����������, ����� �������� ���������
	int sign = 1;
	//���� ����� ��� ������
	if (tmp_b < tmp_p)
		sign = 1;
	//���� ���� ��� �����
	else
		sign = -1;
	if (tmp_t * sign > tmp_b)
		return true;
	return false;
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

void ray::draw()
{
	glLineWidth(2);
	line l(_begin, _p);
	point p1, p2;
	l.extend(p1, p2);
	ray r(_begin.centerize(), _p.centerize());
	if (r.is_element(p2))
		p1 = p2;
	glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
	glVertex2f(_begin.centerize().get_x(), _begin.centerize().get_y());
	glColor3ub(238, 130, 238);
	glVertex2f(p1.get_x(), p1.get_y());
	glEnd();
}

void ray::mymenu()
{
	ifstream in("ray.txt");
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
				cout << "������������ ����������" << endl;
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
				cout << "������ ���������, ��������� � ������� ����" << endl;
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
						cout << "������������ ����������" << endl;
					}
				}
				roll_back_draw();
				add_draw(*this);
			}
			break;
			case 2:
			{
				point p;
				bool flag = false;
				while (!flag)
				{
					try
					{
						cin >> p;
						flag = true;
					}
					catch (...)
					{
						cout << "������������ ����������" << endl;
					}
				}
				if (is_element(p))
					cout << "����� ����������� ����" << endl;
				else
					cout << "����� �� ����������� ����" << endl;
			}
			break;
			case 3:
			{
				if (not this->is_drawn)
				{
					add_draw(*this);
					cout << "������ ������� �������� � ������� �� ���������, �� ������� ���, ����� ��������� ������";
					this->is_drawn = true;
				}
				else
				{
					cout << "������ ��� � ������� �� ���������";
				}
			}
			break;
			case 4:
			{
				if (this->is_drawn)
				{
					roll_back_draw();
					this->is_drawn = false;
					cout << "������ ������� ������ �� ������ �� ���������";
				}
				else
					cout << "�� ��� �� ���������� ������";
			}
			break;
			case 5:
			{
				roll_back_create();
				cout << "������ ������� ������, ��������� � ������� ����";
				return;
			}
			break;
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
			}
			print_inmenu(item, 15, commands);
			if (item < 0)
				item = commands.size() + 1;
			if (item > commands.size() + 1)
				item = 0;
		}
	}
}