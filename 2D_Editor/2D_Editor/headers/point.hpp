#ifndef POINT_HPP
#define POINT_HPP

#include<iostream>

class Point {
private:
	double _x, _y;

public:
	Point() : _x(0), _y(0) {};
	Point(double x, double y) : _x(x), _y(y) {};
	Point(const Point& object) : _x(object._x), _y(object._y) {};

	~Point() { _x = 0; _y = 0; }

	// Переопределение операторов.
	bool operator==(const Point&);
	Point& operator=(const Point&);
	friend std::ostream& operator<<(std::ostream&, const Point&);

	double get_x() const { return _x; }
	double get_y() const { return _y; }
};

#endif // POINT_HPP