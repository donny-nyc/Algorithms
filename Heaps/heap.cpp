#include "heap.hpp"
#include <iostream>

using namespace std;

Heap::Heap(int i) {
  elements = new int[i];
  max = i;
	size = 0;
}

/*
 * Parent returns the index of the
 * node that the given index is a
 * child of.
 *
 * Given the underlying array structure,
 * we can bit-shift to compute the index
 */
int Heap::parent(int i) {
  if (i <= 0) {
    return -1;
  }

  if (i <= 2) {
    return 0;
  }

  if (i >= max) {
    return -1;
  }

  return (i - 1) >> 1;
}

/*
 * Left returns the child at
 * index (2*parent_idx) + 1
 */
int Heap::left(int i) {
  if (i < 0) {
    return -1;
  }

  if (i >= max) {
    return -1;
  }

  return (2 * i) + 1;
}

/*
 * Right returns the child
 * at index 2 * ( i + 1 )
 */
int Heap::right(int i) {
  if (i < 0) {
    return -1;
  }

  if (i >= max) {
    return -1;
  }

  return 2 * (i + 1);
}

/*
 * When given an index falling within
 * the bounds of the underlying array,
 * get() returns the element stored at
 * that location
 */
int Heap::get(int i) {
  if (i < 0) {
    return -1;
  }

  if (i >= max) {
    return -1;
  }

  return elements[i];
}

/*
 * Does what it says on the label
 */
int Heap::getMax() { return max; }

int Heap::set(int i, int value) {
  if (i >= max) {
    return -1;
  }

  if (i < 0) {
    return -1;
  }

  elements[i] = value;

	size++;

  return 0;
}

void max_heapify(Heap *heap, int idx) {
  int left = heap->left(idx);
  int right = heap->right(idx);

  int largest;
  if (left < heap->getSize() && heap->get(left) > heap->get(idx)) {
    largest = left;
  } else {
    largest = idx;
  }

  if (right < heap->getSize() && heap->get(right) > heap->get(largest)) {
    largest = right;
  }

  if (largest != idx) {
    int tmp = heap->get(idx);
    heap->set(idx, heap->get(largest));
    heap->set(largest, tmp);

    max_heapify(heap, largest);
  }
}

void min_heapify(Heap *heap, int idx) {
  int left = heap->left(idx);
  int right = heap->right(idx);

  int smallest;
  if (left < heap->getSize() && heap->get(left) < heap->get(idx)) {
    smallest = left;
  } else {
    smallest = idx;
  }

  if (right < heap->getSize() && heap->get(right) < heap->get(smallest)) {
    smallest = right;
  }

  if (smallest != idx) {
    int tmp = heap->get(idx);
    heap->set(idx, heap->get(smallest));
    heap->set(smallest, tmp);

    min_heapify(heap, smallest);
  }
}

void build_max_heap(Heap *heap) {
  for (int i = heap->getMax() / 2; i >= 0; i--) {
    max_heapify(heap, i);
  }
}

void build_min_heap(Heap *heap) {
	for (int i = heap->getMax() / 2; i >= 0; i--) {
		min_heapify(heap, i);
	}
}

int Heap::getSize() {
	return size;
}

void Heap::decrementSize() {
	size--;
}

int* heapsort(Heap *heap) {
	int* results = new int(heap->getSize());

	build_max_heap(heap);

	for(int i = heap->getSize(); i > 0; i--) {
		results[i] = heap->get(0);
		int tmp = heap->get(i);
		heap->set(i, heap->get(0));
		heap->set(0, tmp);
		heap->decrementSize();
		max_heapify(heap, 1);
	}

	return results;
}
