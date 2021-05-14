#include "Menu.h"
figure* q;
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
	point p1,p2,p3;
	cout << "Введите координаты двух точек для задания прямой" << endl;
	cout << "Введите координаты первой точки" << endl;
	cin >> p1;
	cout << "Введите координаты второй точки" << endl;
	cin >> p2;
	line l1(p1, p2);
	l1.print_v1();
	l1.print_param();
	myvector v1 = l1.normal_vector();
	cout <<"Координаты вектора нормали: "<< v1;
	myvector v2 = l1.guide_vector();
	cout << "Координаты направляющего вектора: " << v2;
	cout << "Введиите координаты точки,через которую нужно построить прямую,параллельную данной: " ;
	cin >> p3;
	line l2=l1.parallel(p3);
	cout << "Уравнение прямой,параллельной данной: ";
	l2.print_v2();
}

void print_polygon(int num)
{
	int n;
	cout << "Введите количество вершин ";
	cin >> n;
	polygon p(n);
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
	//Нарисуем отрезок, поместим на него указатель
	q = &s;
	//запустим рисование
	main_pr();
}

void print_triangle(int num)
{
	triangle abc;
	cin >> abc;
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
	//Нарисовать треугольник
	q = &abc;
	main_pr();
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
void main_pr() {
	glutCreateWindow("Work example");
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutMainLoop();
}
void Display(void) {
	if (q != NULL) q->draw();
}
void Reshape(GLint w, GLint h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, w, 0, h, -1.0, 1.0);
}