#include "segment.h"
#include"math_const.h"
#include "glut-3.7.6-bin/glut.h"
segment::segment(const point& p1,const point& p2) 
{
	//����������� ������ �� ��� ���������� �����
	try 
	{
		if (p1 == p2) 
			throw "��� ����� ������� ���������, ����� ����������� �������� �� ��������� (0,0) � (1,1)";
		//���� ��� ������ ������� ������� � ����������� �������
		set_extm_points(p1, p2);
	}
	catch (const char* err) 
	{
		cout << "������: " << err<<endl;
		//� ������ ������ ������ �������� �� ���������
		point d1(0, 0);
		point d2(1, 1);
		set_extm_points(d1, d2);
	}
}
segment::segment(const segment& s) 
{
	p1_ = s.get_start();
	p2_ = s.get_end();
}

void segment::set_extm_points(const point& p1,const point& p2)
{
	p1_ = p1;
	p2_ = p2;
}

double segment::len() const
{
	return round(sqrt( ((p1_.get_x() - p2_.get_x()) * (p1_.get_x() - p2_.get_x()))
			   + ((p1_.get_y() - p2_.get_y()) * (p1_.get_y() - p2_.get_y())) )*constants::rd)/constants::rd;
}

point segment::middle() const
{
	double x = (p1_.get_x() + p2_.get_x()) / 2;
	double y = (p1_.get_y() + p2_.get_y()) / 2;
	return point(x, y);
}

void segment::draw()  
{
	glLineWidth(3);
	glBegin(GL_LINES);
	      glColor3ub(255, 203, 219);
	      glVertex2f(p1_.centerize().get_x(), p1_.centerize().get_y());
		  glColor3ub(255, 107, 142);
	      glVertex2f(p2_.centerize().get_x(), p2_.centerize().get_y());
	glEnd();
}
void segment::mymenu() {
	ifstream in("segment.txt");
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
	if (not this->is_created) {
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
				cout << "������ ���������, ��������� � ������� ����" << endl;
				return;
			}
			case 1: cin >> *this; break;
			case 2:
			{
				cout << "����� �������: " << this->len() << endl;
			}
			break;
			case 7:
			{
				if (not this->is_drawn) {
					add_draw(*this);
					cout << "������ ������� �������� � ������� �� ���������, �� ������� ���, ����� ��������� ������";
					this->is_drawn = true;
				}
				else {
					cout << "������ ��� � ������� �� ���������";
				}
			}
			break;
			case 8:
			{
				if (this->is_drawn) {
					roll_back_draw();
					this->is_drawn = false;
					cout << "������ ������� ������ �� ������ �� ���������";
				}
				else cout << "�� ��� �� ���������� ������";
			}
			break;
			case 9:
			{
				roll_back_create();
				cout << "������ ������� ������,��������� � ������� ����";
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
			}
			print_inmenu(item, 15, commands);
			if (item < 0)
				item = commands.size() + 1;
			if (item > commands.size() + 1)
				item = 0;
		}
	}
}