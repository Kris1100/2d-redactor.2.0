#include "Menu.h"
bidir_list<figure*> queue;

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
		num = 9;
	if (num > 9)
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
		cout << "1. ���������� �������� �������� � �����\n";
		SetColor(1, 15);
	}
	else
		cout << "1. ���������� �������� �������� � �����\n";
	if (num == 2)
	{
		SetColor(col, col2);
		cout << "2. �����\n";
		SetColor(1, 15);
	}
	else
		cout << "2. �����\n";
	if (num == 3)
	{
		SetColor(col, col2);
		cout << "3. ������\n";
		SetColor(1, 15);
	}
	else
		cout << "3. ������\n";
	if (num == 4)
	{
		SetColor(col, col2);
		cout << "4. ����������\n";
		SetColor(1, 15);
	}
	else
		cout << "4. ����������\n";
	if (num == 5)
	{
		SetColor(col, col2);
		cout << "5. �����������\n";
		SetColor(1, 15);
	}
	else
		cout << "5. �����������\n";
	if (num == 6)
	{
		SetColor(col, col2);
		cout << "6. �������������\n";
		SetColor(1, 15);
	}
	else
		cout << "6. �������������\n";
	if (num ==7 )
	{
		SetColor(col, col2);
		cout << "7. �������\n";
		SetColor(1, 15);
	}
	else
		cout << "7. �������\n";
	if (num == 8)
	{
		SetColor(col, col2);
		cout << "8. ������\n";
		SetColor(1, 15);
	}
	else
		cout << "8. ������\n";
	if (num == 9)
	{
		SetColor(col, col2);
		cout << "9. ���\n";
		SetColor(1, 15);
	}
	else
		cout << "9. ���\n";
}

void print_inmenu(int num, int col, vector<string>& commands)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
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
		num = commands.size() + 1;
	if (num > commands.size() + 1)
		num = 0;
	if (num == 0)
	{
		SetColor(col, col2);
		cout << "    0) �����\n";
		SetColor(1, 15);
	}
	else
		cout << "    0) �����\n";
	for (int i = 1; i < commands.size(); i++)
	{
		if (num == i)
		{
			SetColor(col, col2);
			cout << "    "<< i << ") " << commands[i - 1] << endl;
			SetColor(1, 15);
		}
		else
			cout << "    " << i << ") " << commands[i - 1] << endl;
	}
}

void print_point(int num)
{
	double x, y;
	cout << "������� ���������� �����:" << endl;
	cin >> x >> y;
	point p(x, y);
	cout << "������ ����� ����� � ";
	double a = p.quarter();
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
	point p1, p2, p3;
	cout << "������� ���������� ������ ����� ��� ������� ������:" << endl;
	cin >> p1;
	cout << "������� ���������� ������ �����:" << endl;
	cin >> p2;
	line l1(p1, p2);
	l1.print_v1();
	l1.print_param();
	myvector v1 = l1.normal_vector();
	cout << "���������� ������� �������: " << v1;
	myvector v2 = l1.guide_vector();
	cout << "���������� ������������� �������: " << v2;
	cout << "�������� ���������� �����, ����� ������� ����� ��������� ������, ������������ ������:" << endl;
	cin >> p3;
	line l2 = l1.parallel(p3);
	cout << "��������� ������, ������������ ������: ";
	l2.print_v2();
	queue.add_last(new line(l1));
}

void print_polygon(int num)
{
	int n;
	cout << "������� ���������� ������:" << endl;
	cin >> n;
	polygon p(n);
	cout << p;
	double per = p.perimetr();
	cout << "��������: " << per << endl;
	double sq = p.area();
	cout << "�������: " << sq << endl;
	bool f = p.is_convex();
	if (f)
		cout << "������������� ��������" << endl;
	else
		cout << "������������� ����������" << endl;
	if (p.is_regular(f))
		cout << "������������� ����������" << endl;
	else
		cout << "������������� �� �������� ����������" << endl;
	queue.add_last(new polygon(p));
}

void print_circle(int num)
{
	circle c;
	cin >> c;
	cout << c;// improve it!
	c.quarter();
	c.intersection();
	c.length();
}

void print_segment(int num)
{
	double x1, x2, y1, y2;
	cout << "������� ���������� ������ �����:" << endl;
	cin >> x1 >> y1;
	cout << "������� ���������� ������ �����:" << endl;
	cin >> x2 >> y2;
	point p1(x1, y1);
	point p2(x2, y2);
	segment s(p1, p2);
	cout << "����� �������: " << s.len() << endl;
	//������� � ������� �� ���������
	queue.add_last(new segment(s));
}

