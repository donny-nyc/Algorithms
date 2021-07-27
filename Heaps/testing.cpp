#include <iostream>
#include <functional>
#include "testing.hpp"
#include "heap.hpp"

using namespace std;

#define FAIL 1
#define PASS 0

string testCase;
string message;

void fail(string msg) {
	cout << "[" << testCase << "] fail";

	if (msg.length() > 0) {
		cout << ": " << msg;
	}

	cout << endl;
}

bool equals(int a, int b) {
	if (a != b) {
		message = to_string(a) + " does not equal " + to_string(b);
		return false;
	}

	return true;
}

bool not_equals(int a, int b) {
	if (a == b) {
		message = to_string(a) + " equals " + to_string(b);
		return false;
	}

	return true;
}

bool expect(int a, int b, function<bool(int, int)> test) {
	bool result  = test(a, b);
	if (!result) {
		cout << "fail - " << message << endl;
	}

	return true;
}

int run(string caseName, function<int()> func) {
	testCase = caseName;
	
	cout << testCase << ": ";

	int result = func();

	if (result != 0) { // fail
		return 1;
	}

	cout << "pass" << endl;
	return 0;
}

#define HEAP_SIZE 5
int test() {
	cout << "__testing__" << endl;
	Heap h = Heap(HEAP_SIZE);		

	run("ParentCalculatedCorrectly", [&h](){
		for(int i = 1; i <= 2; i ++) {
			auto actual = h.parent(i);
			if(!expect(actual, 0, equals)) {
				return FAIL;
			}
		}

		for (int i = 3; i <= 4; i++) {
			auto actual = h.parent(i);
			if(!expect(actual, 1, equals)) {
				return FAIL;
			}
		}

		if(!expect(h.parent(HEAP_SIZE), -1, equals)) {
			return FAIL;
		}

		if(!expect(h.parent(-1), -1, equals)) {
			return FAIL;
		}

		return 0;
	});

	run("LeftCalculateCorrectly", [&h](){
		auto actual = h.left(0);
		if (!expect(actual, 1, equals)) {
			return FAIL;
		}

		actual = h.left(1);
		if (!expect(actual, 3, equals)) {
			return FAIL;
		}

		if (!expect(h.left(-1), -1, equals)) {
			return FAIL;
		}

		if (!expect(h.left(HEAP_SIZE), -1, equals)) {
			return FAIL;
		}

		return PASS;
	});

	run("RightCalculateCorrectly", [&h](){
		if(!expect(h.right(0), 2, equals)) {
			return FAIL;
		}

		if(!expect(h.right(-1), -1, equals)) {
			return FAIL;
		}

		if(!expect(h.right(1), 4, equals)) {
			return FAIL;
		}

		if (!expect(h.right(HEAP_SIZE), -1, equals)) {
			return FAIL;
		}

		return PASS;
	});

	run("SetElementWorksAsExpected", [&h](){
		h.set(1, 999);

		if(!expect(h.get(1), 999, equals)) {
			return FAIL;
		}

		if(!expect(h.set(-5, 999), -1, equals)) {
			return FAIL;
		}

		if(!expect(h.set(5, 999), -1, equals)) {
			return FAIL;
		}

		return PASS;
	});

	run("MinimalMaxHeapify", [](){
		Heap h = Heap(3);	

		for(int i = 0; i < 3; i++) {
			h.set(i, i);
		}

		max_heapify(h, 0);

		if(!expect(h.get(0), 2, equals)) {
			return FAIL;
		}

	  return PASS;
	});

	run("ComplicatedMaxHeapify", [](){
		Heap h = Heap(7);

		for(int i = 0; i < h.getMax(); i++) {
			h.set(i, h.getMax() - i - 1);
		}

		h.set(0, 0);

		max_heapify(h, 0);

		if(!expect(h.get(0), 5, equals)) {
			return FAIL;
		}

		// min value would have followed the
		// path of 'largest' down to idx: 3
		if(!expect(h.get(3), 0, equals)) {
			return FAIL;
		}

		return PASS;
	});


	cout << "__done testing __" << endl;

	return 0;
}
