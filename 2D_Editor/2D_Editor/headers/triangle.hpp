#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <iostream>
#include "point.hpp"

class Triangle {
private:
	Point _vertices[3];
public:
	// ������������:
	Triangle();
	Triangle(Point, Point, Point);
	// �����������.
	Triangle(const Triangle&);
	
	// ����������.
	~Triangle();

	// ��������������� ����������.
	Triangle& operator=(const Triangle&);
	bool operator==(const Triangle&);
	friend std::ostream& operator<<(std::ostream&, const Triangle&);
};

#endif // TRIANGLE_HPP