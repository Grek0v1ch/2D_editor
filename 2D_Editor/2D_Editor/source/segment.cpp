#include "../headers/segment.hpp"

// ���������� ��������� ���������
bool Segment::operator==(const Segment& object) {
	if (_point1 == object._point1 && _point2 == object._point2) return true;
	if (_point1 == object._point2 && _point2 == object._point1) return true;
	return false;
}

// ���������� ��������� ������
std::ostream& operator<<(std::ostream& out, const Segment& object) {
	out << "Segment, points:\n" << object._point1 << object._point2;
	return out;
}

// ���������� ��������� =
Segment& Segment::operator=(const Segment& object) {
	if (&object == this) return *this;
	_point1 = object._point1;
	_point2 = object._point2;
	return *this;
}