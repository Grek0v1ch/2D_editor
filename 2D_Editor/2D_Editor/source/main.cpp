#include <iostream>
#include "../headers/point.hpp"
#include "../headers/segment.hpp"

int main() {
	Segment s(Point(0, 0), Point(5, 5));
	std::cout << s;
	return 0;
}