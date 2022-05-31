#include <iostream>
#include "point/point.hpp"
#include "segment/segment.hpp"
#include "triangle/triangle.hpp"
#include "quadrangle/quadrangle.hpp"
#include "ellipse/ellipse.hpp"
#include "data_structures/dllist.hpp"

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

void Display(void) {
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3ub(255, 0, 0);

    glFinish();
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

    if (key == ESCAPE) exit(0);
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
    glutMainLoop();
}