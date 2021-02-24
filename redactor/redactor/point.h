#pragma once
#include<iostream>
#include <cmath>
using namespace std;
class point
{
public:
	point(double x=0, double y=0);
	double get_x();
	void set_x(double x);
	double get_y();
	void set_y(double y);
	void quarter();
	double dist();
	void bisector();
private:
	double _x, _y;
};

