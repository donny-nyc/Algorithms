#include <iostream>

using namespace std;

class HeapNode {
	private:
		int value;
	public:
		int index;
		HeapNode(int v) { value = v; }
		HeapNode() { value = 0; }
		void setValue(int v) { value = v; }
		int getValue() { return value; }
};

class BinaryHeap {
	private:
		int max_elem;
		int count;
		HeapNode *elems;
	public:
		BinaryHeap(int max);
		int size() { return count; }
		HeapNode *root();
		HeapNode *parent(int i);
		HeapNode *left(int i);
		HeapNode *right(int i);
};

BinaryHeap::BinaryHeap(int max) {
	elems = new HeapNode[max];	
	for(int i = 0; i < max; i++) {
		elems[i].index = i;	
	}

	max_elem = max;
}

HeapNode* BinaryHeap::root() {
	return elems;
}

HeapNode* BinaryHeap::parent(int i) {
	int next = i >> 1;
	if (next > max_elem) {
		return NULL;
	}

	if (next < 0) {
		return NULL;
	}

	return elems + next;
}

HeapNode* BinaryHeap::left(int i) {
	int next = 2 * i;
	if (next > max_elem) {
		return NULL;
	}

	if (next < 0) {
		return NULL;
	}

	return elems + next;
}

HeapNode* BinaryHeap::right(int i) {
	int next = (2 * 1) + 1;
	if (next > max_elem) {
		return NULL;
	}

	if (next < 0) {
		return NULL;
	}

	return elems + next;
}

int main() {
	int val = 0;
	int max = 10;
	int count = 1;

	cout << "Welcome" << endl;

	BinaryHeap heap = BinaryHeap(max);
	HeapNode *current = heap.root();
}
