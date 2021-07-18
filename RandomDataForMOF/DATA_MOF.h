#pragma once
#include "Polygon.h"
#include "Point.h"
struct DATA_FOR_MOF
{
	double vcon1, vcon2; // объемные доли
	Point c1, c2; // центроиды
	Polygon P; // €чейка (мноугольник)
	void startRand(int N, double x0, double y0, double r);
};
ostream& operator << (ostream& os, const DATA_FOR_MOF& M);
