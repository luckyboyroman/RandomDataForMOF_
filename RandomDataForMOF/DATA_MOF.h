#pragma once
#include "Polygon.h"
#include "Point.h"
struct DATA_FOR_MOF
{
	double vcon1, vcon2; // �������� ����
	Point c1, c2; // ���������
	Polygon P; // ������ (�����������)
	void startRand(int N, double x0, double y0, double r);
};
ostream& operator << (ostream& os, const DATA_FOR_MOF& M);
