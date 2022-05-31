#include <iostream>
#include "point/point.hpp"
#include "segment/segment.hpp"
#include "triangle/triangle.hpp"
#include "quadrangle/quadrangle.hpp"
#include "ellipse/ellipse.hpp"
#include "data_structures/dllist.hpp"
#include "menu/menu.hpp"

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

/* начальная ширина и высота окна */
GLint Width = 512, Height = 512;

void draw_objects() {
    auto iter = _objects_.front();
    while (iter) {
        iter->value()->draw();
        iter = iter->next();
    }
}

void clear_objects() {
    auto iter = _objects_.front();
    while (iter) {
        auto temp = iter->next();
        delete iter->value();
        iter = temp;
    }
}

void Display(void) {
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3ub(255, 0, 0);

    if (_MENU_) main_menu();
    draw_objects();

    glFinish();
}

// Эта функция перерисовывает картинку через опеределенный интервал времени (в этой программе 33
// милисекунды). В ней просто дублируется часть функции Display, отвечающей за отрисовку.
void TimerMove(int value) {
    if (_MENU_) main_menu();

    glutPostRedisplay(); 
    glutTimerFunc(33, TimerMove, 1);
}

/* Функция вызывается при изменении размеров окна */
void Reshape(GLint w, GLint h) {
    Width = w;
    Height = h;
    /* устанавливаем размеры области отображения */
    glViewport(0, 0, w, h);

    /* ортографическая проекция */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Команда устанавливает центр координат в центре отоброжаемого окна. Также масштаб координат
    // теперь приравнивается к масштабу пикселей.
    gluOrtho2D(-w / 2, w / 2, -h / 2, h / 2);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

/* Функция обрабатывает сообщения от клавиатуры */
void Keyboard(unsigned char key, int x, int y) {
    #define ESCAPE '\033'

    if (key == ESCAPE) {
        clear_objects();
        exit(0);
    }
    if (key == 109) _MENU_ = true;
    if (key == 122) {
        if (_objects_.is_empty()) return;
        auto item = _objects_.back();
        delete item->value();
        _objects_.remove_last();
    }
}

/* Главный цикл приложения */
int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(Width, Height);
    glutCreateWindow("2D editor");
    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutKeyboardFunc(Keyboard);
    glutTimerFunc(33, TimerMove, 1);
    glutMainLoop();
}