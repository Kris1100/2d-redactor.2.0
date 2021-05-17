#include "segment.h"
#include"math_const.h"
#include "glut-3.7.6-bin/glut.h"
segment::segment(const point& p1,const point& p2) 
{
	//Отлавливаем ошибку на две одинаковые точки
	try 
	{
		if (p1 == p2) 
			throw "Обе точки отрезка совпадают, будет установлено значение по умолчанию (0,0) и (1,1)";
		//Если все хорошо создаем отрезок с полученными точками
		set_extm_points(p1, p2);
	}
	catch (const char* err) 
	{
		cout << "Ошибка: " << err<<endl;
		//В случае ошибки задаем значение по умолчанию
		point d1(0, 0);
		point d2(1, 1);
		set_extm_points(d1, d2);
	}
}
segment::segment(const segment& s) 
{
	p1_ = s.get_start();
	p2_ = s.get_end();
}

void segment::set_extm_points(const point& p1,const point& p2)
{
	p1_ = p1;
	p2_ = p2;
}

double segment::len() const
{
	return round(sqrt( ((p1_.get_x() - p2_.get_x()) * (p1_.get_x() - p2_.get_x()))
			   + ((p1_.get_y() - p2_.get_y()) * (p1_.get_y() - p2_.get_y())) )*constants::rd)/constants::rd;
}

point segment::middle() const
{
	double x = (p1_.get_x() + p2_.get_x()) / 2;
	double y = (p1_.get_y() + p2_.get_y()) / 2;
	return point(x, y);
}

void segment::draw()  
{
	glLineWidth(3);
	glBegin(GL_LINES);
	      glColor3ub(255, 203, 219);
	      glVertex2f(p1_.centerize().get_x(), p1_.centerize().get_y());
		  glColor3ub(255, 107, 142);
	      glVertex2f(p2_.centerize().get_x(), p2_.centerize().get_y());
	glEnd();
}