#include "Triangle.h"
#include"segment.h"

triangle::triangle()
{
	point* vert = new point[3];
	vertex = vert;
}

triangle::~triangle()
{
	delete[]vertex;
	vertex = nullptr;
}

std::istream& operator>>(istream& in, triangle& abc)
{
	double x, y;
	cout << "Введите координаты вершин:" << endl;
	for (int i = 0; i < 3; i++)
	{
		cin >> x >> y;
		abc.vertex[i].set_x(x);
		abc.vertex[i].set_y(y);
	}
	return in;
}

bool triangle::exists()
{
	point a = vertex[0];
	point b = vertex[1];
	point c = vertex[2];
	segment ab(a,b);
	segment bc(b,c);
	segment ac(a,c);
	if (ab.len() + bc.len() < ac.len() || ab.len() + ac.len() < bc.len() ||
		ac.len() + bc.len() < ab.len())
	{
		return false;
	}
	return true;
}

void triangle::define_kind()
{
	point a = vertex[0];
	point b = vertex[1];
	point c = vertex[2];
	segment ab(a, b);
	segment bc(b, c);
	segment ac(a, c);
	if (exists())
	{
		was_checked_existence = true;
		if (ab.len() == bc.len() == ac.len())
			cout << "Треугольник равносторонний" << endl;
		else
			if (ab.len() == bc.len() || ab.len() == ac.len() || ac.len() == bc.len())
				cout << "Треугольник равнобедренный" << endl;
		if (ab.len() * ab.len() + ac.len() * ac.len() == bc.len() * bc.len() ||
			ab.len() * ab.len() + bc.len() * bc.len() == ac.len() * ac.len() ||
			bc.len() * bc.len() + ac.len() * ac.len() == ab.len() * ab.len())
			cout << "Треугольник прямоугольный" << endl;
	}
	else
	{
		if (!was_checked_existence)
			cout << "Треугольник с такими координатами не существует" << endl;
		was_checked_existence = true;
	}
}

double triangle::radius_inside()
{
	if (exists())
		return 2 * area() / perimetr();
	else
	{
		if (!was_checked_existence)
			cout << "Треугольник с такими координатами не существует" << endl;
		return -1;
	}
}

double triangle::radius_outside()
{
	if (exists())
	{
		double abc_square = area();
		abc_square *= 4;
		point a = vertex[0];
		point b = vertex[1];
		point c = vertex[2];
		segment ab(a, b);
		segment bc(b, c);
		segment ac(a, c);
		return ab.len() * bc.len() * ac.len() / abc_square;
	}
	else
	{
		if (!was_checked_existence)
			cout << "Треугольник с такими координатами не существует" << endl;
		return -1;
	}
}