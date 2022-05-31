#include "menu.hpp"
#include <iostream>

// Переменная отвечает за переопредление текущего окна. Если она равна true - вызывается
// окно консоли с меню. Если она равна false - будет вызвано окно GLUT.
bool _MENU_ = true;

List<std::unique_ptr<Ishape>> _objects_;

// Функция считываем нажатие клавиши enter пользователем.
void read_enter() {
    // Так как нельзя запретить пользователю нажимать друге клавиши, как метод защиты счтываем
    // все что введет пользователь.
    std::string buff;
    getline(std::cin, buff);
}

std::unique_ptr<Ishape> input_point() {
	double x, y;
	std::cout << "Введите координаты Х и У: ";
	std::cin >> x >> y;
	std::cin.get();
	return std::unique_ptr<Ishape>(new Point(x, y));
}

std::unique_ptr<Ishape> input_segment() {
	double x1, y1, x2, y2;
	std::cout << "Введите координаты точки начала отрезка, Х и У: ";
	std::cin >> x1 >> y1;
	std::cout << "Введите координаты точки конца отрезка, Х и У: ";
	std::cin >> x2 >> y2;
	std::cin.get();
	system("clear");
	return std::unique_ptr<Ishape>(new Segment(Point(x1, y1), Point(x2, y2)));
}

std::unique_ptr<Ishape> input_triangle() {
	double x, y;
	Point vertices[3];
	for (int i = 0; i < 3; i++) {
		std::cout << "Введите координаты вершины " << i + 1 << ", Х и У: ";
		std::cin >> x >> y;
		vertices[i] = Point(x, y);
	}
	std::cin.get();
	return std::unique_ptr<Ishape>(new Triangle(vertices[0], vertices[1], vertices[2]));
}

std::unique_ptr<Ishape> input_quadrangle() {
	double x, y;
	Point vertices[4];
	for (int i = 0; i < 4; i++) {
		std::cout << "Введите координаты вершины " << i + 1 << ", Х и У: ";
		std::cin >> x >> y;
		vertices[i] = Point(x, y);
	}
	std::cin.get();
	return std::unique_ptr<Ishape>(new Quadrangle(vertices[0], vertices[1], 
												  vertices[2], vertices[3]));
}

std::unique_ptr<Ishape> input_ellipse() {
	double x, y;
	double minor_semiaxis, major_semiaxis;
	std::cout << "Введите точку центра эллипса, Х и У: ";
	std::cin >> x >> y;
	std::cout << "Введите малую полуось: ";
	std::cin >> minor_semiaxis;
	std::cout << "Введите большую полуось: ";
	std::cin >> major_semiaxis;
	std::cin.get();
	return std::unique_ptr<Ishape>(new Ellipse(Point(x, y), minor_semiaxis, major_semiaxis));
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

void add_shape_menu() {
    int choice;
    std::unique_ptr<Ishape> object;
    while (true) {
        choice = choise_add_shape_menu();
        switch (choice) {
            case 1:
            	object = input_point();
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
                system("clear");
                return;
            default:
                std::cout << "No such item\nPress enter...";
                read_enter();
                continue;
        }
    }
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
                _MENU_ = false;
                system("clear");
                return;
            default:
                std::cout << "No such item\nPress enter...";
                read_enter();
                continue;
        }
    }
}