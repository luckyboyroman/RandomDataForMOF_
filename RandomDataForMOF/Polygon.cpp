#include "Polygon.h"
Polygon::Polygon(int N) {
	this->N = N;
	p.resize(N);
}
void Polygon::setN(int N) {
	this->N = N;
	p.resize(N);
}
double Polygon::lenSide(Point p1, Point p2) {
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}
void Polygon::setRandomPoints(double x0, double y0, double r) {
	p0.x = x0;
	p0.y = y0;
	double a = 0;
	for (int i = 0; i < N; i++) {
		a += (43.0 + (rand() % 20)) * M_PI / 180.0;
		if (a > 2 * M_PI)
			throw runtime_error("angle>2M_PI");
		p[i].x = x0 + r * cos(a);
		p[i].y = y0 + r * sin(a);
	}
}
void Polygon::setPoints(const Point& p0, const vector<Point>& p) {
	if (p.size() != N) {
		cout << "Error N\n";
		system("pause");
	}
	this->p0 = p0;
	for (int i = 0; i < N; i++) {
		this->p[i] = p[i];
	}
}
double Polygon::square() {
	double a, b, c, per;
	double sqr = 0;
	for (int i = 0; i < N; i++) {
		if (i == N - 1) {
			a = lenSide(p0, p[i]);
			b = lenSide(p0, p[0]);
			c = lenSide(p[i], p[0]);
		}
		else {
			a = lenSide(p0, p[i]);
			b = lenSide(p0, p[i + 1]);
			c = lenSide(p[i], p[i + 1]);
		}
		per = (a + b + c) / 2;
		sqr += sqrt(per * (per - a) * (per - b) * (per - c));
	}
	this->sqr = sqr;
	return sqr;
}
Point Polygon::getRandomCentroid() {
	Point c;
	Point max, min; // для макс и мин координаты (не точки!)
	max = p[0];
	min = p[0];
	for (int i = 1; i < N; i++) {
		if (max.x > p[i].x)
			max.x = p[i].x;

		if (max.y > p[i].y)
			max.y = p[i].y;

		if (min.x < p[i].x)
			min.x = p[i].x;

		if (min.y < p[i].y)
			min.y = p[i].y;
	}
	do {
		c.x = (double)(rand()) / RAND_MAX * (max.x - min.x) + min.x;
		c.y = (double)(rand()) / RAND_MAX * (max.y - min.y) + min.y;
	} while (!belongPoly(c));

	return c;
}
bool Polygon::belongPoly(Point point) {
	bool result = false;
	int j = N - 1;
	for (int i = 0; i < N; i++) {
		if ((p[i].y < point.y && p[j].y >= point.y || p[j].y < point.y && p[i].y >= point.y) &&
			(p[i].x + (point.y - p[i].y) / (p[j].y - p[i].y) * (p[j].x - p[i].x) < point.x))
			result = !result;
		j = i;
	}
	return result;
}
ostream& operator << (ostream& os, Polygon P) {
	for (int i = 0; i < P.N; i++) {
		os << P.p[i] << " ";
	}
	return os;
}