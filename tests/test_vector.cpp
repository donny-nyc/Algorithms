#include "../containers/vector.cpp"

#include <stdexcept>
#include <iostream>

void testEmpty() {
	Vector<int> v = Vector<int>(3);

	try {
		v.get(0);
	} catch (std::range_error& ex) {
		return;
	}

	throw std::runtime_error("should have thrown a range error");

	return;
}

int main() {
	testEmpty();
}
