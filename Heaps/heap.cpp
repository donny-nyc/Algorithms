#include "heap.hpp"

Heap::Heap(int i) {
	elements = new int[i];
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
	if (i <= 2) {
		return 0;
	}

	return (i - 1) >> 1;
}

/*
 * Left returns the child at
 * index (2*parent_idx) + 1
 */
int Heap::left(int i) {
	if (i < 0) {
		return 0;
	}

	return (2 * 1) + 1;
}
