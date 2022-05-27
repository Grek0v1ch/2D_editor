#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <iostream>

#ifdef __APPLE__
    #define GL_SILENCE_DEPRECATION
    #include <OpenGL/gl.h>
    #include <GLUT/glut.h>
#endif
#ifdef __linux__
    #include <GL/glut.h>
#endif
#ifdef _WIN32
    #include "../build/glut-3.7.6-bin/glut.h"
#endif

#include "../Ishape.hpp"
#include "../point/point.hpp"

class Triangle : public Ishape{
private:
	Point _vertices[3];
public:
	// Конструкторы:
	Triangle();
	Triangle(Point, Point, Point);
	// Копирования.
	Triangle(const Triangle&);
	
	// Деструктор.
	~Triangle() {};

	// Переопределение операторов.
	Triangle& operator=(const Triangle&);
	bool operator==(const Triangle&);
	friend std::ostream& operator<<(std::ostream&, const Triangle&);

	// Методе рисования треугольника.
	void draw() override;	
};

#endif // TRIANGLE_HPP