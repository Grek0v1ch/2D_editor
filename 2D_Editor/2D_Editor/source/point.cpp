#include "../headers/point.hpp"

// Переопределение оператора сравнения (оператор проверяет идентичность двух объектов класса).
bool Point::operator==(const Point& p) {
	if (_x == p._x && _y == p._y) return true;
	return false;
}

// Переопределение оператора вывода (временно, может понадобится переделать как метод класса).
std::ostream& operator<<(std::ostream& fout, const Point& p) {
	fout << "Point: x = " << p._x << ", y = " << p._y << '\n';
	return fout;
}

// Переопределение оператора присваивания.
Point& Point::operator=(const Point& value) {
	if (&value == this) return *this;
	_x = value._x;
	_y = value._y;
	return *this;
}