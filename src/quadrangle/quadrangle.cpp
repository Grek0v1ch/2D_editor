#include "quadrangle.hpp"

// Конструкторы.
Quadrangle::Quadrangle() : _vertices{Point(0, 0), Point(0, 0), Point(0, 0), Point(0, 0)} {}

// !!!Note!!! В конструкторе есть баг: вершины в массиве должны располагаться по часовой стрелке. На данный
// момент они никак не упорядочены. 
Quadrangle::Quadrangle(Point point1, Point point2, Point point3, Point point4) : _vertices{point1, point2, point3, point4} {
	if (point1 == point2 || point1 == point3 || point1 == point4 ||
		point2 == point3 || point2 == point4 || point3 == point4) throw 1;
}

// Копирования.
Quadrangle::Quadrangle(const Quadrangle& object) {
	for (int i = 0; i < 4; i++)
		_vertices[i] = object._vertices[i];
}

// Переопределение оператора присваивания.
Quadrangle& Quadrangle::operator=(const Quadrangle& object) {
	if (&object == this) return *this;
	for (int i = 0; i < 4; i++)
		_vertices[i] = object._vertices[i];
	return *this;
}

// Переопределение оператора сравнения (оператор проверяет идентичность двух объектов).
bool Quadrangle::operator==(const Quadrangle& object) {
	for (int i = 0; i < 4; i++) {
		bool flag = false;
		for (int j = 0; j < 4; j++)
			if (_vertices[i] == object._vertices[j]) flag = true;
		if (!flag) return false;
	}
	return true;
}

// Переопределение оператора вывода (временно, возможно придется переделать как метод класса).
std::ostream& operator<<(std::ostream& fout, const Quadrangle& object) {
	fout << "Quadrangle, vertices: " << '\n';
	for (int i = 0; i < 4; i++)
		fout << object._vertices[i];
	return fout;
}

// Метод рисования четырёхугольника.
void Quadrangle::draw() {
	glLineWidth(3);
	glBegin(GL_LINE_LOOP);
		glVertex2f(_vertices[0].get_x(), _vertices[0].get_y());
		glVertex2f(_vertices[1].get_x(), _vertices[1].get_y());
		glVertex2f(_vertices[2].get_x(), _vertices[2].get_y());
		glVertex2f(_vertices[3].get_x(), _vertices[3].get_y());
	glEnd();
}