#pragma once
#include "point.h"
#include <cmath>
#include <math.h>

//����� �������
class segment
{
public:
	//����������� �������
	segment(point& p1, point& p2) {
		set_extm_points(p1, p2);
	}
	segment() {}
	//����������
	~segment() {}
	//������ ������� �����
	void set_extm_points(point& p1, point& p2);
	//�������� ������ �� ��������� ����� (��������� - p1_, � ������ ����� ��� �������, ����� ����� ���������)
	point& get_start() {
		return p1_;
	}
	//������ �� �������� �����
	point& get_end() {
		return p2_;
	}
	//����� �������
	double len();
	//���������� �������� �������
	point middle();

protected:
	point p1_;
	point p2_;
};

