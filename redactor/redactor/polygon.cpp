#include "polygon.h"

//Конструкторы и деструкторы
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
	num_vert_ = t.num_vert_;
	vertex = new point[num_vert_];
	for (int i = 0; i < num_vert_; i++) 
	{
		vertex[i] = t.vertex[i];
	}
}

polygon::~polygon()
{
	delete[] vertex;
	vertex = nullptr;
}

//Сеттеры
void polygon::set_point_array(point* vert)
{
	//По умолчанию орпеделяем правильный n- угольник, однако он может не определяться как 
	//правильный из-за пограшности измерений (при больших значениях num_vert_). 
	//Этот баг я постараюсь минимизировать
	vertex = vert;
	//Установим единичную окружность
	int R = 1;
	//Начальный угол
	double ang = 0;
	for (int i = 0; i < num_vert_; i++)
	{
		//Посчитаем коррдинаты очередной точки - координаты вектора с началом в точке (0,0), 
		//повернутого на угол ang против часовой стрелки
		vertex[i].set_x(R * round(cos(ang * constants::pi / 180) * constants::rd) / constants::rd);
		vertex[i].set_y(R * round(sin(ang * constants::pi / 180) * constants::rd) / constants::rd);
		//Поменяем угол
		ang += (360 / num_vert_);
	}
}

void polygon::set_num(size_t num_vert)
{
	num_vert_ = num_vert;
}

//Основные функции класса
double polygon::perimetr() const
{
	double p = 0;
	for (int i = 0; i < num_vert_ - 1; i++)
	{
		segment s(vertex[i], vertex[i + 1]);
		p += s.len();
	}
	segment s(vertex[num_vert_ - 1], vertex[0]);
	p += s.len();
	s.~segment();
	return p;
}

