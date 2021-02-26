#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include"point.h"
#include"polygon.h"
using namespace std;

class triangle : public polygon
{
public:
	triangle();                                                                // constructor
	void set_line_und_angles();                                                // zadat' cherez 2 ugla i pryamuyu
	void define_kind();                                                        // opredelit' vid
	//perimetr i ploschad' nasleduyutsa ot polygona, zrya pisala
	// dlya bissectrisi, mediani, i tp nujna pramaya
	double radius_inside();                                                    // radius vpisannoy okrugnosti
	double radius_outside();                                                   // radius opisannoy
	//ostalas' trigonometriya
	
private:
	vector<point> abc_apexes;
};