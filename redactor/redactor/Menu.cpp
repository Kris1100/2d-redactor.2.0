#include "Menu.h"
bidir_list<figure*> queue;//Пока просто это костыль, потом уберу
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
		num = 10;
	if (num > 10)
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
	if (num == 10)
	{
		SetColor(col, col2);
		cout << "10. Вернуться к предыдущему шагу\n";
		SetColor(1, 15);
	}
	else 
		cout << "10. Вернуться к предыдущему шагу\n";
}

void print_point(int num)
{
	double x=0, y=0;
	point p(x, y);
	add_create(p);
	all.get_tail()->info.obj->mymenu();
}

void print_line(int num)
{
	point p1, p2, p3;
	line l1(p1,p2);
	add_create(l1);
	all.get_tail()->info.obj->mymenu();
}

void print_polygon(int num)
{
	int n=3;
	polygon p(n);
	add_create(p);
	all.get_tail()->info.obj->mymenu();
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
	double x1=0, x2=0, y1=0, y2=0;
	point p1(x1, y1);
	point p2(x2, y2);
	segment s(p1, p2);
	add_create(s);
	all.get_tail()->info.obj->mymenu();
}

void print_triangle(int num)
{
	triangle abc;
	add_create(abc);
	all.get_tail()->info.obj->mymenu();
}

void print_vector(int num)
{
	double x1=0, x2=0, y1=0, y2=0;
	point p1(x1, y1);
	point p2(x2, y2);
	myvector v(p1, p2);	
	add_create(v);
	all.get_tail()->info.obj->mymenu();
}

void print_ray(int num)
{
	point p1, p2;
	cout << "Введите координаты начала луча:" << endl;
	cin >> p1;
	cout << "Введите произвольную точку на луче:" << endl;
	cin >> p2;
	ray r(p1, p2);
	//bool flag = false;
	//while (!flag)
	//{
	//	try
	//	{
	//		cin >> r;
	//		flag = true;
	//	}
	//	catch (...)
	//	{
	//		cout << "Недостаточно информации" << endl;
	//	}
	//}
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

void paint_field()
{
	int R, G, B;
	R = 84;
	G = 84;
	B = 84;
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	int middle = constants::width / 2;
	int step = 40;
	for (int i = 1; i < constants::width / 2 / step + 1; i++)
	{
		glBegin(GL_LINES);
		glColor3ub(R, G, B);
		glVertex2f(middle + i * step, constants::height);
		glVertex2f(middle + i * step, 0);
		glVertex2f(middle - i * step, constants::height);
		glVertex2f(middle - i * step, 0);
		glEnd();
	}
	glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
	glVertex2f(middle, constants::height);
	glVertex2f(middle, 0);
	glVertex2f(middle, constants::height);
	glVertex2f(middle + 6, constants::height - 15);
	glVertex2f(middle, constants::height);
	glVertex2f(middle - 6, constants::height - 15);
	glEnd();
	middle = constants::height / 2;
	for (int i = 1; i < constants::height / 2 / step + 1; i++)
	{
		glBegin(GL_LINES);
		glColor3ub(R, G, B);
		glVertex2f(0, middle + i * step);
		glVertex2f(constants::width, middle + i * step);
		glVertex2f(0, middle - i * step);
		glVertex2f(constants::width, middle - i * step);
		glEnd();
	}
	glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
	glVertex2f(0, middle);
	glVertex2f(constants::width, middle);
	glVertex2f(constants::width, middle);
	glVertex2f(constants::width - 15, middle + 6);
	glVertex2f(constants::width, middle);
	glVertex2f(constants::width - 15, middle - 6);
	glEnd();
}

void Display(void)
{
	//Пройдемся по списку на отрисовку 
	Node<figure*>* cur = NULL;
	cur = queue.get_head();
	paint_field();
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
