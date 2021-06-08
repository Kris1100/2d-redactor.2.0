#include "Menu.h"

bidir_list<figure*> queue;
bidir_list<elem>all;
bool win = false;
int window;

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
	double x = 0, y = 0;
	point p(x, y);
	add_create(p);
	all.get_tail()->info.obj->mymenu();
}

void print_line(int num)
{
	point p1, p2, p3;
	line l1(p1, p2);
	add_create(l1);
	all.get_tail()->info.obj->mymenu();
}

void print_polygon(int num)
{
	int n = 3;
	polygon p(n);
	add_create(p);
	all.get_tail()->info.obj->mymenu();
}

void print_circle(int num)
{
	circle c(0, 0, 1);
	add_create(c);
	all.get_tail()->info.obj->mymenu();
}

void print_segment(int num)
{
	double x1 = 0, x2 = 0, y1 = 0, y2 = 0;
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
	double x1 = 0, x2 = 0, y1 = 0, y2 = 0;
	point p1(x1, y1);
	point p2(x2, y2);
	myvector v(p1, p2);
	add_create(v);
	all.get_tail()->info.obj->mymenu();
}

void print_ray(int num)
{
	point p1(0, 0), p2(1, 1);
	ray r(p1, p2);
	add_create(r);
	all.get_tail()->info.obj->mymenu();
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
	if (win) 
		glutDestroyWindow(window);
	else 
		win = true;
	window = glutCreateWindow("Let's paint it!");
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(KeyBoard);
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

void KeyBoard(unsigned char key, int x, int y)
{
	if (key == 109)
	{
		print_menu(0, 1);
		invalid();
	}
}

void Reshape(GLint w, GLint h)
{
	glutReshapeWindow(constants::width, constants::height);

	/* ортографическая проекция */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, w, 0, h, -1.0, 1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int invalid()
{
	int item = 0;
	while (true)
	{
		int key = _getch();

		if (key == 13)
		{
			switch (item)
			{
			case 0: { queue.~bidir_list(); return 0; }
			case 1: main_pr(); break;
			case 2: print_point(0);  break;
			case 3: print_line(0);  break;
			case 4: print_circle(0); break;
			case 5: print_triangle(0);  break;
			case 6: print_polygon(0);  break;
			case 7: print_segment(0);  break;
			case 8: print_vector(0);  break;
			case 9: print_ray(0); break;
			case 10:
			{
				if (all.get_tail() != NULL) all.get_tail()->info.obj->mymenu();
				else cout << "Вы еще ничего не делали";
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
			case 72: item--; break;
			case 80: item++; break;
			case 48: item = 0; break;
			case 49: item = 1; break;
			case 50: item = 2; break;
			case 51: item = 3; break;
			case 52: item = 4; break;
			case 53: item = 5; break;
			case 54: item = 6; break;
			case 55: item = 7; break;
			case 56: item = 8; break;
			case 57: item = 9; break;
			case 58: item = 10; break;
			}
			print_menu(item, 15);
			if (item < 0)
				item = 10;
			if (item > 10)
				item = 0;
		}
	}
}