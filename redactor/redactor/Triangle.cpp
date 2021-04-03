#include "Triangle.h"

const double M_EPS = 0.00000001;

triangle::triangle()
{
	point* vert = new point[3];
	vertex = vert;
}

//triangle::~triangle()
//{
//	delete[]vertex;
//	vertex = nullptr;
//}

void triangle::init()
{
	for (int i = 0; i < 3; i++)
		cin >> vertex[i];
}

bool triangle::exists() const
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

bool triangle::is_equilateral() const
{
	segment ab(vertex[0], vertex[1]);
	segment bc(vertex[1], vertex[2]);
	segment ac(vertex[0], vertex[2]);
	if (ab.len() - bc.len() <= M_EPS && ab.len() - ac.len() <= M_EPS)
		/*почему не работает объ€вленна€ в общем заголовочнике через define константа?*/
		return true;
	else
		return false;
	//ab.~segment();
	//bc.~segment();
	//ac.~segment();
}

bool triangle::is_isosceles() const
{
	segment ab(vertex[0], vertex[1]);
	segment bc(vertex[1], vertex[2]);
	segment ac(vertex[0], vertex[2]);
	if (ab.len() == bc.len() || ab.len() == ac.len() || ac.len() == bc.len())
		return true;
	else
		return false;
	//ab.~segment();
	//bc.~segment();
	//ac.~segment();
}

bool triangle::is_right() const
{
	segment ab(vertex[0], vertex[1]);
	segment bc(vertex[1], vertex[2]);
	segment ac(vertex[0], vertex[2]);
	if (ab.len() * ab.len() + ac.len() * ac.len() - bc.len() * bc.len() <= M_EPS ||
		ab.len() * ab.len() + bc.len() * bc.len() - ac.len() * ac.len() <= M_EPS ||
		bc.len() * bc.len() + ac.len() * ac.len() - ab.len() * ab.len() <= M_EPS)
		return true;
	else
		return false;
	//ab.~segment();
	//bc.~segment();
	//ac.~segment();
}

double triangle::radius_inside() const
{
	if (exists())
		return 2 * area() / perimetr();
	else
	{
			cout << "“реугольник с такими координатами не существует" << endl;
		return -1;
	}
}

double triangle::radius_outside() const
{
	if (exists())
	{
		double abc_square = area();
		segment ab(vertex[0], vertex[1]);
		segment bc(vertex[1], vertex[2]);
		segment ac(vertex[0], vertex[2]);
		return ab.len() * bc.len() * ac.len() / (4 * abc_square);
	}
	else
	{
		cout << "“реугольник с такими координатами не существует" << endl;
	}
}