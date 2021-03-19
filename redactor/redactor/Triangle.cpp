#include "Triangle.h"
#include"segment.h"

triangle::triangle()
{
	point* vert = new point[3];
	abc_apexes = vert;
}

triangle::~triangle()
{
	delete[]abc_apexes;
	abc_apexes = nullptr;
}

std::istream& operator>>(istream& in, triangle& abc)
{
	double x, y;
	cout << "Введите координаты вершин:" << endl;
	for (int i = 0; i < 3; i++)
	{
		cin >> x >> y;
		abc.abc_apexes[i].set_x(x);
		abc.abc_apexes[i].set_y(y);
	}
	return in;
}

bool triangle::exists()
{
	point a = abc_apexes[0];
	point b = abc_apexes[1];
	point c = abc_apexes[2];
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

double triangle::square()
{
	point a = abc_apexes[0];
	point b = abc_apexes[1];
	point c = abc_apexes[2];
	segment ab(a, b);
	segment bc(b, c);
	segment ac(a, c);
	return sqrt(abc_perimetr() * (abc_perimetr() - ab.len()) * 
		(abc_perimetr() - ac.len()) * (abc_perimetr() - bc.len()));
}

double triangle::abc_perimetr()
{
	point a = abc_apexes[0];
	point b = abc_apexes[1];
	point c = abc_apexes[2];
	segment ab(a, b);
	segment bc(b, c);
	segment ac(a, c);
	return ab.len() + bc.len() + ac.len();
}

void triangle::define_kind()
{
	point a = abc_apexes[0];
	point b = abc_apexes[1];
	point c = abc_apexes[2];
	segment ab(a, b);
	segment bc(b, c);
	segment ac(a, c);
	if ((ab.len() + bc.len() > ac.len()) && (ab.len() + ac.len() > bc.len()) &&
		(ac.len() + bc.len() > ab.len()))
	{
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
		cout << "Треугольник с такими координатами не существует" << endl;
}

double triangle::radius_inside()
{
	if (exists())
		return 2 * square() / abc_perimetr();
	else
	{
		cout << "Треугольник с такими координатами не существует" << endl;
		return 1;
	}
}

double triangle::radius_outside()
{
	if (exists())
	{
		double abc_square = square();
		abc_square *= 4;
		point a = abc_apexes[0];
		point b = abc_apexes[1];
		point c = abc_apexes[2];
		segment ab(a, b);
		segment bc(b, c);
		segment ac(a, c);
		return ab.len() * bc.len() * ac.len() / abc_square;
	}
	else
	{
		cout << "Треугольник с такими координатами не существует" << endl;
		return 1;
	}
}