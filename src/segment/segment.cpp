#include "segment.hpp"

// Переопределение оператора сравнения (оператор проверяет идентичность двух объектов класса).
bool Segment::operator==(const Segment& object) {
	if (_point1 == object._point1 && _point2 == object._point2) return true;
	if (_point1 == object._point2 && _point2 == object._point1) return true;
	return false;
}

// Переопределение оператора вывода (временно, может понадобится переделать как метод класса).
std::ostream& operator<<(std::ostream& out, const Segment& object) {
	out << "Segment, points:\n" << object._point1 << object._point2;
	return out;
}

// Переопределение оператора присваивания.
Segment& Segment::operator=(const Segment& object) {
	if (&object == this) return *this;
	_point1 = object._point1;
	_point2 = object._point2;
	return *this;
}

// Метод рисования отрезка.
void Segment::draw() {
	glBegin(GL_LINES);
		glVertex2f(_point1.get_x(), _point1.get_y());
		glVertex2f(_point2.get_x(), _point2.get_y());
	glEnd();
}