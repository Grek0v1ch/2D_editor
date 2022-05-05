#include "../headers/triangle.hpp"

// ������������:
Triangle::Triangle() {
	for (int i = 0; i < 3; i++)
		_vertices[i] = Point(0, 0);
}
Triangle::Triangle(Point point1, Point point2, Point point3) {
		_vertices[0] = point1;
		_vertices[1] = point2;
		_vertices[2] = point3;
}
// �����������.
Triangle::Triangle(const Triangle& object) {
	for (int i = 0; i < 3; i++)
		_vertices[i] = object._vertices[i];
}
// ����������.
Triangle::~Triangle() {
	for (int i = 0; i < 3; i++)
		_vertices[i] = Point(0, 0);
}
// ��������������� ��������� ������������.
Triangle& Triangle::operator=(const Triangle& value) {
	if (&value == this) return *this;
	for (int i = 0; i < 3; i++)
		_vertices[i] = value._vertices[i];
	return *this;
}
// ��������������� ��������� ��������� (�������� ��������� ������������ ���� �������� ������).
bool Triangle::operator==(const Triangle& object) {
	for (int i = 0; i < 3; i++)
		if (!(_vertices[i] == object._vertices[i])) return false;
	return true;
}
// ��������������� ��������� ������.
std::ostream& operator<<(std::ostream& fout, const Triangle& object) {
	fout << "Triangle, vertices: " << '\n' << object._vertices[0] << object._vertices[1] << object._vertices[2] << '\n';
	return fout;
}