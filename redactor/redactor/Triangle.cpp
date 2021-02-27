#include "Triangle.h"
//#include"segment.h"
triangle::triangle()
{
	point* vert = new point[3];
	set_point_array(vert);
	delete[]vert;
	for (int i = 0; i < 3; i++)
		abc_apexes.push_back(vertex[i]);
	// mne ne nravitsya, peredelayu
}

void triangle::set_line_und_angles()
{
	//tut doljen byt' cod s pryamoy, no yeyo (ne yego) escho net
}

void triangle::define_kind()
{
	triangle abc;
	point a = abc.abc_apexes[0];
	point b = abc.abc_apexes[1];
	point c = abc.abc_apexes[2];
	double dist_ab = sqrt( (a.get_x() - b.get_x()) * (a.get_x() - b.get_x()) 
		                 + (a.get_y() - b.get_y()) * (a.get_y() - b.get_y()) );
	double dist_bc = sqrt( (b.get_x() - c.get_x()) * (c.get_x() - b.get_x())
		                 + (c.get_y() - b.get_y()) * (c.get_y() - b.get_y()) );
	double dist_ac = sqrt( (a.get_x() - c.get_x()) * (a.get_x() - c.get_x())
		                 + (a.get_y() - c.get_y()) * (a.get_y() - c.get_y()) );
	if (dist_ab + dist_bc < dist_ac || dist_ab + dist_ac < dist_bc ||
		dist_ac + dist_bc < dist_ab)
	{
		cout << "doesn't exist" << endl;
		return;
	}
	if (dist_ab == dist_bc == dist_ac)
		cout << "ravnostoronniy" << endl;
	else
		if (dist_ab == dist_bc || dist_ab == dist_ac || dist_ac == dist_bc)
			cout << "ravnobedrenniy" << endl;
	if (dist_ab * dist_ab + dist_ac * dist_ac == dist_bc * dist_bc ||
		dist_ab * dist_ab + dist_bc * dist_bc == dist_ac * dist_ac ||
		dist_bc * dist_bc + dist_ac * dist_ac == dist_ab * dist_ab)
		cout << "pramougolniy" << endl;
	//nado dobavit' tupo- i ostrougolniye, kogda poyavitsa pramaya
}

double triangle::radius_inside()
{
	triangle abc;
	double square = abc.area();
	double perimetr = abc.perimetr();
	// hochu destructor
	return 2 * square / perimetr;
}

double triangle::radius_outside()
{
	triangle abc;
	double square = abc.area();
	square *= 4;
	point a = abc.abc_apexes[0];
	point b = abc.abc_apexes[1];
	point c = abc.abc_apexes[2];
	double dist_ab = sqrt( (a.get_x() - b.get_x()) * (a.get_x() - b.get_x())
		                 + (a.get_y() - b.get_y()) * (a.get_y() - b.get_y()) );
	double dist_bc = sqrt( (b.get_x() - c.get_x()) * (c.get_x() - b.get_x())
		                 + (c.get_y() - b.get_y()) * (c.get_y() - b.get_y()) );
	double dist_ac = sqrt( (a.get_x() - c.get_x()) * (a.get_x() - c.get_x())
		                 + (a.get_y() - c.get_y()) * (a.get_y() - c.get_y()) );
	return dist_ab * dist_bc * dist_ac / square;
	//≈сли хочешь рассто€ние между точками!!!
	//segment s(vertex[0], vertex[1]);
	//int ss = s.len();
}