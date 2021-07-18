#include "Point.h"
Point::Point() {
	x = 0;
	y = 0;
}
Point::Point(double x, double y) {
	this->x = x;
	this->y = y;
}
Point& Point::operator=(const Point& p) {
	this->x = p.x;
	this->y = p.y;
	return *this;
}
ostream& operator << (ostream& os, const Point& p) {
	os << p.x << " " << p.y;
	return os;
}