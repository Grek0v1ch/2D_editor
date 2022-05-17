#include "ellipse.hpp"

// Конструктор
Ellipse::Ellipse(){
	_center = Point(0, 0);
	_minor_semiaxis = 0;
	_major_semiaxis = 0;
}

// Конструктор по всем полям класса
Ellipse::Ellipse(Point center, double minor_semiaxis, double major_semiaxis){
	_center = center;
	_minor_semiaxis = minor_semiaxis;
	_major_semiaxis = major_semiaxis;
}

// Конструктор копирования
Ellipse::Ellipse(const Ellipse& object){
	_center = object._center;
	_minor_semiaxis = object._minor_semiaxis;
	_major_semiaxis = object._major_semiaxis;
}

// Деструктор
Ellipse::~Ellipse(){
	_center = Point(0, 0);
	_minor_semiaxis = 0;
	_major_semiaxis = 0;
}

// Переопределение оператора сравнения (оператор проверяет идентичность двух объектов класса).
bool Ellipse::operator==(const Ellipse& object) {
	if (_center == object._center && _minor_semiaxis == object._minor_semiaxis && _minor_semiaxis == object._minor_semiaxis) return true;
	return false;
}

// Переопределение оператора вывода (временно, может понадобится переделать как метод класса).
std::ostream& operator<<(std::ostream& fout, const Ellipse& object) {
	fout << "Ellipse, center:\n" << object._center << "minor semiaxis = " 
	<< object._minor_semiaxis << '\n' << "major semiaxis = " << object._minor_semiaxis << '\n';
	return fout;
}

// Переопределение оператора присваивания.
Ellipse& Ellipse::operator=(const Ellipse& object) {
	if (&object == this) return *this;
	_center = object._center;
	_minor_semiaxis = object._minor_semiaxis;
	_major_semiaxis = object._major_semiaxis;
	return *this;
}