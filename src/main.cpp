#include <iostream>
#include "point/point.hpp"
#include "segment/segment.hpp"
#include "triangle/triangle.hpp"
#include "quadrangle/quadrangle.hpp"
#include "ellipse/ellipse.hpp"

int main() {
	Segment s(Point(0, 0), Point(5, 5));
	std::cout << s;

	Triangle t(Point(0, 0), Point(5, 5), Point(2, 2));
	Triangle f(Point(0, 1), Point(2, 2), Point(5, 5));
	std::cout << t << f;
	std::cout << (t == f) << '\n';
	f = t;
	std::cout << f << '\n';

	Quadrangle a(Point(0, 0), Point(1, 0), Point(1, 1), Point(0, 1));
	Quadrangle b(Point(1, 0), Point(0, 0), Point(1, 1), Point(0, 1));
	std::cout << a << b;
	std::cout << (a == b) << '\n';
	a = b;
	std::cout << a << '\n';

	Ellipse c(Point(0, 0), 2, 5);
	Ellipse d(Point(0, 1), 4, 8);
	std::cout << c << d;
	std::cout << (c == d) << '\n';
	c = d;
	std::cout << c << '\n';
	return 0;
}	