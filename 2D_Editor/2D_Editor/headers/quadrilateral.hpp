#ifndef QUADRILATERAL_HPP
#define QUADRILATERAL_HPP

#include <iostream>
#include "point.hpp"

class Quadrilateral {
private:
	Point _vertices[4];
public:
	Quadrilateral();
	// В конструкторе есть баг.
	Quadrilateral(Point, Point, Point, Point);
	Quadrilateral(const Quadrilateral&);

	~Quadrilateral();

	// Переадресовка операторов.
	Quadrilateral& operator=(const Quadrilateral&);
	bool operator==(const Quadrilateral&);
	friend std::ostream& operator<<(std::ostream&, const Quadrilateral&);
	
};

#endif // QUADRILATERAL_HPP
