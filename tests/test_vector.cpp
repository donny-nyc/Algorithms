#include "../containers/vector.cpp"

#include <stdexcept>
#include <iostream>

using namespace std;

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

void testPushFront() {
	Vector<int> v = Vector<int>(1);

	v.push_front(99);

	if (v.get(0) != 99) {
		throw std::runtime_error("expected 99, got " + to_string(v.front()));
	}

	return;
}

void testFront() {
	Vector<int> v = Vector<int>(1);

	v.push_front(99);

	if (v.front() != 99) {
		throw std::runtime_error("expected 99, got " + to_string(v.front()));
	}

	return;
}

void testPushFrontMulti() {
	Vector<int> v = Vector<int>(1);

	v.push_front(0);
	v.push_front(1);
	v.push_front(2);

	for(int i = 0; i < 3; i++) {
		if (v.get(i) != 2 - i) {
			throw std::runtime_error("expected " + to_string(i) + "got " + to_string(v.get(i)));
		}
	}

	return;
}

void testInsertGetElement() {
	Vector<int> v = Vector<int>(3);

	v.push_end(5);

	if(v.get(0) != 5) {
		throw std::runtime_error("expected 5, got " + to_string(v.get(0)));
	}

	return;
}

int main() {
	testEmpty();
	testPushFront();
	testPushFrontMulti();
	testFront();
	testInsertGetElement();
}
