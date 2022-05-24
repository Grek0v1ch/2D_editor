#ifndef QUADRILATERAL_HPP
#define QUADRILATERAL_HPP

#include <iostream>
#include "../point/point.hpp"

class Quadrangle {
private:
	Point _vertices[4];
public:
	// Конструкторы.
	Quadrangle();
	// В конструкторе есть баг.
	Quadrangle(Point, Point, Point, Point);
	// Копирования.
	Quadrangle(const Quadrangle&);

	// Деструктор.
	~Quadrangle() {}

	// Переадресовка операторов.
	Quadrangle& operator=(const Quadrangle&);
	bool operator==(const Quadrangle&);
	friend std::ostream& operator<<(std::ostream&, const Quadrangle&);
};

#endif // QUADRILATERAL_HPP
