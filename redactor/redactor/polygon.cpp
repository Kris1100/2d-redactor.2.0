#include "polygon.h"

//������������ � �����������
polygon::polygon(size_t num_vert)
{
	if (num_vert < 3)
		num_vert = 3;
	set_num(num_vert);
	point* vert = new point[num_vert];
	set_point_array(vert);                  
}

polygon::polygon(const polygon& t) 
{
	if (this == &t)
		return;
	if (t.num_vert_ == 0)
		return;
	point* vert = new point[t.num_vert_];
	for (int i = 0; i < t.num_vert_; i++) 
	{
		try
		{
			vert[i] = t.vertex[i];
		}
		catch (...)
		{
			delete[] vert;
			vert = nullptr;
			throw;
		}
	}
	if (vertex)
		delete[] vertex;
	vertex = vert;
	num_vert_ = t.num_vert_;
}

polygon::~polygon()
{
	delete[] vertex;
	vertex = nullptr;
	is_drawn = false;
}

//�������
void polygon::set_point_array(point* vert)
{
	//�� ��������� ���������� ���������� n- ��������, ������ �� ����� �� ������������ ��� 
	//���������� ��-�� ����������� ��������� (��� ������� ��������� num_vert_). 
	//���� ��� � ���������� ��������������
	vertex = vert;
	//��������� ��������� ����������
	int R = 1;
	//��������� ����
	double ang = 0;
	for (int i = 0; i < num_vert_; i++)
	{
		//��������� ���������� ��������� ����� - ���������� ������� � ������� � ����� (0,0), 
		//����������� �� ���� ang ������ ������� �������
		vertex[i].set_x(R * round(cos(ang * constants::pi / 180) * constants::rd) / constants::rd);
		vertex[i].set_y(R * round(sin(ang * constants::pi / 180) * constants::rd) / constants::rd);
		//�������� ����
		ang += (360 / num_vert_);
	}
}

void polygon::set_num(size_t num_vert)
{
	num_vert_ = num_vert;
}

//�������� ������� ������
double polygon::perimetr() const
{
	if (not is_correct()) return 0;
	double p = 0;
	for (int i = 0; i < num_vert_ - 1; i++)
	{
		segment s1(vertex[i], vertex[i + 1]);
		p += s1.len();
	}
	segment s(vertex[num_vert_ - 1], vertex[0]);
	p += s.len();
	return p;
}

double polygon::area() const
{
	//���������� ������� ������� ������ https://cpp.mazurok.com/tag/%D0%BF%D0%BB%D0%BE%D1%89%D0%B0%D0%B4%D1%8C-%D0%BC%D0%BD%D0%BE%D0%B3%D0%BE%D1%83%D0%B3%D0%BE%D0%BB%D1%8C%D0%BD%D0%B8%D0%BA%D0%B0/#:~:text=%D0%94%D0%BB%D1%8F%20%D1%82%D0%BE%D0%B3%D0%BE%2C%20%D1%87%D1%82%D0%BE%D0%B1%D1%8B%20%D0%B2%D1%8B%D1%87%D0%B8%D1%81%D0%BB%D0%B8%D1%82%D1%8C%20%D0%B5%D0%B3%D0%BE,%D0%BF%D1%80%D0%BE%D0%B8%D0%B7%D0%B2%D0%BE%D0%BB%D1%8C%D0%BD%D0%BE%D0%B3%D0%BE%20%D0%BC%D0%BD%D0%BE%D0%B3%D0%BE%D1%83%D0%B3%D0%BE%D0%BB%D1%8C%D0%BD%D0%B8%D0%BA%D0%B0%20%D0%BC%D0%BE%D0%B6%D0%BD%D0%BE%20%D0%BF%D1%80%D0%BE%D1%87%D0%B5%D1%81%D1%82%D1%8C%20%D0%B7%D0%B4%D0%B5%D1%81%D1%8C.
	double s1 = 0, s2 = 0, s = 0;
	if (not is_correct()) return 0;
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
double polygon::non_convex_area() {
	//http://opita.net/node/27
	if (not is_correct()) return 0;
	double s = 0,res=0;
	for (int i = 0; i < num_vert_; i++) {
		if (i == 0) {
			s=vertex[i].get_x()* (vertex[num_vert_ - 1].get_y() - vertex[i + 1].get_y());
			res += s;
		}
		else if (i == num_vert_ - 1) {
			s = vertex[i].get_x() * (vertex[i- 1].get_y() - vertex[0].get_y());
			res += s;
			}
		else {
			s = vertex[i].get_x() * (vertex[i - 1].get_y() - vertex[i + 1].get_y());
			res += s;
		}
	}
	return abs(res / 2);
}
bool polygon::is_correct() const {
	for (int i=0;i<num_vert_;i++)
		for (int j = i + 1; j < num_vert_; j++) {
			if (vertex[i] == vertex[j]) return false;
		}
	return true;
}

void polygon::print() const
{
	for (int i = 0; i < num_vert_; i++)
	{
		cout << "x = " << vertex[i].get_x() << ", y = " << vertex[i].get_y() << endl;
	}
}

bool polygon::is_convex() const
{
	//������������� ����� �������� ���� ��� ��� ������ � ������ ������ ���������������� ������ 
	//���������� ������� ������ � ���� � �� �� �������. ��� ������ �������������� ������ �������
	//������� ������� ����� ������ ������, � ��� ������ �� ������� - �������.
	//��� �������� ������ ���(�������� ������� � total) �������� ����� �������������,
	//� ��� �������� ������� - �������������.
	if (not is_correct()) return false;
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
	return true;
}

bool polygon::is_regular(bool convexity) const
{
	//�������� �� ����������. ���������� ������������� �� �������� ����������.
	//������������� �������� ����������, ���� ��� ��� ������� � ���� �����
	if (not is_correct()) return 0;
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
			{
				//���� ��������� ������� �� ����� �������, �� ������������� ������������
				double d = abs(s.len() - side);
				if (d > constants::eps)
					return false;
			}
			//������� ��� �������, ����� �������� ����� ���������� ����
			myvector v1(vertex[i + 1], vertex[i]);
			point p;
			if (i == num_vert_ - 2)
				p = vertex[0];
			else
				p = vertex[i + 2];
			myvector v2(vertex[i + 1], p);
			//����� ������ ���������� �������� ������
			if (ang == -1)
				ang = angle(v1, v2);
			else
			{
				double d = abs(ang - angle(v1, v2));
				if (d > constants::eps)
					return false;
			}
		}
		//��������� �������� ��� ��������� �������, �� � ��� ������ ���������� � ������� �����
		segment s(vertex[num_vert_ - 1], vertex[0]);
		myvector v1(vertex[0], vertex[num_vert_ - 1]);
		myvector v2(vertex[0], vertex[1]);
		double d = abs(s.len() - side);
		if (d > constants::eps)
			return false;
		d = abs(ang - angle(v1, v2));
		if (d > constants::eps)
			return false;
		return true;
	}
}

