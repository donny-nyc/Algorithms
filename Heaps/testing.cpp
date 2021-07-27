#include <iostream>
#include <functional>
#include "testing.hpp"
#include "heap.hpp"

using namespace std;

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

int test() {
	cout << "__testing__" << endl;
	Heap h = Heap(5);		

	run("ParentCalculatedCorrectly", [&h](){
		for(int i = 0; i <= 2; i ++) {
			auto actual = h.parent(i);
			if(!expect(actual, 0, equals)) {
				return 1;
			}
		}

		for (int i = 3; i <= 4; i++) {
			auto actual = h.parent(i);
			if(!expect(actual, 1, equals)) {
				return 1;
			}
		}

		return 0;
	});

	run("LeftCalculateCorrectly", [&h](){
		auto actual = h.left(0);
		if (actual != 1) {
			message = "expected left(0) to equal 1, got " + to_string(actual);
		}

		actual = h.left(1);
		if (actual != 3) {
			message = "expected left(1) to equal 3, got " + to_string(actual);
		}

		return 0;
	});


	cout << "__done testing __" << endl;

	return 0;
}
