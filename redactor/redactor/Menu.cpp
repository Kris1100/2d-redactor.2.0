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
		cout << "0. Выход\n";
		SetColor(1, 15);
	}
	else
		cout << "0. Выход\n";
	if (num == 1)
	{
		SetColor(col, col2);
		cout << "1. Точка\n";
		SetColor(1, 15);
	}
	else
		cout << "1. Точка\n";
	if (num == 2)
	{
		SetColor(col, col2);
		cout << "2. Прямая\n";
		SetColor(1, 15);
	}
	else
		cout << "2. Прямая\n";
	if (num == 3)
	{
		SetColor(col, col2);
		cout << "3. Окружность\n";
		SetColor(1, 15);
	}
	else
		cout << "3. Окружность\n";
	if (num == 4)
	{
		SetColor(col, col2);
		cout << "4. Треугольник\n";
		SetColor(1, 15);
	}
	else
		cout << "4. Треугольник\n";
	if (num == 5)
	{
		SetColor(col, col2);
		cout << "5. Многоугольник\n";
		SetColor(1, 15);
	}
	else
		cout << "5. Многоугольник\n";
	if (num == 6)
	{
		SetColor(col, col2);
		cout << "6. Отрезок\n";
		SetColor(1, 15);
	}
	else
		cout << "6. Отрезок\n";
	if (num == 7)
	{
		SetColor(col, col2);
		cout << "7. Вектор\n";
		SetColor(1, 15);
	}
	else
		cout << "7. Вектор\n";
}

void print_point(int num)
{
	double x, y;
	cout << "Введите координаты точки" << endl;
	cin >> x >> y;
	point p(x, y);
	cout << "Данная точка лежит в ";
	double a=p.quarter();
	cout << a << "четверти" << endl;
	double b = p.dist();
	cout << "Расстояние от данной точки до начала координат: " << b << endl;
	if (p.bisector() == true) 
		cout << "Данная точка лежит на биссектрисе координатной плоскости";
	else
		cout << "Данная точка не лежит на биссектрисе координатной плоскости";
	cout << endl;
}

void print_line(int num)
{
	double x1, y1, x2, y2;
	cout << "Введите координаты двух точек для задания прямой" << endl;
	cout << "Введите координаты первой точки" << endl;
	cin >> x1 >> y1;
	cout << "Введите координаты второй точки" << endl;
	cin >> x2 >> y2;
	point p1(x1, y1);
	point p2(x2, y2);
	line l(p1, p2);
	l.print();
	l.print_param();
	myvector v = l.normal_vector();
	cout <<"Координаты вектора нормали: "<< v;
}

void print_polygon(int num)
{
	int n;
	cout << "Введите количество вершин ";
	cin >> n;
	polygon p(n);
	cin >> p;
	cout << p;
	double per = p.perimetr();
	cout << "Периметр " << per << endl;
	double sq = p.area();
	cout << "Площадь " << sq << endl;
	bool f = p.is_convex();
	if (f)
		cout << "Многоугольник выпуклый" << endl;
	else
		cout << "Многоугольник невыпуклый" << endl;
	if (p.is_regular(f))
		cout << "Многоугольник правильный" << endl;
	else
		cout << "Многоугольник не является правильным" << endl;
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
	cout << "Введите координаты точки: ";
	cin >> x1 >> y1;
	cout << "Введите координаты точки: ";
	cin >> x2 >> y2;
	p1.set_x(x1);
	p1.set_y(y1);
	p2.set_x(x2);
	p2.set_y(y2);
	segment s(p1, p2);
	cout << "Длина отрезка " << s.len();
}

void print_triangle(int num)
{
	triangle abc;
	abc.init();
	if (abc.is_equilateral())
		cout << "Треугольник равносторонний" << endl;
	if (abc.is_isosceles())
		cout << "Треугольник равнобедренный" << endl;
	if (abc.is_right())
		cout << "Треугольник прямоугольный" << endl;
	cout << "Площадь: " << abc.area() << endl;
	cout << "Периметр: " << abc.perimetr() << endl;
	cout << "Радиус вписанной окружности: " << abc.radius_inside() << endl;
	cout << "Радиус описанной окружности: " << abc.radius_outside() << endl;
	//abc.~triangle();
}

void print_vector(int num)
{
	point p1, p2;
	double x1, x2, y1, y2;
	cout << "Введите координаты начальной точки: ";
	cin >> x1 >> y1;
	cout << "Введите координаты конечной точки: ";
	cin >> x2 >> y2;
	p1.set_x(x1);
	p1.set_y(y1);
	p2.set_x(x2);
	p2.set_y(y2);
	myvector v(p1, p2);
	cout << "Длина вектора " << v.len();
}

void SetColor(int text, int Fon)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, (Fon << 4) + text);
}