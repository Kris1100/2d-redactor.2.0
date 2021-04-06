#pragma once
#include "point.h"
#include "line.h"
#include "ray.h"
#include "math_const.h"
#include <cmath>
#include <math.h>
#include <cassert>
using namespace std;
//����� �������
class segment
{
public:
	//����������� �������
	segment(const point& p1, const point& p2);
	//����������� �� ��������� ��������� ��� ������ vector
	segment() {};
	//����������
	~segment() {}
	//�������� ������ �� ��������� ����� (��������� - p1_, � ������ ����� ��� �������, ����� ����� ���������)
	point get_start() const { return p1_; }
	//������ �� �������� �����
	point get_end() const {	return p2_;	}
	//������ ������� �����
	void set_extm_points(const point& p1,const point& p2);
	//����� �������
	double len() const;
	//���������� �������� �������
	point middle() const;
	//����������� �� ������� ������, ����
	bool is_elememt(const line& l) const;
	bool is_elememt(const ray& r) const;

protected:
	point p1_;
	point p2_;
};

