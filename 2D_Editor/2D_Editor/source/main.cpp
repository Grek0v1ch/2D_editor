#include <iostream>
#include "../headers/point.hpp"
#include "../headers/segment.hpp"
#include "../headers/ellipse.hpp"

int main() {
	Ellipse t(Point(0, 0), 2, 5);
	Ellipse f(Point(0, 1), 4, 8);

	std::cout << t << f;
	std::cout << (t == f) << '\n';
	f = t;
	std::cout << f << '\n';

	return 0;
}	