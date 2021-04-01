#include "polygon.h"

polygon::polygon(int num_vert)
{
	if (num_vert < 3)
		num_vert = 3;
	set_num(num_vert);
	point* vert = new point[num_vert];
	set_point_array(vert);                  
}

polygon::~polygon()
{
	delete[] vertex;
	vertex = nullptr;
}

std::istream& operator>>(istream& in, polygon& p)
{
	double x, y;
	cout << "Введите координаты " << p.num_vert_ << " вершин";
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
	out << "Количество углов " << p.num_vert_ << endl;
	for (int i = 0; i < p.num_vert_; i++)
	{
		out << "x= " << p.vertex[i].get_x() << " y= " << p.vertex[i].get_y() << endl;
	}
	return out;
}

void polygon::set_point_array(point* vert) 
{
	vertex = vert;
}

void polygon::set_num(int num_vert)
{
	num_vert_ = num_vert;
}

int polygon::get_num()const
{
	return num_vert_;
}

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
	double s1 = 0, s2 = 0, s = 0;                          // можно добавить комментарий с общей идеей: я дурачок, мне непонятно
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
		cout << "x= " << vertex[i].get_x() << " y= " << vertex[i].get_y() << endl;
	}
}

bool polygon::is_convex() const
{
	//Многоугольник будет выпуклым если при его обходе в каждой тройке последовательных вершин 
	//происходит поворот всегда в одну и ту же сторону. При обходе многоугольника против часовой
	//стрелки поворот будет всегда налево, а при обходе по часовой - направо.
	//Для поворота налево это(значение формулы в total) значение будет положительным, а для поворота направо - отрицательным.
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
	v1.~myvector();
	v2.~myvector();
	v3.~myvector();
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
				//Если очередная сторона не равна шаблону, то многоугольник неправильный
				if (side != s.len())
					return false;
			//Создаем два вектора, между которыми будем определять угол
			myvector v1(vertex[i], vertex[i + 1]);
			myvector v2(vertex[i + 1], vertex[i + 2]);
			//Далее логика аналогично проберке сторон
			if (ang == -1)
				ang = angle(v1, v2);
			else
				if (ang != angle(v1, v2))
					return false;
		}
		//Отдельная проверка для последней стороны, тк к ней трудно обратиться с помощью цикла
		segment s(vertex[num_vert_ - 1], vertex[0]);
		myvector v1(vertex[num_vert_ - 1], vertex[0]);
		myvector v2(vertex[0], vertex[1]);
		if (side != s.len())
			return false;
		if (ang != angle(v1, v2))
			return false;
		//Удалим вспомогательные элементы
		s.~segment();
		v1.~myvector();
		v2.~myvector();
 		return true;
	}
}