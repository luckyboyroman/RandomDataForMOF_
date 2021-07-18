#pragma once
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
using namespace std;
struct Point
{
	double x, y;
	Point();
	Point(double x, double y);
	Point& operator =(const Point& p);
};
ostream& operator << (ostream& os, const Point& p);