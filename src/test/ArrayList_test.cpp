#include "../containers/ArrayList.hpp"
#include <stdexcept>

template class ArrayList<int>;

void test_init_count() {
	ArrayList<int> ali = ArrayList<int>();

	if(ali.size() != 0) {
		throw std::runtime_error("wrong list size. Expected 0, got " + std::to_string(ali.size()));
	}

	return;
}

void test_get_int() {
	ArrayList<int> ali = ArrayList<int>();

	ali.get(0);

	return;
}

auto main() -> int{
	test_init_count();
	test_get_int();

	return 0;
}
