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

bool test_remove_firs() {
	List<int> my_list;
	my_list.push_back(1);
	my_list.push_back(2);
	my_list.remove_first();
	if (my_list.front()->value() != 2) return false;
	return true;
}