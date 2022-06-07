#ifndef QUADRILATERAL_HPP
#define QUADRILATERAL_HPP

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
	#include "../../build/glut-3.7.6-bin/glut.h"
#endif

#include "../Ishape.hpp"
#include "../point/point.hpp"

class Quadrangle : public Ishape {
private:
	Point _vertices[4];
public:
	// Конструкторы.
	Quadrangle();
	// В конструкторе есть баг.
	Quadrangle(Point, Point, Point, Point);
	// Копирования.
	Quadrangle(const Quadrangle&);

	// Деструктор.
	~Quadrangle() {}

	// Переадресовка операторов.
	Quadrangle& operator=(const Quadrangle&);
	bool operator==(const Quadrangle&);
	friend std::ostream& operator<<(std::ostream&, const Quadrangle&);

	// Метод возвращает тип объекта.
	std::string type() const override { return "quadrangle"; };

	void zoom(const double koef) override { _vertices[0].zoom(koef), _vertices[1].zoom(koef),
											_vertices[2].zoom(koef), _vertices[3].zoom(koef); }

	// Метод рисования черырёхугольника.
	void draw() override;
};

#endif // QUADRILATERAL_HPP