double polygon::area() const
{
	//Используем формулу площади Гаусса https://cpp.mazurok.com/tag/%D0%BF%D0%BB%D0%BE%D1%89%D0%B0%D0%B4%D1%8C-%D0%BC%D0%BD%D0%BE%D0%B3%D0%BE%D1%83%D0%B3%D0%BE%D0%BB%D1%8C%D0%BD%D0%B8%D0%BA%D0%B0/#:~:text=%D0%94%D0%BB%D1%8F%20%D1%82%D0%BE%D0%B3%D0%BE%2C%20%D1%87%D1%82%D0%BE%D0%B1%D1%8B%20%D0%B2%D1%8B%D1%87%D0%B8%D1%81%D0%BB%D0%B8%D1%82%D1%8C%20%D0%B5%D0%B3%D0%BE,%D0%BF%D1%80%D0%BE%D0%B8%D0%B7%D0%B2%D0%BE%D0%BB%D1%8C%D0%BD%D0%BE%D0%B3%D0%BE%20%D0%BC%D0%BD%D0%BE%D0%B3%D0%BE%D1%83%D0%B3%D0%BE%D0%BB%D1%8C%D0%BD%D0%B8%D0%BA%D0%B0%20%D0%BC%D0%BE%D0%B6%D0%BD%D0%BE%20%D0%BF%D1%80%D0%BE%D1%87%D0%B5%D1%81%D1%82%D1%8C%20%D0%B7%D0%B4%D0%B5%D1%81%D1%8C.
	double s1 = 0, s2 = 0, s = 0;
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

void polygon::print() const
{
	for (int i = 0; i < num_vert_; i++)
	{
		cout << "x = " << vertex[i].get_x() << ", y = " << vertex[i].get_y() << endl;
	}
}

bool polygon::is_convex() const
{
	//Многоугольник будет выпуклым если при его обходе в каждой тройке последовательных вершин 
	//происходит поворот всегда в одну и ту же сторону. При обходе многоугольника против часовой
	//стрелки поворот будет всегда налево, а при обходе по часовой - направо.
	//Для поворота налево это(значение формулы в total) значение будет положительным,
	//а для поворота направо - отрицательным.
	int sign = 0;
	//Перебираем все тройки вершин, к которым можем циклически обратиться
	for (int i = 0; i < num_vert_ - 2; i++)
	{
		//Зададим два вектора через три вершины (одна вершина общая)
		myvector v1(vertex[i], vertex[i + 1]);
		myvector v2(vertex[i + 1], vertex[i + 2]);
		//Вычисляем векторное произведение данных векторов
		double total = v1.get_x() * v2.get_y() - v1.get_y() * v2.get_x();
		//Проверяем, сохраняется ли знак
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
	//Отдельно рассматриваем две последние тройки, делаем тоже самое
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
	//Проверка на выпуклость. Невыпуклый многоугольник не является правильным.
	//Многоугольник является правильным, если все его стороны и углы равны
	if (not convexity)
		return false;
	else
	{
		double side = -1; double ang = -1;
		//Пройдемся по всем сторонам, кроме последней
		for (int i = 0; i < num_vert_ - 1; i++)
		{
			segment s(vertex[i], vertex[i + 1]);
			//Если мы первый раз вычисляем длину стороны, то нам пока не с чем ее сранивать. Зададим сторону (шаблон)
			if (side == -1)
				side = s.len();
			else
			{
				//Если очередная сторона не равна шаблону, то многоугольник неправильный
				double d = abs(s.len() - side);
				if (d > constants::eps)
					return false;
			}
			//Создаем два вектора, между которыми будем определять угол
			myvector v1(vertex[i + 1], vertex[i]);
			point p;
			if (i == num_vert_ - 2)
				p = vertex[0];
			else
				p = vertex[i + 2];
			myvector v2(vertex[i + 1], p);
			//Далее логика аналогично проверке сторон
			if (ang == -1)
				ang = angle(v1, v2);
			else
			{
				double d = abs(ang - angle(v1, v2));
				if (d > constants::eps)
					return false;
			}
		}
		//Отдельная проверка для последней стороны, тк к ней трудно обратиться с помощью цикла
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
	glBegin(GL_POLYGON);
	int R = 220, G = 208, B = 255;
	for (int i = 0; i < num_vert_; i++) 
	{
		glColor3f(R, G, B);
		glVertex2f(vertex[i].centerize().get_x(), vertex[i].centerize().get_y());
	}
	glEnd;
	glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
	for (int i = 0; i < num_vert_ - 1; i++)
	{
		glVertex2f(vertex[i].centerize().get_x(), vertex[i].centerize().get_y());
		glVertex2f(vertex[i + 1].centerize().get_x(), vertex[i + 1].centerize().get_y());
	}
	glEnd();
}

//Friend функции
std::istream& operator>>(istream& in, polygon& p)
{
	double x, y;
	cout << "Введите координаты " << p.num_vert_ << " вершин:" << endl;
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
	out << "Количество углов: " << p.num_vert_ << endl;
	for (int i = 0; i < p.num_vert_; i++)
	{
		out << "x = " << p.vertex[i].get_x() << ", y = " << p.vertex[i].get_y() << endl;
	}
	return out;
}
void polygon::mymenu() {
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
				cout << "Работа завершена, перейдите в главное меню" << endl;
				return;
			}
			case 1: cin >> *this; break;
			case 2:
			{
				double per = this->perimetr();
				cout << "Периметр: " << per << endl;
			}
			break;
			case 3:
			{
				double sq = this->area();
				cout << "Площадь: " << sq << endl;
			}
			break;
			case 4:
			{
				bool f = this->is_convex();
				if (f)
					cout << "Многоугольник выпуклый" << endl;
				else
					cout << "Многоугольник невыпуклый" << endl;;
			}
			break;
			case 5:
			{
				if (this->is_regular(this->is_convex()))
					cout << "Многоугольник правильный" << endl;
				else
					cout << "Многоугольник не является правильным" << endl;
			}
			break;
			case 6:
			{
				if (not this->is_drawn) {
					add_draw(*this);
					cout << "Объект успешно добавлен в очередь на отрисовку, вы увидите его, когда завершите работу";
					this->is_drawn = true;
				}
				else {
					cout << "Объект уже в очереди на отрисовку";
				}
			}
			break;
			case 7:
			{
				if (this->is_drawn) {
					roll_back_draw();
					this->is_drawn = false;
					cout << "Объект успешно удален из очерди на отрисовку";
				}
				else cout << "Вы еще не нарисовали объект";
			}
			break;
			case 8:
			{
				roll_back_create();
				cout << "Объект успешно удален,перейдите в главное меню";
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
			}
			print_inmenu(item, 15, commands);
			if (item < 0)
				item = commands.size() + 1;
			if (item > commands.size() + 1)
				item = 0;
		}
	}
}