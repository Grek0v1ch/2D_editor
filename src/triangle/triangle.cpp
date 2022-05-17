#include "triangle.hpp"

// Конструкторы:
Triangle::Triangle() {
	for (int i = 0; i < 3; i++)
		_vertices[i] = Point(0, 0);
}
Triangle::Triangle(Point point1, Point point2, Point point3) {
		_vertices[0] = point1;
		_vertices[1] = point2;
		_vertices[2] = point3;
}
// Копирования.
Triangle::Triangle(const Triangle& object) {
	for (int i = 0; i < 3; i++)
		_vertices[i] = object._vertices[i];
}
// Деструктор.
Triangle::~Triangle() {
	for (int i = 0; i < 3; i++)
		_vertices[i] = Point(0, 0);
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