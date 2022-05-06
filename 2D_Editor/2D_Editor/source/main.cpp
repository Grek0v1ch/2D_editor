#include <iostream>
#include "../headers/point.hpp"
#include "../headers/segment.hpp"
#include "../headers/quadrilateral.hpp"

int main() {
	Quadrilateral a(Point(0, 0), Point(1, 0), Point(1, 1), Point(0, 1));
	std::cout << a;
	Quadrilateral b(Point(0, 0), Point(1, 0), Point(1, 1), Point(0, 1));
	std::cout << (a == b) << '\n';
	Quadrilateral c(Point(1, 0), Point(0, 0), Point(1, 1), Point(0, 1));
	std::cout << (a == c) << '\n';
	a = c;
	std::cout << a;
	return 0;
}