#include <iostream>
#include "point/point.hpp"
#include "segment/segment.hpp"
#include "triangle/triangle.hpp"
#include "quadrangle/quadrangle.hpp"
#include "ellipse/ellipse.hpp"
#include "data_structures/dllist.hpp"
#include "data_structures_test/test.hpp"

int main() {
	bool res = true;
	res = test_is_empty();
	res = test_front();
	res = test_back();
	if (res) std::cout << "All good" << std::endl;
	return 0;
}	