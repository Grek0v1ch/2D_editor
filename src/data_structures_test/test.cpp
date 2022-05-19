#include "test.hpp"

bool test_is_empty() {
	List<int> my_list;
	if (my_list.is_empty() != true) return false;
	my_list.push_back(1);
	if (my_list.is_empty() != false) return false;
	my_list.remove_last();
	if (my_list.is_empty() != true) return false;
	return true;
}

bool test_front() {
	List<int> my_list;
	my_list.push_back(1);
	if (my_list.front()->value() != 1) return false;
	my_list.push_back(2);
	if (my_list.front()->value() != 1) return false;
	return true;
}

bool test_back() {
	List<int> my_list;
	my_list.push_back(1);
	if (my_list.back()->value() != 1) return false;
	my_list.push_back(2);
	if (my_list.back()->value() != 2) return false;
	return true;
}

bool test_remove_first() {
	List<int> my_list;
	my_list.push_back(1);
	my_list.push_back(2);
	my_list.remove_first();
	if (my_list.front()->value() != 2) return false;
	return true;
}

bool test_remove_last() {
	List<int> my_list;
	my_list.push_back(1);
	my_list.push_back(2);
	my_list.remove_last();
	if (my_list.front()->value() != 1) return false;
	return true;
}

bool test_clear_list1() {
	List<int> my_list;
	for (int i = 0; i < 10; i++)
		my_list.push_back(i);
	for (int i = 0; i < 10; i++)
		my_list.remove_last();
	if (my_list.is_empty() != true) return false;

	for (int i = 0; i < 10; i++)
		my_list.push_front(i);
	for (int i = 0; i < 10; i++)
		my_list.remove_first();
	if (my_list.is_empty() != true) return false;
	return true;
}

bool test_clear_list2() {
	List<int> my_list;
	for (int i = 0; i < 10; i++)
		my_list.push_back(i);
	for (int i = 0; i < 10; i++)
		my_list.remove_first();
	if (my_list.is_empty() != true) return false;

	for (int i = 0; i < 10; i++)
		my_list.push_front(i);
	for (int i = 0; i < 10; i++)
		my_list.remove_last();
	if (my_list.is_empty() != true) return false;
	return true;
}

void test_list_print() {
	List<int> my_list;
	std::cout << "Должна напечататься \"елочка\"\n";
	for (int i = 0; i < 10; i++)
		my_list.push_front(i);
	my_list.print();
	for (int i = 0; i < 10; i++) {
		if (i % 2)
			my_list.remove_last();
		else
			my_list.remove_first();
		my_list.print();
	}
}

void run_all_tests_list() {
	bool res = true;
	res = test_is_empty();
	res = test_front();
	res = test_back();
	res = test_remove_first();
	res = test_remove_last();
	res = test_clear_list1();
	res = test_clear_list1();
	res = test_clear_list2();
	test_list_print();
	if (res) 
		std::cout << "All good" << std::endl;
	else
		std::cout << "Not good";
}