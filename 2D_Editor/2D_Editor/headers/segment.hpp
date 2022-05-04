#ifndef SEGMENT_HPP
#define SEGMENT_HPP

#include <iostream>
#include "point.hpp"

class Segment {
private:
	Point _point1, _point2;

public:
	Segment() : _point1(0, 0), _point2(0, 0) {};
	Segment(Point point1, Point point2) : _point1(point1), _point2(point2) {};
	Segment(const Segment& object) : _point1(object._point1), _point2(object._point2) {};

	~Segment() { _point1 = Point(0, 0); _point2 = Point(0, 0); }

	// Переопределение операторов.
	bool operator==(const Segment&);
	Segment& operator=(const Segment&);
	friend std::ostream& operator<<(std::ostream&, const Segment&);
};

#endif // SEGMENT_HPP