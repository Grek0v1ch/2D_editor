#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP

#include <iostream>
#include "point.hpp"

class Ellipse {
private:
    Point _center;
    double _minor_semiaxis, _major_semiaxis;
public:
    Ellipse();
    // В конструкторе есть баг.
    Ellipse(Point, double, double);
    Ellipse(const Ellipse&);

    ~Ellipse();

    // Переадресовка операторов.
    Ellipse& operator=(const Ellipse&);
    bool operator==(const Ellipse&);
    friend std::ostream& operator<<(std::ostream&, const Ellipse&);
};

#endif // ELLIPSE_HPP

