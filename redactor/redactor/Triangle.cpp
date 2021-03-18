#include "Triangle.h"

triangle::triangle()
{
	point* vert = new point[3];
	set_point_array(vert);
	for (int i = 0; i < 3; i++)
		abc_apexes.push_back(vertex[i]);
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

void triangle::define_kind()
{
	triangle abc;
	point a = abc.abc_apexes[0];
	point b = abc.abc_apexes[1];
	point c = abc.abc_apexes[2];
	segment ab(a, b);
	segment bc(b, c);
	segment ac(a, c);
	if (!abc.exists())
	{
		cout << "doesn't exist" << endl;
		return;
	}
	if (ab.len() == bc.len() == ac.len())
		cout << "равносторонний" << endl;
	else
		if (ab.len() == bc.len() || ab.len() == ac.len() || ac.len() == bc.len())
			cout << "равнобедренный" << endl;
	if (ab.len() * ab.len() + ac.len() * ac.len() == bc.len() * bc.len() ||
		ab.len() * ab.len() + bc.len() * bc.len() == ac.len() * ac.len() ||
		bc.len() * bc.len() + ac.len() * ac.len() == ab.len() * ab.len())
		cout << "пр€моугольный" << endl;
	// нужно добавить остро- и тупоугольность
}

double triangle::radius_inside()
{
	triangle abc;
	if (!abc.exists())
	{
		cout << "doesn't exist" << endl;
		return 1;
	}
	double square = abc.area();
	double perimetr = abc.perimetr();
	// hochu destructor
	return 2 * square / perimetr;
}

double triangle::radius_outside()
{
	triangle abc;
	if (!abc.exists())
	{
		cout << "doesn't exist" << endl;
		return 1;
	}
	double square = abc.area();
	square *= 4;
	point a = abc.abc_apexes[0];
	point b = abc.abc_apexes[1];
	point c = abc.abc_apexes[2];
	segment ab(a, b);
	segment bc(b, c);
	segment ac(a, c);
	return ab.len() * bc.len() * ac.len() / square;
}