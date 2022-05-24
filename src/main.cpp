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
/* размер куба */
const int CubeSize = 200;
/* эта функция управляет всем выводом на экран */
void Display(void) {
    int left, right, top, bottom;
    left = (Width - CubeSize) / 2;
    right = left + CubeSize;
    bottom = (Height - CubeSize) / 2;
    top = bottom + CubeSize;
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3ub(255, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(left, bottom);
    glVertex2f(left, top);
    glVertex2f(right, top);
    glVertex2f(right, bottom);
    glEnd();
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
    glOrtho(0, w, 0, h, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

/* Функция обрабатывает сообщения от клавиатуры */
void Keyboard(unsigned char key, int x, int y) {
#define ESCAPE '\033'

    if (key == ESCAPE)
        exit(0);
}

/* Главный цикл приложения */
int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(Width, Height);
    glutCreateWindow("Red square example");
    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutKeyboardFunc(Keyboard);
    glutMainLoop();
}