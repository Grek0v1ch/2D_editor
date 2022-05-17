#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <iostream>
#include "../point/point.hpp"

class Triangle {
private:
	Point _vertices[3];
public:
	// Конструкторы:
	Triangle();
	Triangle(Point, Point, Point);
	// Копирования.
	Triangle(const Triangle&);
	
	// Деструктор.
	~Triangle();

	// Переопределение операторов.
	Triangle& operator=(const Triangle&);
	bool operator==(const Triangle&);
	friend std::ostream& operator<<(std::ostream&, const Triangle&);
};

#endif // TRIANGLE_HPP