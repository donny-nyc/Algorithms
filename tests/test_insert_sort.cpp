#include "../containers/list.cpp"
#include "../strategies/insert_sort.cpp"

#include <stdexcept>
#include <iostream>

using namespace std;

void testBasic() {
	List<int> list = List<int>();

	list.push_end(5);
	list.push_end(4);
	list.push_end(3);

	InsertSort<int> s = InsertSort<int>();

	List<int>* sorted = (List<int>*)s.sort(&list);

	if(sorted->get(0) != 3) {
		throw std::runtime_error("expected 3, got " + sorted->get(0));
	} else if (sorted->get(1) != 4) {
		throw std::runtime_error("expected 4, got " + sorted->get(1));
	} else if(sorted->get(2) != 5) {
		throw std::runtime_error("expected 5, got " + sorted->get(2));
	}

	return;
}

void testComplex() {
	List<int> list = List<int>(200);

	for(int i = -100; i < 100; i++) {
		list.push_end(i);
	}

	InsertSort<int> s = InsertSort<int>();

	List<int>* sorted = (List<int>*)s.sort(&list);

	for(int i = 0; i < 200; i++) {
		if (sorted->get(i) != i - 100) {
			throw std::runtime_error("expected " + to_string(i) + "got " + to_string(i - 100));
		}
	}

	return;

}

void testNegatives() {
	List<int> list = List<int>(10);

	for(int i = -10; i < 0; i++) {
		list.push_end(i);
	}

	InsertSort<int> s = InsertSort<int>();

	List<int>* sorted = (List<int>*)s.sort(&list);

	for (int i = 0; i < 10; i++) {
		if (sorted->get(i) != i - 10) {
			throw std::runtime_error("expected " + to_string(i) + "got " +to_string(i - 10));
		}
	}

	return;
}

void testEmpty() {
	try {
		List<int> list = List<int>(0);
	} catch (std::invalid_argument& ex) {
		return;
	}

	throw std::runtime_error("should have thrown error - size is zero");

	return;
}

void testNegativeSizeConstructor() {
	try {
		List<int>(-5);
	} catch (std::invalid_argument& ex) {
		return;
	}

	return;
}

int main(int argc, char** argv) {
	testBasic();
	testComplex();
	testNegatives();
	testEmpty();
	testNegativeSizeConstructor();
}
