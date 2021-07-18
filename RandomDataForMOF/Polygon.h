#pragma once
#include "Point.h"
class Polygon {
	int N; // ���-�� ������
	Point p0; // ����� �������������� 
	vector <Point> p; // ������ ������
	double sqr; // �������
public:
	Polygon() {};
	Polygon(int N);
	void setN(int N);
	void setRandomPoints(double x0, double y0, double r);
	void setPoints(const Point& p0, const vector <Point>& p);
	double lenSide(Point p1, Point p2);
	double square();
	Point getRandomCentroid();
	bool belongPoly(Point p);
	friend ostream& operator << (ostream& os, const Polygon P);
};

