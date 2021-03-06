#pragma once
#include <cmath>
#include <math.h>
#include <cassert>
#include "point.h"
#include "Figure.h"
#include "math_const.h"
#include "glut-3.7.6-bin/glut.h"
using namespace std;

//����� �������
class segment : public figure
{
public:
	//����������� �������
	segment(const point& p1, const point& p2);
	//����������� �� ��������� ��������� ��� ������ vector
	segment() {};
	//����������� �����������
	segment(const segment& s);
	//����������
	~segment();

	//�������� ������ �� ��������� ����� (��������� - p1_, � ������ ����� ��� �������, ����� ����� ���������)
	point get_start() const {  
		return p1_;
	}
	//������ �� �������� �����
	point get_end() const {
		return p2_;
	}
	//������ ������� �����
	void set_extm_points(const point& p1,const point& p2);
	//����� �������
	double len() const;
	//���������� �������� �������
	point middle() const;
	void is_correct();
	bool point_lay(const point& p) const;

	//���������� �������
	void draw();
	void mymenu();

	//����� �������
	//��������� �����
	friend std::istream& operator>>(std::istream& in, segment& s);

protected:
	point p1_;
	point p2_;
};

