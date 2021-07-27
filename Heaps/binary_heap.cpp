#include <iostream>
#include "testing.hpp"
#include "heap.hpp"

using namespace std;

/*
 * Starting from a heap as an entrypoint, I want access to the root
 * node. From there, I can traverse down to the leaf-nodes to
 * search, insert, remove
 */

class HeapNode {
	private:
		int value;
		HeapNode *parentNode;
		HeapNode *leftNode;
		HeapNode *rightNode;
	public:
		int index;
		HeapNode(int v) { value = v; }
		HeapNode() { value = 0; }
		void setValue(int v) { value = v; }
		int getValue() { return value; }
		HeapNode *parent();
		HeapNode *left();
		HeapNode *right();
};

/*
 * The BinaryHeap should probably start with a known maximum size
 * (the depth along a simple tree that only branches off to the right
 * [1] o
 *  		\
 * [3]   o
 *        \
 * [7]     o
 *          .
 *           .
 *            .
 *             \
 * [n]          o
 */

class BinaryHeap {
	private:
//		int max_elem; // not exactly the most we could have, just the bounds of
									// the supporting array. We could have a simple tree with
									// fewer than `max_elem` nodes, that simply branches to the
									// right (see above)
									// So really, it's (2^n - 1) where n is the depth
									//
									// We could take the depth instead (knowing that it's a
									// binary tree) and do something like
									//
									// private:
									// 	int max_depth;
									// public:
									//  int max_elem() { return 2^max_depth - 1; }
									//  BinaryHeap(int d) { elems = new HeapNode[max_elems()]; }
		int maxDepth;
		int count;
		HeapNode *elems;
	public:
//		BinaryHeap(int max); // see above
		BinaryHeap(int depth);
		int maxElems();
		int size() { return count; }
		HeapNode *root();
};

int BinaryHeap::maxElems() {
	return (2^maxDepth) - 1;
}

BinaryHeap::BinaryHeap(int depth) {
	maxDepth = depth;

	elems = new HeapNode[maxElems()];	
	for(int i = 0; i < maxElems(); i++) {
		elems[i].index = i;	
	}
}

HeapNode* BinaryHeap::root() {
	return elems;
}

/*
HeapNode* HeapNode::parent() {
	int next = index >> 1;
	if (next > maxElems()) {
		return NULL;
	}

	if (next < 0) {
		return NULL;
	}

	return elems + next;
}

HeapNode* HeapNode::left(int i) {
	int next = 2 * i;
	if (next > maxElems()) {
		return NULL;
	}

	if (next < 0) {
		return NULL;
	}

	return elems + next;
}

HeapNode* BinaryHeap::right(int i) {
	int next = (2 * 1) + 1;
	if (next > maxElems()) {
		return NULL;
	}

	if (next < 0) {
		return NULL;
	}

	return elems + next;
}
*/

// something less over-engineered

int heap[100];

int parent(int i) {
	if (i <= 2) {
		return 0;
	}

	return (i- 1) >> 1;
}

int main() {
	test();
//	int max = 4;
//	cout << "Welcome" << endl;
//
//	BinaryHeap heap = BinaryHeap(max);
//	HeapNode *current = heap.root();
//
//	current->setValue(5);


}
