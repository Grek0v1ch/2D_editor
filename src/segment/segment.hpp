#ifndef SEGMENT_HPP
#define SEGMENT_HPP

#include <iostream>
#include "../point/point.hpp"

class Segment {
private:
	Point _point1, _point2;

public:
	// Конструкторы.
	Segment() : _point1(0, 0), _point2(0, 0) {};
	Segment(Point point1, Point point2) : _point1(point1), _point2(point2) { if (point1 == point2) throw 1; };
	// Копирования.
	Segment(const Segment& object) : _point1(object._point1), _point2(object._point2) {};

	// Деструктор.
	~Segment() {}

	// Переопределение операторов.
	bool operator==(const Segment&);
	Segment& operator=(const Segment&);
	friend std::ostream& operator<<(std::ostream&, const Segment&);
};

#endif // SEGMENT_HPP