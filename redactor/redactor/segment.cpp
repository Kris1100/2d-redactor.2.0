#include "segment.h"

segment::segment(const point& p1,const point& p2) 
{
	//����������� ������ �� ��� ���������� �����
	try 
	{
		if (p1 == p2) throw "��� ����� ������� ���������, ����� ����������� �������� �� ��������� (0,0) � (1,1)";
		//���� ��� ������ ������� ������� � ����������� �������
		set_extm_points(p1, p2);
	}
	catch (const char* err) {
		cout << "������: " << err<<endl;
		//� ������ ������ ������ �������� �� ���������
		point d1(0, 0);
		point d2(1, 1);
		set_extm_points(d1, d2);
	}
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

bool segment::is_elememt(const line& l) const
{
	if (p1_.is_element(l) && p2_.is_element(l))
		return true;
	return false;
}

bool segment::is_elememt(const ray& r) const
{
	if (p1_.is_element(r) && p2_.is_element(r))
		return true;
	return false;
}