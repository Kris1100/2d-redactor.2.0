#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include"point.h"
#include"polygon.h"
#include"segment.h"
using namespace std;

class triangle : public polygon
{
public:
	triangle();                                                                // �����������
	void define_kind();                                                        // ���������� ��� ������������
	//perimetr i ploschad' nasleduyutsa ot polygona, zrya pisala
	bool exists();                                                             // ����������, ���������� �� �����������
	double radius_inside();                                                    // ������ ��������� ����������
	double radius_outside();                                                   // ������ ��������� ����������
	
private:
	vector<point> abc_apexes;
};