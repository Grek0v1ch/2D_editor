#include "../headers/point.hpp"

// ���������� ��������� ���������
bool Point::operator==(const Point& p) {
	if (_x == p._x && _y == p._y) return true;
	return false;
}

// ���������� ��������� ������
std::ostream& operator<<(std::ostream& fout, const Point& p) {
	fout << "Point: x = " << p._x << ", y = " << p._y << '\n';
	return fout;
}

// ���������� ��������� =
Point& Point::operator=(const Point& value) {
	if (&value == this) return *this;
	_x = value._x;
	_y = value._y;
	return *this;
}