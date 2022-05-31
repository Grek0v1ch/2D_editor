#ifndef MENU_HPP
#define MENU_HPP

#include "../point/point.hpp"
#include "../segment/segment.hpp"
#include "../triangle/triangle.hpp"
#include "../quadrangle/quadrangle.hpp"
#include "../ellipse/ellipse.hpp"
#include "../data_structures/dllist.hpp"

// Переменная отвечает за переопредление текущего окна. Если она равна true - вызывается
// окно консоли с меню. Если она равна false - будет вызвано окно GLUT.
extern bool _MENU_;
extern List<Ishape*> _objects_;

void main_menu();

#endif // MENU_HPP
