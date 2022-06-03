#include "data_check.hpp"

// ������� ��������� ������������ ��������� �������� ��� �������������� ��������.
void check_value(double& num) {
	std::cin >> num;
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		std::cout << "Enter a rational number\n";
		std::cin >> num;
	}
}

// ������� ��������� ������������ ��������� �������.
void input_menu_command(int& command) {
	std::cin >> command;
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		std::cout << "Enter the correct command number\n";
		std::cin >> command;
	}
}
