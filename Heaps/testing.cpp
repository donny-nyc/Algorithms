#include "testing.hpp"
#include "heap.hpp"
#include <functional>
#include <iostream>

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

bool gt(int a, int b) {
  if (a <= b) {
    message = to_string(a) + " is not greater than " + to_string(b);
    return false;
  }

  return true;
}

bool gte(int a, int b) {
  if (a < b) {
    message = to_string(a) + " is not greater than or equal to " + to_string(b);
    return false;
  }

  return true;
}

bool lt(int a, int b) {
  if (a >= b) {
    message = to_string(a) + " is not less than " + to_string(b);
    return false;
  }

  return true;
}

bool lte(int a, int b) {
  if (a > b) {
    message = to_string(a) + " is not less than or equal to " + to_string(b);
    return false;
  }

  return true;
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
  bool result = test(a, b);
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

  run("ParentCalculatedCorrectly", [&h]() {
    for (int i = 1; i <= 2; i++) {
      auto actual = h.parent(i);
      if (!expect(actual, 0, equals)) {
        return FAIL;
      }
    }

    for (int i = 3; i <= 4; i++) {
      auto actual = h.parent(i);
      if (!expect(actual, 1, equals)) {
        return FAIL;
      }
    }

    if (!expect(h.parent(HEAP_SIZE), -1, equals)) {
      return FAIL;
    }

    if (!expect(h.parent(-1), -1, equals)) {
      return FAIL;
    }

    return 0;
  });

  run("LeftCalculateCorrectly", [&h]() {
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

  run("RightCalculateCorrectly", [&h]() {
    if (!expect(h.right(0), 2, equals)) {
      return FAIL;
    }

    if (!expect(h.right(-1), -1, equals)) {
      return FAIL;
    }

    if (!expect(h.right(1), 4, equals)) {
      return FAIL;
    }

    if (!expect(h.right(HEAP_SIZE), -1, equals)) {
      return FAIL;
    }

    return PASS;
  });

  run("SetElementWorksAsExpected", [&h]() {
    h.set(1, 999);

    if (!expect(h.get(1), 999, equals)) {
      return FAIL;
    }

    if (!expect(h.set(-5, 999), -1, equals)) {
      return FAIL;
    }

    if (!expect(h.set(5, 999), -1, equals)) {
      return FAIL;
    }

    return PASS;
  });

  run("MinimalMaxHeapify", []() {
    Heap *h = new Heap(3);

    for (int i = 0; i < 3; i++) {
      h->set(i, i);
    }

    max_heapify(h, 0);

    if (!expect(h->get(0), 2, equals)) {
      return FAIL;
    }

    return PASS;
  });

  run("ComplicatedMaxHeapify", []() {
    Heap *h = new Heap(7);

    for (int i = 0; i < h->getMax(); i++) {
      h->set(i, h->getMax() - i - 1);
    }

    h->set(0, 0);

    max_heapify(h, 0);

    if (!expect(h->get(0), 5, equals)) {
      return FAIL;
    }

    // min value would have followed the
    // path of 'largest' down to idx: 3
    if (!expect(h->get(3), 0, equals)) {
      return FAIL;
    }

    return PASS;
  });

  run("BuildMaxHeap", []() {
    Heap *heap = new Heap(5);
    for (int i = 0; i < 5; i++) {
      heap->set(i, i);
    }

    build_max_heap(heap);

    for (int i = 0; i < 5; i++) {
      cout << heap->get(i) << ", ";
    }

    if (!expect(heap->get(0), 4, equals)) {
      return FAIL;
    }

    return PASS;
  });

  run("BuildSmallMaxHeap", []() {
    Heap *heap = new Heap(1);

    heap->set(0, 9);

    build_max_heap(heap);

    if (!expect(heap->get(0), 9, equals)) {
      return FAIL;
    }

    return PASS;
  });

  run("BuildEmptyMaxHeap", []() {
    Heap *heap = new Heap(0);

    build_max_heap(heap);

    if (!expect(heap->getMax(), 0, equals)) {
      return FAIL;
    }

    if (!expect(heap->get(0), -1, equals)) {
      return FAIL;
    }

    return PASS;
  });

  run("BuildHugeMaxHeap", []() {
    int heap_size = 900000;
    Heap *heap = new Heap(heap_size);

    for (int i = 0; i < heap_size; i++) {
      heap->set(i, heap_size - i);
    }

    build_max_heap(heap);

    for (int i = 1; i < heap_size; i++) {
      if (!expect(heap->get(i - 1), heap->get(i), gt)) {
        return FAIL;
      }
    }

    if (!expect(heap->get(0), heap_size, equals)) {
      return FAIL;
    }

    return PASS;
  });

  run("SmallMinHeapify", []() {
    Heap *heap = new Heap(3);
    heap->set(0, 2);
    heap->set(1, 1);
    heap->set(2, 0);

    min_heapify(heap, 0);

    if (!expect(heap->get(0), 0, equals)) {
      return FAIL;
    }

    if (!expect(heap->get(2), 2, equals)) {
      return FAIL;
    }

    return PASS;
  });

	run("BuildSmallMinHeap", []() {
		Heap *heap = new Heap(3);
		heap->set(0, 2);
		heap->set(1, 1);
		heap->set(2, 0);

		build_min_heap(heap);

		if (!expect(heap->get(0), 0, equals)) {
			return FAIL;
		}

		if (!expect(heap->get(2), 2, equals)) {
			return FAIL;
		}

		return PASS;
	});

	run("BuildBiggerMinHeap", []() {
		// blows up above 10,000
		for (int x = 4; x < 10000; x++) {
			int heapSize = x;
			Heap *heap = new Heap(heapSize);

			for(int i = 0; i < heapSize; i++) {
				heap->set(i, heapSize - i);
			}

			build_min_heap(heap);

			if (!expect(heap->get(0), 1, equals)) {
				for (int j = 0; j < heapSize; j++) {
					cout << heap->get(j) << ", ";
				}

				return FAIL;
			}
		}
		return PASS;
	});

	run("ReportsCorrectSize", []() {
		Heap *heap = new Heap(4);

		if (!expect(heap->getSize(), 0, equals)) {
			return FAIL;
		}

		heap->set(0, 0);

		if (!expect(heap->getSize(), 1, equals)) {
			return FAIL;
		}

		return PASS;
	});

	run("Heapsort", []() {
		int heap_size = 4;
		Heap *heap = new Heap(heap_size);

		for(int i = 0; i < heap_size; i++) {
			heap->set(i, i);	
		}

		int* res = heapsort(heap);

		for (int j = 0; j < heap_size; j++) {
			cout << res[j] << ", ";
		}

		return PASS;
	});

	/*
	run("BuildMassiveMinHeap", []() {
		int heap_size = 1000000;
		Heap* heap = new Heap(heap_size);

		for(int i = 0; i < heap_size; i++) {
			heap->set(i, heap_size - i);
		}

		build_min_heap(heap);

		for(int j = 1; j < 10; j++) {
			cout << heap->get(j) << ", ";
		}

		if(!expect(heap->get(0), 0, equals)) {
			return FAIL;
		}

		return PASS;
	});
	*/

  cout << "__done testing __" << endl;

  return 0;
}
