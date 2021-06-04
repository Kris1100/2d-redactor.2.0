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
	/*line l(_begin, _p);
	line t = l.extend();
	point p2;
	double t1x = t.get_first().get_x();
	double t1y = t.get_first().get_y();
	double t2x = t.get_second().get_x();
	if (t1x == t2x)
	{
		if (t1y > _begin.get_y() && t1y > _p.get_y() ||
			t1y < _begin.get_y() && t1y < _p.get_y())
			p2 = t.get_first();
		else
			p2 = t.get_second();
	}
	else
	{
		if (t1x > _begin.get_x() && t1x > _p.get_x() ||
			t1x < _begin.get_x() && t1x < _p.get_x())
			p2 = t.get_first();
		else
			p2 = t.get_second();
	}*/
	glBegin(GL_LINES);
	    glColor3ub(255, 255, 255);
	    glVertex2f(_begin.centerize().get_x(), _begin.centerize().get_y());
	    glColor3ub(238, 130, 238);
	    glVertex2f(_p.centerize().get_x()*100, _p.centerize().get_y()*100);
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