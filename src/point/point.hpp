#ifndef POINT_HPP
#define POINT_HPP

#include<iostream>

class Point {
private:
	double _x, _y;

public:
	// Конструкторы.
	Point() : _x(0), _y(0) {};
	Point(double x, double y) : _x(x), _y(y) {};
	// Копирования.
	Point(const Point& object) : _x(object._x), _y(object._y) {};
	
	// Деструктор.
	~Point() {}

	// Переопределение операторов.
	bool operator==(const Point&);
	Point& operator=(const Point&);
	friend std::ostream& operator<<(std::ostream&, const Point&);

	// Методы гетеры.
	double get_x() const { return _x; }
	double get_y() const { return _y; }
};

#endif // POINT_HPP