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

// Медиана из вершины A на сторону BC
Segment Triangle::medianA(){
	// Противоположная сторона треугольника, к которой ищем медиану
	Segment opposite_side(_vertices[1], _vertices[2]);
	// Медиана
	Segment median(_vertices[0], opposite_side.div_in_ratio(1.0, 1.0));
	return median;
}

// Медиана из вершины B на сторону AC
Segment Triangle::medianB(){
	// Противоположная сторона треугольника, к которой ищем медиану
	Segment opposite_side(_vertices[0], _vertices[2]);
	// Медиана
	Segment median(_vertices[1], opposite_side.div_in_ratio(1.0, 1.0));
	return median;
}

// Медиана из вершины C на сторону AB
Segment Triangle::medianC(){
	// Противоположная сторона треугольника, к которой ищем медиану
	Segment opposite_side(_vertices[0], _vertices[1]);
	// Медиана
	Segment median(_vertices[2], opposite_side.div_in_ratio(1.0, 1.0));
	return median;
}