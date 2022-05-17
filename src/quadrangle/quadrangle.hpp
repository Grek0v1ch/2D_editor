#ifndef QUADRILATERAL_HPP
#define QUADRILATERAL_HPP

#include <iostream>
#include "../point/point.hpp"

class Quadrangle {
private:
	Point _vertices[4];
public:
	Quadrangle();
	// В конструкторе есть баг.
	Quadrangle(Point, Point, Point, Point);
	Quadrangle(const Quadrangle&);

	~Quadrangle();

	// Переадресовка операторов.
	Quadrangle& operator=(const Quadrangle&);
	bool operator==(const Quadrangle&);
	friend std::ostream& operator<<(std::ostream&, const Quadrangle&);
	
};

#endif // QUADRILATERAL_HPP
