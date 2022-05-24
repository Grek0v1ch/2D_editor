#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP

#include <iostream>
#include "../point/point.hpp"

class Ellipse {
private:
    Point _center;
    double _minor_semiaxis, _major_semiaxis;
public:
    // Конструкторы.
    Ellipse();
    // В конструкторе есть баг.
    Ellipse(Point, double, double);
    // Копирования.
    Ellipse(const Ellipse&);

    //Деструктор.
    ~Ellipse() {}

    // Переадресовка операторов.
    Ellipse& operator=(const Ellipse&);
    bool operator==(const Ellipse&);
    friend std::ostream& operator<<(std::ostream&, const Ellipse&);
};

#endif // ELLIPSE_HPP

