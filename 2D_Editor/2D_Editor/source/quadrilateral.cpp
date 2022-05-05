#include "../headers/quadrilateral.hpp"

Quadrilateral::Quadrilateral() {
	for (int i = 0; i < 4; i++)
		_vertices[i] = Point(0, 0);
}

// В конструкторе есть баг: вершины в массиве должны располагаться по часовой стрелке. На данный
// момент они никак не упорядочены. 
Quadrilateral::Quadrilateral(Point point1, Point point2, Point point3, Point point4) {
	_vertices[0] = point1;
	_vertices[1] = point2;
	_vertices[2] = point3;
	_vertices[3] = point4;
}

Quadrilateral::Quadrilateral(const Quadrilateral& object) {
	for (int i = 0; i < 4; i++)
		_vertices[i] = object._vertices[i];
}

Quadrilateral::~Quadrilateral() {
	for (int i = 0; i < 4; i++)
		_vertices[i] = Point(0, 0);
}

// Переопределение оператора присваивания.
Quadrilateral& Quadrilateral::operator=(const Quadrilateral& object) {
	if (&object == this) return *this;
	for (int i = 0; i < 4; i++)
		_vertices[i] = object._vertices[i];
	return *this;
}

// Переопределение оператора сравнения (оператор проверяет идентичность двух объектов).
bool Quadrilateral::operator==(const Quadrilateral& object) {
	for (int i = 0; i < 4; i++) {
		bool flag = false;
		for (int j = 0; j < 4; j++)
			if (_vertices[i] == object._vertices[j]) flag = true;
		if (!flag) return false;
	}
	return true;
}

// Переопределение оператора вывода (временно, возможно придется переделать как метод класса).
std::ostream& operator<<(std::ostream& fout, const Quadrilateral& object) {
	fout << "Quadrilateral, vertices: " << '\n';
	for (int i = 0; i < 4; i++)
		fout << object._vertices[i];
	return fout;
}