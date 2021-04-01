#include "Triangle.h"
#include"segment.h"

triangle::triangle()
{
	point* vert = new point[3];
	set_point_array(vert);
	for (int i = 0; i < 3; i++)
		abc_apexes.push_back(vertex[i]);
}

triangle::~triangle()
{
	abc_apexes.clear();
	delete[]vertex;
}

bool triangle::exists()
{
	triangle abc;
	point a = abc.abc_apexes[0];
	point b = abc.abc_apexes[1];
	point c = abc.abc_apexes[2];
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
	triangle abc;
	point a = abc.abc_apexes[0];
	point b = abc.abc_apexes[1];
	point c = abc.abc_apexes[2];
	segment ab(a, b);
	segment bc(b, c);
	segment ac(a, c);
	return sqrt(abc.perimetr() * (abc.perimetr() - ab.len()) * 
		(abc.perimetr() - ac.len()) * (abc.perimetr() - bc.len()));
}

double triangle::perimetr()
{
	triangle abc;
	point a = abc.abc_apexes[0];
	point b = abc.abc_apexes[1];
	point c = abc.abc_apexes[2];
	segment ab(a, b);
	segment bc(b, c);
	segment ac(a, c);
	return ab.len() + bc.len() + ac.len();
}

void triangle::define_kind()
{
	triangle abc;
	point a = abc.abc_apexes[0];
	point b = abc.abc_apexes[1];
	point c = abc.abc_apexes[2];
	segment ab(a, b);
	segment bc(b, c);
	segment ac(a, c);
	if (ab.len() + bc.len() > ac.len() && ab.len() + ac.len() > bc.len() &&
		ac.len() + bc.len() > ab.len())
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
	// нужно добавить остро- и тупоугольность
}

double triangle::radius_inside()
{
	triangle abc;
	//if (abc.exists())
		return 2 * abc.square() / abc.perimetr();
	//else
	//{
	//	cout << "Треугольник с такими координатами не существует" << endl;
	//	return 1;
	//}
}

double triangle::radius_outside()
{
	triangle abc;
	//if (abc.exists())
	//{
		double square = abc.square();
		square *= 4;
		point a = abc.abc_apexes[0];
		point b = abc.abc_apexes[1];
		point c = abc.abc_apexes[2];
		segment ab(a, b);
		segment bc(b, c);
		segment ac(a, c);
		return ab.len() * bc.len() * ac.len() / square;
	//}
	//else
	//{
	//	cout << "Треугольник с такими координатами не существует" << endl;
	//	return 1;
	//}
}