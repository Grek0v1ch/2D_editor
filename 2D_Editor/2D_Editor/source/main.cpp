#include <iostream>
#include "../headers/point.hpp"
#include "../headers/segment.hpp"
#include "../headers/triangle.hpp"

int main() {
	Segment s(Point(0, 0), Point(5, 5));
	std::cout << s;

	Triangle t(Point(0, 0), Point(5, 5), Point(2, 2));
	Triangle f(Point(0, 1), Point(2, 2), Point(5, 5));
	std::cout << t << f;
	std::cout << (t == f) << '\n';
	f = t;
	std::cout << f << '\n';

	return 0;
}