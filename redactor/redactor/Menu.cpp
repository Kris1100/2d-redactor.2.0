﻿#include "Menu.h"
bidir_list<figure*> queue;
bidir_list<elem>all;
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
		cout << "0. Выход\n";
		SetColor(1, 15);
	}
	else
		cout << "0. Выход\n";
	if (num == 1)
	{
		SetColor(col, col2);
		cout << "1. Нарисовать заданные элементы и выйти\n";
		SetColor(1, 15);
	}
	else
		cout << "1. Нарисовать заданные элементы и выйти\n";
	if (num == 2)
	{
		SetColor(col, col2);
		cout << "2. Точка\n";
		SetColor(1, 15);
	}
	else
		cout << "2. Точка\n";
	if (num == 3)
	{
		SetColor(col, col2);
		cout << "3. Прямая\n";
		SetColor(1, 15);
	}
	else
		cout << "3. Прямая\n";
	if (num == 4)
	{
		SetColor(col, col2);
		cout << "4. Окружность\n";
		SetColor(1, 15);
	}
	else
		cout << "4. Окружность\n";
	if (num == 5)
	{
		SetColor(col, col2);
		cout << "5. Треугольник\n";
		SetColor(1, 15);
	}
	else
		cout << "5. Треугольник\n";
	if (num == 6)
	{
		SetColor(col, col2);
		cout << "6. Многоугольник\n";
		SetColor(1, 15);
	}
	else
		cout << "6. Многоугольник\n";
	if (num == 7)
	{
		SetColor(col, col2);
		cout << "7. Отрезок\n";
		SetColor(1, 15);
	}
	else
		cout << "7. Отрезок\n";
	if (num == 8)
	{
		SetColor(col, col2);
		cout << "8. Вектор\n";
		SetColor(1, 15);
	}
	else
		cout << "8. Вектор\n";
	if (num == 9)
	{
		SetColor(col, col2);
		cout << "9. Луч\n";
		SetColor(1, 15);
	}
	else
		cout << "9. Луч\n";
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
		cout << "    0) Выход\n";
		SetColor(1, 15);
	}
	else
		cout << "    0) Выход\n";
	for (int i = 0; i < commands.size(); i++)
	{
		if (num == i + 1)
		{
			SetColor(col, col2);
			cout << "    " << i + 1 << ") " << commands[i] << endl;
			SetColor(1, 15);
		}
		else
			cout << "    " << i + 1 << ") " << commands[i] << endl;
	}
}

void print_point(int num)
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
	double x, y;
	cout << "Введите координаты точки:" << endl;
	cin >> x >> y;
	point p(x, y);

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
			case 1: cin >> p; break;
			case 2:
			{
				cout << "Данная точка лежит в ";
				double a = p.quarter();
				cout << a << "четверти" << endl;
			}
			break;
			case 3:
			{
				double b = p.dist();
				cout << "Расстояние от данной точки до начала координат: " << b << endl;
			}
			break;
			case 4:
			{
				if (p.bisector() == true)
					cout << "Данная точка лежит на биссектрисе координатной плоскости";
				else
					cout << "Данная точка не лежит на биссектрисе координатной плоскости";
				cout << endl;
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
			}
			print_inmenu(item, 15, commands);
			if (item < 0)
				item = commands.size() + 1;
			if (item > commands.size() + 1)
				item = 0;
		}
	}
}

void print_line(int num)
{
	ifstream in("line.txt");
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
	point p1, p2,p3;
	line l1(p1,p2);
	cin >> l1;
	elem one;
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
			case 1: { 
				l1.~line();
				cin >> l1;
			}
	        break;
			case 2:
			{
				l1.print_v1();
			}
			break;
			case 3:
			{
				l1.print_param();
			}
			break;
			case 4:
			{
				myvector v1 = l1.normal_vector();
				cout << "Координаты вектора нормали: " << v1;
			}
			break;
			case 5:
			{
				myvector v2 = l1.guide_vector();
				cout << "Координаты направляющего вектора: " << v2;
			}
			break;
			case 6:
			{
				cout << "Введиите координаты точки, через которую нужно построить прямую, параллельную данной:" << endl;
				cin >> p3;
				line l2 = l1.parallel(p3);
				cout << "Уравнение прямой, параллельной данной: ";
				l2.print_v2();//не работает, как надо
			}
			break;
			case 7:
			{
				if (not l1.is_drawn) {
					queue.add_last(new line(l1));
					one.comm = "DRAW";
					one.obj = queue.get_tail()->info;
					all.add_last(one);
					cout << "Объект успешно добавлен в очередь на отрисовку, вы увидите его, когда завершите работу";
					l1.is_drawn = true;
				}
				else {
					cout << "Объект уже в очереди на отрисовку";
				}
			}
			break;
			case 8:
			{
				if (l1.is_drawn) {
					Node<figure*>* p;
					p = queue.get_last();
					delete p;
					Node<elem>* t;
					t= all.get_last();
					delete t;
					l1.is_drawn = false;
					cout << "Объект успешно удален из очерди на отрисовку";
				}
				else cout << "Вы еще не нарисовали объект";
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
			case 56: item = 8; break;
			}
			print_inmenu(item, 15, commands);
			if (item < 0)
				item = commands.size() + 1;
			if (item > commands.size() + 1)
				item = 0;
		}
	}
}

