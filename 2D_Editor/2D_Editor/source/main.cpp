#include <iostream>
#include "../headers/point.hpp"
#include "../headers/segment.hpp"
#include "../headers/triangle.hpp"
#include "../headers/quadrilateral.hpp"

int main() {
	Segment s(Point(0, 0), Point(5, 5));
	std::cout << s;

	Triangle t(Point(0, 0), Point(5, 5), Point(2, 2));
	Triangle f(Point(0, 1), Point(2, 2), Point(5, 5));
	std::cout << t << f;
	std::cout << (t == f) << '\n';
	f = t;
	std::cout << f << '\n';

	Quadrilateral a(Point(0, 0), Point(1, 0), Point(1, 1), Point(0, 1));
	Quadrilateral b(Point(1, 0), Point(0, 0), Point(1, 1), Point(0, 1));
	std::cout << a << b;
	std::cout << (a == b) << '\n';
	a = b;
	std::cout << a << '\n';
	return 0;
}