#include <iostream>
#include "../headers/point.hpp"
int main() {
	Point p(1, 2);
	std::cout << p;
	std::cout << "Coord x = " << p.get_x() << std::endl;
	return 0;
}