#include "../containers/vector.cpp"
#include "../strategies/insert_sort.cpp"

#include <stdexcept>
#include <iostream>

using namespace std;

void testBasic() {
	Vector<int> vector = Vector<int>();

	vector.push_end(5);
	vector.push_end(4);
	vector.push_end(3);

	InsertSort<int> s = InsertSort<int>();

	Vector<int>* sorted = (Vector<int>*)s.sort(&vector);

	if(sorted->get(0) != 3) {
		throw std::runtime_error("expected 3, got " + to_string(sorted->get(0)));
	} else if (sorted->get(1) != 4) {
		throw std::runtime_error("expected 4, got " + to_string(sorted->get(1)));
	} else if(sorted->get(2) != 5) {
		throw std::runtime_error("expected 5, got " + to_string(sorted->get(2)));
	}

	return;
}

void testComplex() {
	Vector<int> vector = Vector<int>(200);

	for(int i = -100; i < 100; i++) {
		vector.push_end(i);
	}

	InsertSort<int> s = InsertSort<int>();

	Vector<int>* sorted = (Vector<int>*)s.sort(&vector);

	for(int i = 0; i < 200; i++) {
		if (sorted->get(i) != i - 100) {
			throw std::runtime_error("expected " + to_string(i) + "got " + to_string(i - 100));
		}
	}

	return;

}

void testNegatives() {
	Vector<int> vector = Vector<int>(10);

	for(int i = -10; i < 0; i++) {
		vector.push_end(i);
	}

	InsertSort<int> s = InsertSort<int>();

	Vector<int>* sorted = (Vector<int>*)s.sort(&vector);

	for (int i = 0; i < 10; i++) {
		if (sorted->get(i) != i - 10) {
			throw std::runtime_error("expected " + to_string(i) + "got " +to_string(i - 10));
		}
	}

	return;
}

void testEmpty() {
	try {
		Vector<int> vector = Vector<int>(0);
	} catch (std::invalid_argument& ex) {
		return;
	}

	throw std::runtime_error("should have thrown error - size is zero");

	return;
}

void testNegativeSizeConstructor() {
	try {
		Vector<int>(-5);
	} catch (std::invalid_argument& ex) {
		return;
	}

	return;
}

void testBasicDouble() {
	Vector<double> vector = Vector<double>(10);
	for(double i = 1.0; i > 0; i = i - 0.1) {
		vector.push_end(i);
	}

	InsertSort<double> s = InsertSort<double>();

	Vector<double>* sorted = (Vector<double>*)s.sort(&vector);

	for(int i = 0; i < 10; i++) {
		// must be careful with floating point comparisons
		// we're probably not going to get the exact value
		// we'd expect, but we can still confirm that the 
		// returned value falls within an expected range
		if(sorted->get(i) >= 0.1 * i + 0.1 || sorted->get(i) < 0.1 * i) {
			throw std::runtime_error("expected " + to_string(0.1 * i) + " got " + to_string(sorted->get(i)));
		}
	}
}

void testHugeSort() {
	//List<int> list = List<int>(1000000); // 10^6 - I tried, gave up after waiting a few minutes
	Vector<int> vector = Vector<int>(10000);

	for(int i = 10000; i > 0; i--) {
		vector.push_end(i);
	}

	InsertSort<int> s = InsertSort<int>();

	Vector<int>* sorted = (Vector<int>*)s.sort(&vector);

	for(int i = 0; i < 10000; i++) {
		if (sorted->get(i) !=  i + 1) {
			throw std::runtime_error("expected " + to_string(i) + "got " + to_string(sorted->get(i)));
		}
	}
}

int main(int argc, char** argv) {
	testBasic();
	testComplex();
	testNegatives();
	testEmpty();
	testNegativeSizeConstructor();
	testBasicDouble();
	testHugeSort();
}
