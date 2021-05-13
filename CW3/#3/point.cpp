#include"point.h"
Point::Point(float x, float y) {
	X = x;
	Y = y;
}
float Point::len(Point point) {
	return sqrt((X - point.X) * (X - point.X) + (Y - point.Y) * (Y - point.Y));
}