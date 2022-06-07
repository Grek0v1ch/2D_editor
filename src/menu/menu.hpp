#ifndef MENU_HPP
#define MENU_HPP

#include "../data_structures/dllist.hpp"

// Переменная отвечает за переопредление текущего окна. Если она равна true - вызывается
// окно консоли с меню. Если она равна false - будет вызвано окно GLUT.
extern bool _MENU_;
extern List<Ishape*> _objects_;
extern Stack<Ishape*> _buff_;

void main_menu();

#endif // MENU_HPP
