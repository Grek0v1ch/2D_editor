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

// Переменная отвечает за переопредление текущего окна. Если она равна true - вызывается
// окно консоли с меню. Если она равна false - будет вызвано окно GLUT.
bool MENU = true;

List<std::unique_ptr<Ishape>> object;

// Функция считываем нажатие клавиши enter пользователем.
void read_enter() {
    // Так как нельзя запретить пользователю нажимать друге клавиши, как метод защиты счтываем
    // все что введет пользователь.
    std::string buff;
    getline(std::cin, buff);
}

int choise_add_shape_menu() {
    int choice;
    system("clear");
    std::cout << "Add Shape Menu\n"
              << "1 - Add Point\n"
              << "2 - Add Segment\n"
              << "3 - Add Triangle\n"
              << "4 - Add Quadrangle\n"
              << "5 - Add Ellipse\n"
              << "6 - Quit\n"
              << "Please choose: ";
    std::cin >> choice;
    // Убираем мусор из потока.
    std::cin.get();
    return choice;
}

void add_shape_menu() {
    int choice;
    while (true) {
        choice = choise_add_shape_menu();
        switch (choice) {
            case 1:
                std::cout << "Add Point\n";
                std::cout << "Press enter...";
                read_enter();
                break;
            case 2:
                std::cout << "Add Point\n";
                std::cout << "Press enter...";
                read_enter();
                break;
            case 3:
                std::cout << "Add Point\n";
                std::cout << "Press enter...";
                read_enter();
                break;
            case 4:
                std::cout << "Add Point\n";
                std::cout << "Press enter...";
                read_enter();
                break;
            case 5:
                std::cout << "Add Point\n";
                std::cout << "Press enter...";
                read_enter();
                break;
            case 6:
                MENU = false;
                system("clear");
                return;
            default:
                std::cout << "No such item\nPress enter...";
                read_enter();
                continue;
        }
    }
}

// Вывод пунктов второго меню и выбор пункта.
int choise_main_menu() {
    int choice;
    system("clear");
    std::cout << "Main Menu\n"
              << "1 - Add item\n"
              << "2 - Delete item\n"
              << "3 - Quit\n"
              << "Please choose: ";
    std::cin >> choice;
    // Убираем мусор из потока.
    std::cin.get();
    return choice;
}

void main_menu() {
    int choice;
    while (true) {
        choice = choise_main_menu();
        switch (choice) {
            case 1:
                add_shape_menu();
                break;
            case 2:
                std::cout << "Delete item\n";
                std::cout << "Press enter...";
                read_enter();
                break;
            case 3:
                MENU = false;
                system("clear");
                return;
            default:
                std::cout << "No such item\nPress enter...";
                read_enter();
                continue;
        }
    }
}


void Display(void) {
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3ub(255, 0, 0);

    if (MENU) main_menu();

    glFinish();
}

// Эта функция перерисовывает картинку через опеределенный интервал времени (в этой программе 33
// милисекунды). В ней просто дублируется часть функции Display, отвечающей за отрисовку.
void TimerMove(int value) {
    if (MENU) main_menu();

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

    if (key == ESCAPE) exit(0);
    if (key == 109) MENU = true;
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