#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include "point.h"
#include <circle.h>
using namespace std;
<<<<<<< HEAD
<<<<<<< HEAD
class my_round : public circle
=======
=======
>>>>>>> 7fd4a1c70be8e07ed46fb135d0319a788675f418

class my_round
>>>>>>> 7fd4a1c70be8e07ed46fb135d0319a788675f418
{
public:
	//������������ ������
	friend ostream& operator<<(ostream& out, const my_round& c);
	//������������ �����
	friend istream& operator>>(istream& in, my_round& p);
	//����������� ����������
	my_round(double x = 0.0, double y = 0.0, double r = 1.0);
	//���������� ������� �����
	double get_square() const;
	//���������� ������� ��������, �������� - ���� � ��������
	double get_square_of_segment(double a = 1) const;

<<<<<<< HEAD
=======
	point get_p();

>>>>>>> 7fd4a1c70be8e07ed46fb135d0319a788675f418
private:
	point* _p;
	double _r;
};