void polygon::draw()
{
	int R = 220, G = 208, B = 255;
	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3ub(R, G, B);
	for (int i = 0; i < num_vert_ - 1; i++)
	{
		glVertex2f(vertex[i].centerize().get_x(), vertex[i].centerize().get_y());
		glVertex2f(vertex[i + 1].centerize().get_x(), vertex[i + 1].centerize().get_y());
	}
	glEnd();
}

//Friend �������
std::istream& operator>>(istream& in, polygon& p)
{
	double x, y;
	//������������ ������ �� ������ ������
	long long int n;
	cout << "������� ���������� ������" << endl;
	cin >> n;
	delete[] p.vertex;
	p.set_num(n);
	point* vert = new point[n];
	p.set_point_array(vert);
	cout << "������� ���������� " << p.num_vert_ << " ������:" << endl;
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
	out << "���������� �����: " << p.num_vert_ << endl;
	for (int i = 0; i < p.num_vert_; i++)
	{
		out << "x = " << p.vertex[i].get_x() << ", y = " << p.vertex[i].get_y() << endl;
	}
	return out;
}

void polygon::mymenu() 
{
	ifstream in("polygon.txt");
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
				cout << "������ ���������, ��������� � ������� ����" << endl;
				return;
			}
			case 1: cin >> *this; break;
			case 2:
			{
				double per = this->perimetr();
				cout << "��������: " << per << endl;
			}
			break;
			case 3:
			{
				double sq;
				sq = this->area();
				cout << "�������: " << sq << endl;
			}
			break;
			case 4:
			{
				bool f = this->is_convex();
				if (f)
					cout << "������������� ��������" << endl;
				else
					cout << "������������� ����������" << endl;;
			}
			break;
			case 5:
			{
				if (this->is_regular(this->is_convex()))
					cout << "������������� ����������" << endl;
				else
					cout << "������������� �� �������� ����������" << endl;
			}
			break;
			case 6:
			{
				if (this->is_correct()) cout << "Многоугольник задан корректно" << endl;
				else cout << "Многоугольник задан некорректно" << endl;
			}
			break;
			case 7:
			{
				if (not this->is_drawn) {
					if (not this->is_correct()) cout << "Вы ввели некорректные данные, не можем нарисовать!";
					else {
						add_draw(*this);
						cout << "������ ������� �������� � ������� �� ���������, �� ������� ���, ����� ��������� ������";
						this->is_drawn = true;
					}
				}
				else 
				{
					cout << "������ ��� � ������� �� ���������";
				}
			}
			break;
			case 8:
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
			case 54: item = 6;  break;
			case 55: item = 7;  break;
			case 56: item = 8;  break;
			case 57: item = 9; break;
			}
			print_inmenu(item, 15, commands);
			if (item < 0)
				item = commands.size() + 1;
			if (item > commands.size() + 1)
				item = 0;
		}
	}
}