void print_polygon(int num)
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

	int n;
	cout << "Введите количество вершин:" << endl;
	cin >> n;
	polygon p(n);
	cout << p;

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
				queue.add_last(new polygon(p));
				cout << "Работа завершена, перейдите в главное меню" << endl;
				return;
			}
			case 1: cin >> p; break;
			case 2:
			{
				double per = p.perimetr();
				cout << "Периметр: " << per << endl;
			}
			break;
			case 3:
			{
				double sq = p.area();
				cout << "Площадь: " << sq << endl;
			}
			break;
			case 4:
			{
				bool f = p.is_convex();
				if (f)
					cout << "Многоугольник выпуклый" << endl;
				else
					cout << "Многоугольник невыпуклый" << endl;;
			}
			break;
			case 5:
			{
				if (p.is_regular(p.is_convex()))
					cout << "Многоугольник правильный" << endl;
				else
					cout << "Многоугольник не является правильным" << endl;
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

void print_circle(int num)
{
	circle c;
	cin >> c;
	cout << c;// improve it! URGENT!!!!!!!!!
	c.quarter();
	c.intersection();
	c.length();
	queue.add_last(new circle(c));

}

void print_segment(int num)
{
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

	double x1, x2, y1, y2;
	cout << "Введите координаты первой точки:" << endl;
	cin >> x1 >> y1;
	cout << "Введите координаты второй точки:" << endl;
	cin >> x2 >> y2;
	point p1(x1, y1);
	point p2(x2, y2);
	segment s(p1, p2);

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
				//Добавим в очередь на отрисовку
				queue.add_last(new segment(s));
				cout << "Работа завершена, перейдите в главное меню" << endl;
				return;
			}
			case 1: cin >> s; break;
			case 2:
			{
				cout << "Длина отрезка: " << s.len() << endl;
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
			}
			print_inmenu(item, 15, commands);
			if (item < 0)
				item = commands.size() + 1;
			if (item > commands.size() + 1)
				item = 0;
		}
	}
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
	if (commands[commands.size() - 1] == "" || commands[commands.size() - 1] == "\n")
		commands.pop_back();
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
			case 0: 
			{
				in.close();
				//Нарисовать треугольник
				queue.add_last(new triangle(abc));
				cout << "Работа завершена, перейдите в главное меню" << endl;
				return;
			}
			case 1: cin >> abc; break;
			case 2:
			{
				if (abc.is_equilateral())
					cout << "Треугольник равносторонний" << endl;
				else
					cout << "Треугольник не является расносторонним" << endl;
			}
			break;
			case 3:
			{
				if (abc.is_isosceles())
					cout << "Треугольник равнобедренный" << endl;
				else
					cout << "Треугольник не является равнобедренным" << endl;
			}
			break;
			case 4:
			{
				if (abc.is_right())
					cout << "Треугольник прямоугольный" << endl;
				else
					cout << "Треугольник не является прямоугольным" << endl;
			}
			break;
			case 5:
			{
				cout << "Площадь: " << abc.area() << endl;
			}
			break;
			case 6:
			{
				cout << "Периметр: " << abc.perimetr() << endl;
			}
			break;
			case 7:
			{
				try
				{
					cout << "Радиус вписанной окружности: " << abc.radius_inside() << endl;
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
					cout << "Радиус описанной окружности: " << abc.radius_outside() << endl;
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
}

void print_vector(int num)
{
	ifstream in("myvector.txt");
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
	double x1, x2, y1, y2;
	cout << "Введите координаты начальной точки:" << endl;
	cin >> x1 >> y1;
	cout << "Введите координаты конечной точки:" << endl;
	cin >> x2 >> y2;
	point p1(x1, y1);
	point p2(x2, y2);
	myvector v(p1, p2);
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
			case 1: cin >> v; break;
			case 2:	cout << "Длина вектора: " << v.len() << endl; break;

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
			}
			print_inmenu(item, 15, commands);
			if (item < 0)
				item = commands.size() + 1;
			if (item > commands.size() + 1)
				item = 0;
		}
	}
	in.close();
}

void print_ray(int num)
{
	//ifstream in("triangle.txt");
	//vector<string> commands;
	//while (in)
	//{
	//	string s = "";
	//	getline(in, s, '\n');
	//	commands.push_back(s);
	//}
	//if (commands[commands.size() - 1] == "" || commands[commands.size() - 1] == "\n")
	//	commands.pop_back();
	//SetColor(1, 15);
	//int item = 0;
	//print_inmenu(0, 1, commands);

	double x, y;
	cout << "Введите координаты начала луча:" << endl;
	cin >> x >> y;
	point beg(x, y);
	cout << "Введите координаты произвольной точки луча:" << endl;
	cin >> x >> y;
	point p(x, y);
	ray r(beg, p);

	//Рисование луча
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
	//Пройдемся по списку на отрисовку 
	Node<figure*>* cur = NULL;
	cur = queue.get_head();
	while (cur != NULL)
	{
		//Вызовем метод draw соответствующего объекта
		cur->info->draw();
		cur = cur->next;
	}
	glFinish();
}

void Reshape(GLint w, GLint h)
{
	glViewport(0, 0, w, h);

	/* ортографическая проекция */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, w, 0, h, -1.0, 1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}