void print_triangle(int num)
{
	ifstream in("triangle.txt");
	vector<string> commands;
	while (in)
	{
		string s = "";
		getline(in, s, '\n');
		commands.push_back(s);
	}
	SetColor(1, 15);
	int item = 0;
	print_inmenu(0, 1, commands);
	triangle abc;
	cin >> abc;
	while (true)
	{
		int key = _getch();

		if (key == 13)
		{
			switch (item)
			{
			case 0: goto skip;
			case 1: cin >> abc; break;
			case 2: 
			{
				if (abc.is_equilateral())
					cout << "����������� ��������������" << endl;
				else
					cout << "����������� �� �������� ��������������" << endl;
			}
			break;
			case 3: 
			{
				if (abc.is_isosceles())
					cout << "����������� ��������������" << endl;
				else
					cout << "����������� �� �������� ��������������" << endl;
			}
			break;
			case 4: 
			{
				if (abc.is_right())
					cout << "����������� �������������" << endl;
				else
					cout << "����������� �� �������� �������������" << endl;
			}
			break;
			case 5:
			{
				cout << "�������: " << abc.area() << endl;
			}
			break;
			case 6: 
			{
				cout << "��������: " << abc.perimetr() << endl;
			}
			break;
			case 7: 
			{
				try
				{
					cout << "������ ��������� ����������: " << abc.radius_inside() << endl;
				}
				catch (const string& e)
				{
					cout << e << endl;
				}
			}
			break;
			case 8: 
			{
				try
				{
					cout << "������ ��������� ����������: " << abc.radius_outside() << endl;
				}
				catch (const string& e)
				{
					cout << e << endl;
				}
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
			}
			print_inmenu(item, 15, commands);
			if (item < 0)
				item = commands.size() + 1;
			if (item > commands.size() + 1)
				item = 0;
		}
	}
	skip:
	//cin >> abc;
	//if (abc.is_equilateral())
	//	cout << "����������� ��������������" << endl;
	//else
	//	cout << "����������� �� �������� ��������������" << endl;
	//if (abc.is_isosceles())
	//	cout << "����������� ��������������" << endl;
	//else
	//	cout << "����������� �� �������� ��������������" << endl;
	//if (abc.is_right())
	//	cout << "����������� �������������" << endl;
	//else
	//	cout << "����������� �� �������� �������������" << endl;
	//cout << "�������: " << abc.area() << endl;
	//cout << "��������: " << abc.perimetr() << endl;
	//try
	//{
	//	cout << "������ ��������� ����������: " << abc.radius_inside() << endl;
	//}
	//catch (const string& e)
	//{
	//	cout << e << endl;
	//}
	//try
	//{
	//	cout << "������ ��������� ����������: " << abc.radius_outside() << endl;
	//}
	//catch (const string& e)
	//{
	//	cout << e << endl;
	//}
	in.close();
	//���������� �����������
	queue.add_last(new triangle(abc));
}

void print_vector(int num)
{
	double x1, x2, y1, y2;
	cout << "������� ���������� ��������� �����:" << endl;
	cin >> x1 >> y1;
	cout << "������� ���������� �������� �����:" << endl;
	cin >> x2 >> y2;
	point p1(x1, y1);
	point p2(x2, y2);
	myvector v(p1, p2);
	cout << "����� �������: " << v.len() << endl;
}

void print_ray(int num) 
{
	double x, y;
	cout << "������� ���������� ������ ����:" << endl;
	cin >> x >> y;
	point beg(x, y);
	cout << "������� ���������� ������������ ����� ����:" << endl;
	cin >> x >> y;
	point p(x, y);
	ray r(beg, p);
	//��������� ����
	queue.add_last(new ray(r));
}

void SetColor(int text, int Fon)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, (Fon << 4) + text);
}

void main_pr() 
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glutInitWindowSize(constants::width, constants::height);
	glutCreateWindow("Let's paint it!");
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutMainLoop();
}

void Display(void) 
{
	//��������� �� ������ �� ��������� 
	Node<figure*>* cur = NULL;
	cur = queue.get_head();
	while (cur != NULL) 
	{
		//������� ����� draw ���������������� �������
		cur->info->draw();
		cur = cur->next;
	}
	glFinish();
}

void Reshape(GLint w, GLint h)
{
	glViewport(0, 0, w, h);

	/* ��������������� �������� */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, w, 0, h, -1.0, 1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}