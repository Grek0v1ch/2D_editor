#include "triangle.hpp"

// Конструкторы:
Triangle::Triangle() : _vertices{Point(0, 0), Point(0, 0), Point(0, 0)} {}

Triangle::Triangle(Point point1, Point point2, Point point3) : _vertices{point1, point2, point3} {
	if (point1 == point2 || point1 == point3 || point2 == point3) throw 1;
}

// Копирования.
Triangle::Triangle(const Triangle& object) {
	for (int i = 0; i < 3; i++)
		_vertices[i] = object._vertices[i];
}

// Переопределение оператора присваивания.
Triangle& Triangle::operator=(const Triangle& value) {
	if (&value == this) return *this;
	for (int i = 0; i < 3; i++)
		_vertices[i] = value._vertices[i];
	return *this;
}

// Переопределение оператора сравнения (оператор проверяет идентичность двух объектов класса).
bool Triangle::operator==(const Triangle& object) {
	for (int i = 0; i < 3; i++) {
		bool flag = false;
		for (int j = 0; j < 3; j++)
			if (_vertices[i] == object._vertices[j]) flag = true;
		if (!flag) return false;
	}
	return true;
}

// Переопределение оператора вывода.
std::ostream& operator<<(std::ostream& fout, const Triangle& object) {
	fout << "Triangle, vertices: " << '\n' << object._vertices[0] << object._vertices[1] << object._vertices[2] << '\n';
	return fout;
}

// Метод рисования треугольника.
void Triangle::draw() {
	glLineWidth(3);
	glBegin(GL_LINE_LOOP);
		glVertex2f(_vertices[0].get_x(), _vertices[0].get_y());
		glVertex2f(_vertices[1].get_x(), _vertices[1].get_y());
		glVertex2f(_vertices[2].get_x(), _vertices[2].get_y());
	glEnd();
}